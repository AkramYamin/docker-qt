#include "../../include/restclient/requestmanage.h"
#include <QNetworkReply>
#include <QDebug>
#include <iostream>
using namespace std;

RequestManager::RequestManager(const QString &host, const QString &port, const QString &version, QObject *parent):
QObject(parent),
m_host(host),
m_port(port),
m_version(version),
p_manager(nullptr)
 {
    m_docker_address = "http://";
    m_docker_address.append(m_host);
    m_docker_address.append(":");
    m_docker_address.append(m_port);
    m_docker_address.append("/");
    m_docker_address.append(m_version);

    p_manager = new QNetworkAccessManager(this);
}

void RequestManager::get(const QString &resource_path) {
    QString endpoint_url = m_docker_address + resource_path;
    QNetworkRequest request;
    request.setUrl(QUrl(endpoint_url));
    QNetworkReply *reply = p_manager->get(request);

    connect(reply, &QIODevice::readyRead, this, &RequestManager::slotReadyRead);
}

void RequestManager::post(const QString &json, const QString &resource_path) {

}



void RequestManager::slotReadyRead() {
    QNetworkReply *rep =  static_cast<QNetworkReply*>(QObject::sender());
    QByteArray res = rep->readAll();
    QString s(res);
    cout << s.toStdString() << endl;
}
