#include <QObject>
#include <QNetworkAccessManager>


class RequestManager: public QObject {
Q_OBJECT
public: 
    explicit RequestManager(const QString &host, const QString &port, const QString &version, QObject *parent = 0);
    void post(const QString &json, const QString &resource_path);
    void get(const QString &resource_path);

public Q_SLOTS:
 void slotReadyRead();

private:
    QNetworkAccessManager *p_manager;
    QString m_host;
    QString m_port;
    QString m_version;
    QString m_docker_address;
};
