#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "calc.h"
#include "element.h"
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
int Tests::CheckInt(string check){
    calc calculator;
    return  calculator.FirstCheckInt(check);
}
int Tests::CheckDouble(string check){
    calc calculator;
    return calculator.FirstCheckDouble(check);
}
int Tests::ValidOp(string check){
    calc calculator;
    return calculator.CheckValidOp(check);
}
int Tests::BothInts(int first, string op, int second){
    calc calculator;
    calculator.SetFirstNum(first);
    calculator.SetSecondNum(second);
    return calculator.CalculateInts(op);
}
double Tests::FirstDouble(double first, string op, int second){
    calc calculator;
    calculator.SetFirstNum(first);
    calculator.SetSecondNum(second);
    return calculator.CalcFirstDouble(op);
}
double Tests::SecondDouble(int first, string op, double second){
    calc calculator;
    calculator.SetFirstNum(first);
    calculator.SetSecondNum(second);
    return calculator.CalcSecondDouble(op);
}
double Tests::BothDoubles(double first, string op, double second){
    calc calculator;
    calculator.SetFirstNum(first);
    calculator.SetSecondNum(second);
    return calculator.CalcBothDoubles(op);
}
int Tests::CreateIntElement(int value){
    Element testElement(value);
    return testElement.Value();
}
double Tests::CreateDoubleElement(double value){
      Element testElement(value);
    return testElement.Value();
}
int Tests::IntStringElement(string value){
     Element testElement(value);
    return testElement.Value();
}
double Tests::DoubleStringElement(string value){
      Element testElement(value);
    return testElement.Value();
}
double Tests::ChangeValue(string firstValue, double secondValue){
    Element testElement(firstValue);
    testElement.Value(secondValue);
    return testElement.Value();
}
bool Tests::TestIsDouble(string value){
     Element testElement(value);
     return testElement.IsDouble();
}
bool Tests::TestChangeType(string value){
     Element testElement(value);
     testElement.ChangeType();
      return testElement.IsDouble();
}
int Tests::TestIntValue(double value){
      Element testElement(value);
    return testElement.IntValue();
}
double Tests::TestDoubleValue(double value){
      Element testElement(value);
    return testElement.DoubleValue();
}
Element Tests::TestElementAddition(string firstNum, string secondNum){
    Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.Value()+SecondElement.Value());
}
Element Tests::TestElementSubtraction(string firstNum, string secondNum){
    Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.Value()-SecondElement.Value());
}
Element Tests::TestElementMultiplication(string firstNum, string secondNum){
     Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.Value()*SecondElement.Value());

} 
Element Tests::TestElementDivision(string firstNum, string secondNum){
     Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.Value()/SecondElement.Value());

} 
Element Tests::TestElementModulo(string firstNum, string secondNum){
     Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.IntValue()%SecondElement.IntValue());

} 
void Tests::RunTests(){
    cout << "Testing started" << endl;
    assert(CheckInt("4") == 0);
    assert(CheckInt("e") == 1);
    assert(CheckDouble("3.5") == 0);
    assert(CheckDouble("Hut.") == 1);
    assert(ValidOp("/")== 0);
    assert(ValidOp("!")== 4);
    assert(BothInts(3, "+", 7)== 10);
    assert(BothInts(45, "-", 13)== 32);
    assert(BothInts(8, "*", 8)== 64);
    assert(BothInts(100, "/", 20)== 5);
    assert(BothInts(64, "%", 7)== 1);
    assert(FirstDouble(3.5, "+", 7) == 10.5);
    assert(FirstDouble(56.42, "-", 32) == 24.42);
    assert(FirstDouble(43.24, "*", 7) == 302.68);
    assert(FirstDouble(564.3, "/", 3) == 188.1);
    assert(SecondDouble(46, "+", 35.4) == 81.4);
    assert(SecondDouble(75, "-", 28.35) == 46.65);
    assert(SecondDouble(23, "*", 4.5) == 103.5);
    assert(SecondDouble(105, "/", 10.5) == 10.00);
    assert(BothDoubles(34.5, "+", 79.1)== 113.6);
    assert(BothDoubles(1463.37, "-", 111.11)== 1352.26);
    assert(BothDoubles(7.5, "*", 45.3)== 339.75);
    assert(BothDoubles(339.75, "/", 4.53)== 75);
    assert(CreateIntElement(4)== 4);
    assert(CreateDoubleElement(323.4)==323.4);
    assert(IntStringElement("500")== 500);
    assert(DoubleStringElement("43.1")== 43.1);
    assert(ChangeValue("345.3", 1832.7)== 1832.7);
    assert(TestIsDouble("34")== false);
    assert(TestIsDouble("5734.2")== true);
    assert(TestChangeType("400")== true);
    assert(TestChangeType("43.56")== false);
    assert(TestIntValue(465.34)== 465);
    assert(TestIntValue(43)== 43);
    assert(TestDoubleValue(4332849.1)== 4332849.1);
    assert(TestDoubleValue(43)== 43.00);
    assert(TestElementAddition("3", "1987.8").Value()== 1990.8);
    assert(TestElementSubtraction("104", "33").Value()== 71);
    assert(TestElementMultiplication("7", "36.423").Value()== 254.961);
    assert(TestElementDivision("254.961", "14").Value()== 18.2115);
    assert(TestElementModulo("1000", "35").Value()== 20);
    cout << "Testing completed" << endl;
}