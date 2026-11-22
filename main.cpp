#include <QGuiApplication>
#include <QtQml/qqmlapplicationengine.h>

#include "calc.h"
#include "element.h"
#include "operation.h"
#include "parser.h"

#include <QtQml/qqmlcontext.h>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
   calc Calculator;
    QQmlApplicationEngine engine;
    Element TestElement;
   Operation Operate;
   Parser parsing;

 QObject::connect(
        &engine,
      &QQmlApplicationEngine::objectCreationFailed,
        &app,
       []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

engine.rootContext()->setContextProperty("Calculator", &Calculator);
engine.rootContext()->setContextProperty("TElement", &TestElement);
engine.rootContext()->setContextProperty("Help", &Operate);
engine.rootContext()->setContextProperty("Par", &parsing);


   engine.loadFromModule("HW5", "Main");
  
//app.loadFromModule("HW5", "Main");
    return app.exec();
}
