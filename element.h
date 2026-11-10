#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class Element{
    public:
    virtual ~Element();
      Element();
      Element(const Element& previousElement);
    Element(int newInt);
    Element(double newDouble);
    Element(const string& newVal);
    virtual double Value() const; 
    virtual double DoubleValue() const;
virtual int IntValue() const;
void Value(double newVal);
void ChangeType();
  void ChangeString();
    virtual Element* Clone() const;
virtual bool IsDouble() const;
  friend Element operator+(const Element& first, const Element& second);
  friend Element operator-(const Element& first, const Element& second);
  friend Element operator*(const Element& first, const Element& second);
  friend Element operator/(const Element& first, const Element& second);
 friend Element operator%(const Element& first, const Element& second);
  friend ostream &operator<<(ostream &lhs, const Element &first);
    string getString();
private:
    string asString = "";
 double numValue = 0.0;
    bool isDouble;
};
#endif