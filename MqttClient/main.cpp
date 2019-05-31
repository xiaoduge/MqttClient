#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include "dmqttclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    
    DMqttClient MqttClient;
    gMqttClient = &MqttClient;
    MqttClient.startMqttWork();

    return a.exec();
}
