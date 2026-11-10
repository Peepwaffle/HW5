#include <iostream>
#include <string>
#include "element.h"
#include <sstream>
#include "exceptions.h"
#include <vector>
#include "operation.h"


using namespace std;


ostream& operator<<(ostream& lhs, const Operation& operate){
    lhs << "("<<operate.FirstElement->Value()<<" "<< operate.Op << " "<< operate.SecondElement->Value()<< ")";
   return lhs;
}
  Operation::Operation(const Operation& other): Element(){
    FirstElement = other.FirstElement;
    Op = other.Op;  
    SecondElement = other.SecondElement;  
    origFirstString = other.origFirstString;
    origSecondString = other.origSecondString; 
  }

Operation::Operation(){
}


Operation::~Operation(){
}
Operation* Operation::Clone() const{
    Operation* NewOperation =  new Operation(*this);
    return NewOperation;
}

char Operation::GetOp(){
    return Op;
}
bool Operation::ValidOp(char op){
    if(op == '+'){
        return true;
    }
     if(op == '-'){
        return true;
    }
     if(op == '*'){
        return true;
    }
     if(op == '/'){
        return true;
    }
    if(op == '*'){
        return true;
    }
    if(op == '%'){
        return true;
    }
    return false;
}
Operation& Operation::operator= (Operation other) {
    if(this != &other){
        FirstElement = other.FirstElement;
        Op = other.Op;
        SecondElement = other.SecondElement;
    }
    return *this;  
}
 Operation::Operation(const Element& leftElem, char op, const Element& rightElem): Element(){

    if(ValidOp(op)== false){
    throw InvalidOperator("Successfully caught InvalidOperator");
    }
    else{  
    FirstElement = leftElem.Clone(); 
    origFirstString = FirstElement->getString();     
    Op = op;  
    SecondElement = rightElem.Clone(); 
    origSecondString = SecondElement->getString(); 
    }
}
double Operation::RunCalc() const{
      const double left = FirstElement->Value();
    const double right = SecondElement->Value();  
  if(Op == '+'){
    Element result(left + right);
    return result.DoubleValue();
 }
  else if(Op == '-'){
       Element result(left - right);
    return result.DoubleValue();
 }
  else if(Op == '*'){
       Element result(left * right);
    return result.DoubleValue();
 }
  else if(Op == '/'){
        Element result(left / right);
    return result.DoubleValue();
 }
 return 0.0;
}
int Operation::IntCalc() const{
     if(Op == '+'){
    Element result(FirstElement->IntValue()+ SecondElement->IntValue());
    return result.IntValue();
 }
  else if(Op == '-'){
       Element result(FirstElement->IntValue()- SecondElement->IntValue());
    return result.IntValue();
 }
  else if(Op == '*'){
       Element result(FirstElement->IntValue() * SecondElement->IntValue());
    return result.IntValue();
 }
  else if(Op == '/'){
        Element result(FirstElement->IntValue()/ SecondElement->IntValue());
    return result.IntValue();
 }
 else if(Op == '%'){

       Element result(FirstElement->IntValue()% SecondElement->IntValue());
     
    return result.IntValue();
 }
 return 0.0;
}
double Operation::DoubleValue() const{
    return RunCalc();
}
int Operation::IntValue() const{
    return IntCalc();
}
double Operation::Value() const{
    if(SecondElement->Value()== 0.0 && Op == '/'){
        throw DivideByZeroError("Successfully caught division by 0");
    }
    
    if(SecondElement->IsDouble()== true && Op == '%'){
           throw ModuloByDoubleError("Successfully caught modulo by 0");
    }
    if(IsDouble()== true && Op == '%'){
    return IntValue();
    }
   else if(IsDouble()== true){      
    return DoubleValue();
    }
    else{     
        return IntValue();
    }
}
Operation::Operation(const string& element){
    vector<string> tokens;
    stringstream AsStream(element);
    string token;
    
    while(getline(AsStream, token, ' ')){
        tokens.push_back(token);
    } 
    if(tokens.size() != 3){
      throw InvalidElement("Successfully caught InvalidElement");
       }
          string first =tokens[0];
          origFirstString = first;
    string op = tokens[1];
    string second = tokens[2];
    origSecondString = second;
     try{
        Element firsttemp = Element(first);
        FirstElement = firsttemp.Clone();
    }
    catch(InvalidElement& e){
        throw InvalidElement("Successfully caught InvalidElement");
    }
    char opAsChar = op[0];
      if(ValidOp(opAsChar)!= true){
        throw InvalidOperator("Successfully caught InvalidOperator");
    }
    else{
        Op = opAsChar;
    }
    try{
        Element secondtemp = Element(second);
        SecondElement = secondtemp.Clone();
    }
    catch(InvalidElement& e){
        throw InvalidElement("Successfully caught InvalidElement");
    }       
}
 bool Operation::IsDouble() const {   
    return origFirstString.find('.') != std::string::npos || origSecondString.find('.') != std::string::npos ||FirstElement->IsDouble() ||
    SecondElement->IsDouble();

}