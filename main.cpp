#include <iostream>
#include <QtCore>
#include "include/restclient/requestmanage.h"
using namespace std;

int main(int args, char *argv[])
{
    QCoreApplication app(args, argv);
    RequestManager *m = new RequestManager("localhost", "2375", "v1.24");
    m->get("/images/json");
    cout << "Hello world " << endl;
    return app.exec();
}