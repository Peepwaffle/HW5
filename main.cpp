#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "calc.h"




int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
   
    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("HW5", "Main");
   

    return app.exec();
}
