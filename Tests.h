#ifndef TESTS_H_INCLUDED

#define TESTS_H_INCLUDED
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <fstream>
using namespace std;
class Tests{
    public:
    void RunTests();
    int CheckInt(string check);
    int CheckDouble(string check);
    int ValidOp(string check);
    int BothInts(int first, string op, int second);
    double FirstDouble(double first, string op, int second);
    double SecondDouble(int first, string op, double second);
    double BothDoubles(double first, string op, double second);
    int CreateIntElement(int value);
    double CreateDoubleElement(double value);
    int IntStringElement(string value);
    double DoubleStringElement(string value);
    double ChangeValue(string firstValue, double secondValue);
    bool TestIsDouble(string value);
    bool TestChangeType(string value);
    int TestIntValue(double value);
    double TestDoubleValue(double value);
    Element TestElementAddition(string firstNum, string secondNum);
    Element TestElementSubtraction(string firstNum, string secondNum);
    Element TestElementMultiplication(string firstNum, string secondNum);
    Element TestElementDivision(string firstNum, string secondNum);
    Element TestElementModulo(string firstNum, string secondNum);
    };
#endif