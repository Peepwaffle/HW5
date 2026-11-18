#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
#include <iostream>
#include <string>
#include "element.h"
#include <sstream>
#include "exceptions.h"
#include <vector>
#include <QObject>
#include <QtQmlIntegration/qqmlintegration.h>
using namespace std;
class Operation : public Element {
     Q_OBJECT
  QML_ELEMENT
      public:

     Q_INVOKABLE  Operation();
    Q_INVOKABLE  Operation(const string& element);
     Q_INVOKABLE  Operation(const Operation& other);
     Q_INVOKABLE  Operation& operator= (Operation other);

      Q_INVOKABLE void CreateString(QString input);
    Q_INVOKABLE   virtual ~Operation(); 
   Q_INVOKABLE   bool IsDouble() const override;
  Q_INVOKABLE   Operation(const Element& leftElem, char op, const Element& rightElem);
  Q_INVOKABLE   bool ValidOp(char op);
Q_INVOKABLE  Operation* Clone() const override;
   Q_INVOKABLE  char GetOp();
  Q_INVOKABLE   virtual double Value() const override;
  Q_INVOKABLE   double RunCalc() const;
  Q_INVOKABLE   int IntCalc() const;
  Q_INVOKABLE   virtual double DoubleValue() const override;
  Q_INVOKABLE    int IntValue() const override;
    Q_INVOKABLE   friend ostream& operator<<(ostream& lhs, const Operation& operate);
    private:
   
 string origFirstString;
 string origSecondString;
    Element* FirstElement;
    Element* SecondElement;
  
    char Op;
};
#endif