#ifndef EXCEPTIONS_H_INCLUDED

#define EXCEPTIONS_H_INCLUDED
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;
class Exceptions: public exception{


};
class InvalidEquationStructure: public invalid_argument{
    public:
      explicit InvalidEquationStructure(const string& message): invalid_argument(message){
 }
 };
class ModuloByDoubleError: public domain_error{
    public:
 explicit ModuloByDoubleError(const string& message): domain_error(message){
 }
};
class DivideByZeroError: public domain_error {
    public:
     explicit DivideByZeroError(const string& message): domain_error(message){
 }
};
class InvalidElement: public invalid_argument{
    public:
     explicit InvalidElement(const string& message): invalid_argument(message){
 }
};
class InvalidOperator: public invalid_argument{
    public:
      explicit InvalidOperator(const string& message): invalid_argument(message){
 }
     private:
    string error_message;
};
#endif