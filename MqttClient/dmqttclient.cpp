#include "dmqttclient.h"
#include "mqtt.h"
#include <QtCore>
#include <QFileSystemWatcher>
#include <QFile>
#include <QDebug>

DMqttClient *gMqttClient;

void clientReadMqtt(void *ptopic, int topiclen, void *pbuf, int len)
{
    gMqttClient->readMqtt(ptopic, topiclen, pbuf, len);
}

DMqttClient::DMqttClient(QObject *parent) :
    QObject(parent)
{

}

void DMqttClient::startMqttWork()
{
    QtConcurrent::run(cloud_mqtt_thread);

    if(isDirExist("/opt/mqttTempFile"))
    {
        QStringList fileList;
        fileList << "/opt/mqttTempFile/publishFile.txt";
        m_pFileWatcher = new QFileSystemWatcher(fileList, this);
        connect(m_pFileWatcher, SIGNAL(fileChanged (const QString &)),
                this, SLOT(on_fileWatcher_fileChanged(const QString &)));
    }
}

void DMqttClient::readMqtt(void *ptopic, int topiclen, void *pbuf, int len)
{
    qDebug() << QString("topic: %1, topicLen: %2").arg((char*)ptopic).arg(topiclen);
    qDebug() << QString("Message: %1, len: %2").arg((char*)pbuf).arg(len);

    QByteArray array((char*)pbuf, len);
    QFile file("/opt/mqttTempFile/subscribeFile.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "MqttClient: " << "Open subscribeFile file failed";
        return;
    }

    QTextStream out(&file);
    out << array;
    file.close();
}

//检测到文件内容被修改则发布文件内容
void DMqttClient::on_fileWatcher_fileChanged(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "MqttClient: " <<"Open publish file failed";
        return;
    }

    QByteArray array = file.readAll();
    int len = array.size();
    if(0 == len)
    {
        return;
    }
    char* buff = array.data();
    mqtt_data_write(buff, len, 0);
}

bool DMqttClient::isDirExist(QString fullPath)
{
    QDir dir(fullPath);
    if(dir.exists())
    {
        return true;
    }
    else
    {
        bool ok = dir.mkdir(fullPath);//只创建一级子目录，即必须保证上级目录存在
        return ok;
    }
}
