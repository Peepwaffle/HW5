#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "calc.h"
#include "element.h"
#include "operation.h"
#include <QtQml>
#include <QQmlContext>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
   calc Calculator;
    QQmlApplicationEngine engine;
    Element TestElement;
   Operation temp;

 QObject::connect(
        &engine,
       &QQmlApplicationEngine::objectCreationFailed,
        &app,
       []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

engine.rootContext()->setContextProperty("Calculator", &Calculator);
engine.rootContext()->setContextProperty("TElement", &TestElement);
engine.rootContext()->setContextProperty("Help", &temp);


    engine.loadFromModule("HW5", "Main");
  

    return app.exec();
}
