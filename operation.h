#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
#include <iostream>
#include <string>
#include "element.h"
#include <sstream>
#include "exceptions.h"
#include <vector>
using namespace std;
class Operation : public Element {
      public:
      Operation();
      Operation(const string& element);
      Operation(const Operation& other);
      Operation& operator= (Operation other);
      
      virtual ~Operation(); 
     bool IsDouble() const override;
    Operation(const Element& leftElem, char op, const Element& rightElem);
    bool ValidOp(char op);
 Operation* Clone() const override;
    char GetOp();
    virtual double Value() const override;
    double RunCalc() const;
    int IntCalc() const;
    virtual double DoubleValue() const override;
     int IntValue() const override;
      friend ostream& operator<<(ostream& lhs, const Operation& operate);
    private:
 string origFirstString;
 string origSecondString;
    Element* FirstElement;
    Element* SecondElement;
  
    char Op;
};
#endif