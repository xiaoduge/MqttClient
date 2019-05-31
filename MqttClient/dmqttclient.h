#ifndef DMQTTCLIENT_H
#define DMQTTCLIENT_H

#include <QObject>

class QFileSystemWatcher ;

class DMqttClient : public QObject
{
    Q_OBJECT
public:
    explicit DMqttClient(QObject *parent = 0);

    void startMqttWork();

    void readMqtt(void *pbuf, int len);

private slots:
    void on_fileWatcher_fileChanged(const QString& fileName);

private:
    bool isDirExist(QString fullPath);
    
private:
    QFileSystemWatcher *m_pFileWatcher;
    
};

extern DMqttClient *gMqttClient;

#endif // DMQTTCLIENT_H
