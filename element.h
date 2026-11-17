#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include <iostream>
#include <string>
#include <QObject>
#include <QtQmlIntegration/qqmlintegration.h>
using namespace std;
class Element: public QObject {
    public:
Q_INVOKABLE virtual ~Element();
   Q_INVOKABLE   Element();
 Q_INVOKABLE   Element(const Element& previousElement);
    Q_INVOKABLE Element(int newInt);
    Q_INVOKABLE Element(double newDouble);
   Q_INVOKABLE  Element(const string& newVal);
   Q_INVOKABLE  virtual double Value() const; 
  Q_INVOKABLE   virtual double DoubleValue() const;
 Q_INVOKABLE virtual int IntValue() const;
 Q_INVOKABLE void Value(double newVal);
 Q_INVOKABLE void ChangeType();
   Q_INVOKABLE void ChangeString();
    Q_INVOKABLE virtual Element* Clone() const;
 Q_INVOKABLE virtual bool IsDouble() const;
  Q_INVOKABLE friend Element operator+(const Element& first, const Element& second);
  Q_INVOKABLE friend Element operator-(const Element& first, const Element& second);
  Q_INVOKABLE friend Element operator*(const Element& first, const Element& second);
  Q_INVOKABLE friend Element operator/(const Element& first, const Element& second);
 Q_INVOKABLE friend Element operator%(const Element& first, const Element& second);
  Q_INVOKABLE friend ostream &operator<<(ostream &lhs, const Element &first);
   Q_INVOKABLE  string getString();
private:
    string asString = "";
 double numValue = 0.0;
    bool isDouble;
};
#endif