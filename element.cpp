#include <iostream>
#include <string>
#include "exceptions.h"
#include "element.h"
using namespace std;
 Element::Element(const Element& previousElement){
  asString = previousElement.asString;
   isDouble = previousElement.isDouble;
  numValue = previousElement.numValue;

 }
void Element::ChangeString(){
  if(isDouble == true){
    asString = to_string(IntValue());
  }
  else{
     asString = to_string(DoubleValue());
  }
}
string Element::getString(){
  return asString;
}
Element* Element::Clone() const{
   Element* NewElement =   new Element(*this);
  return NewElement;
}
Element::Element(){
asString = "";
  numValue = 0.0;
  isDouble = false;
}
Element::~Element(){ 
asString = "";
  numValue = 0.0;
  isDouble = false;
}
ostream& operator<<(ostream &lhs, const Element& first){
lhs << first.Value();
return lhs;
}

 Element operator+(const Element& first, const Element& second){
    return Element(second.numValue+first.numValue);
}
Element operator-(const Element& first, const Element& second){  
    return Element(first.numValue - second.numValue);
}
Element operator*(const Element& first, const Element& second){  
    return Element(first.numValue* second.numValue);
}
Element operator/(const Element& first, const Element& second){  
    try{
      if(second.numValue == 0){
        throw domain_error("Error");
      }
      else{
      return Element(first.numValue/second.numValue);
      }    
    }
     catch(const domain_error& e){
      string error_message = "Successfully caught division by 0";
       throw DivideByZeroError(error_message);
        }
 return Element(0);
}
Element operator%(const Element& first, const Element& second){  
     try{
      if(second.numValue == 0){
        throw invalid_argument("Error");
      }
      else if(first.IsDouble()|| second.IsDouble()){
        throw domain_error("Error");
      }
      else{
          return Element(static_cast<int>(first.numValue)%static_cast<int>(second.numValue));
      }
    }
    catch(const invalid_argument&e){
      string error_message = "Successfully caught modulo by 0";
       throw DivideByZeroError(error_message); 
    }
     catch(const domain_error& e){
         string error_message = "Successfully caught modulo by double";
       throw ModuloByDoubleError(error_message);
        }
 return Element(0);   
}
 double Element::Value() const {
    if(isDouble ==  false){
        return static_cast<double>(IntValue());
    }
    else{
        return DoubleValue();
    }
 }
 bool Element::IsDouble() const{
    if(isDouble == true){
    return true;
  }
    return false;
 }
 void Element::ChangeType(){
    if(isDouble== false){
        asString= to_string(static_cast<double>(numValue));
        isDouble = true;   
    }
    else{
        asString= to_string(static_cast<int>(numValue));
        isDouble = false;
    }
 }
 void Element::Value(double newVal){
  asString = to_string(newVal);
    numValue = newVal;
 }
double Element::DoubleValue() const{
    return numValue;
}
int Element::IntValue() const{
    return static_cast<int>(numValue);
}
Element::Element(int newInt){
    asString = to_string(newInt);
    isDouble = false;
    numValue = static_cast<double>(newInt);
}
Element::Element(double newDouble){
    asString = to_string(newDouble);
    isDouble = true;
    numValue = newDouble;
}
Element::Element(const string& newVal){
    if(newVal.find(".")!= string::npos){
        try{
            isDouble = true;
            asString = (newVal);
            numValue = stod(newVal);
          }
          catch(const invalid_argument&){  
            string error_message = "Successfully caught InvalidElement";
           throw InvalidElement(error_message);
          }
    }
    else{
         try{
           isDouble = false;
              asString = newVal;
             numValue = stoi(newVal);
          }
          catch(const invalid_argument&){  
                     string error_message = "Successfully caught InvalidElement";
           throw InvalidElement(error_message);
          }
    }
    
}