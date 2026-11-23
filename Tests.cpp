#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "calc.h"
#include "element.h"
#include "operation.h"
#include "parser.h"
using namespace std;
Tests::Tests(){
}
int Tests::CheckInt(string check){
    calc calculator;
    results+= "Testing to see if calculator can correctly recognize " + check +" as an integer.";
    results += "\n";
    return  calculator.FirstCheckInt(QString::fromStdString(check));
}
int Tests::CheckDouble(string check){
    calc calculator;
     results+= "Testing to see if calculator can correctly recognize " + check +" as a double.";
    results += "\n";
    return calculator.FirstCheckDouble(QString::fromStdString(check));
}
int Tests::ValidOp(string check){
    calc calculator;
    results+= "Testing to see if calculator can correctly recognize " + check +" as a valid op or not.";
    results += "\n";
    return calculator.CheckValidOp(QString::fromStdString(check));
}
int Tests::BothInts(int first, string op, int second){
    calc calculator;
             results+= "Testing to see if calculator can correctly perform the equation " + to_string(first) +" "+ op + " " +to_string(second) +".";
    results += "\n";
    calculator.SetFirstNum(first);
    calculator.SetSecondNum(second);
    return calculator.CalculateInts(QString::fromStdString(op));
}
double Tests::FirstDouble(double first, string op, int second){
    calc calculator;
            results+= "Testing to see if calculator can correctly perform the equation " + to_string(first) +" "+ op + " " +to_string(second) +".";
    results += "\n";
    calculator.SetFirstNum(first);
    calculator.SetSecondNum(second);
    return calculator.CalcFirstDouble(QString::fromStdString(op));
}
double Tests::SecondDouble(int first, string op, double second){
    calc calculator;
          results+= "Testing to see if calculator can correctly perform the equation " + to_string(first) +" "+ op + " " +to_string(second) +".";
    results += "\n";
    calculator.SetFirstNum(first);
    calculator.SetSecondNum(second);
    return calculator.CalcSecondDouble(QString::fromStdString(op));
}
double Tests::BothDoubles(double first, string op, double second){
    calc calculator;
      results+= "Testing to see if calculator can correctly perform the equation " + to_string(first) +" "+ op + " " +to_string(second) +".";
    results += "\n";
    calculator.SetFirstNum(first);
    calculator.SetSecondNum(second);
    return calculator.CalcBothDoubles(QString::fromStdString(op));
}
int Tests::CreateIntElement(int value){
      results+= "Testing to see if an element can be created using an integer with the value of " + to_string(value) +".";
    results += "\n";
    Element testElement(value);
    return testElement.Value();
}
double Tests::CreateDoubleElement(double value){
        results+= "Testing to see if an element can be created using a double with the value of " + to_string(value) +".";
         results += "\n";
        Element testElement(value);
    return testElement.Value();
}
int Tests::IntStringElement(string value){
        results+= "Testing to see if an element can be created using a string with the value of " + value +".";
      results += "\n";
     Element testElement(value);
    return testElement.Value();
}
double Tests::DoubleStringElement(string value){
    results+= "Testing to see if an element can be created using a string with the value of " + value +".";
      results += "\n";
      Element testElement(value);
    return testElement.Value();
}
double Tests::ChangeValue(string firstValue, double secondValue){
      results+= "Testing to see if an element that was created with the value of " + firstValue + " can have its value changed to "+ to_string(secondValue) + ".";
      results += "\n";
    Element testElement(firstValue);
    testElement.Value(secondValue);
    return testElement.Value();
}
bool Tests::TestIsDouble(string value){
      results+= "Testing to see if an element that was created with the value of " + value +" is recognized as a double or as an int.";
      results += "\n";
     Element testElement(value);
     return testElement.IsDouble();
}
bool Tests::TestChangeType(string value){
    results+= "Testing to see if an element that was created with the value of " + value +" can have its type correctly changed.";
      results += "\n";
     Element testElement(value);
     testElement.ChangeType();
      return testElement.IsDouble();
}
int Tests::TestIntValue(double value){
     results+= "Testing to see if an element that was created with the value of " + to_string(value) +" can have the correct value returned for its integer value.";
      results += "\n";
      Element testElement(value);
    return testElement.IntValue();
}
double Tests::TestDoubleValue(double value){
       results+= "Testing to see if an element that was created with the value of " + to_string(value) +" can have the correct value returned for its double value.";
      results += "\n";
      Element testElement(value);
    return testElement.DoubleValue();
}
Element Tests::TestElementAddition(string firstNum, string secondNum){
     results+= "Testing to see if an element with the value of "+ firstNum+ " and an element with the value of " + secondNum +" can be correctly added together.";
      results += "\n";
    Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.Value()+SecondElement.Value());
}
Element Tests::TestElementSubtraction(string firstNum, string secondNum){
     results+= "Testing to see if an element with the value of "+ firstNum+ " can correctly subtract an element with the value of " + secondNum +" from it.";
      results += "\n";
    Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.Value()-SecondElement.Value());
}
Element Tests::TestElementMultiplication(string firstNum, string secondNum){
         results+= "Testing to see if an element with the value of "+ firstNum+ " can be correctly multiplied by an element with the value of " + secondNum +".";
      results += "\n";
    Element FirstElement(firstNum);
   
    Element SecondElement(secondNum);
    return Element(FirstElement.Value()*SecondElement.Value());

} 
Element Tests::TestElementDivision(string firstNum, string secondNum){
      results+= "Testing to see if an element with the value of "+ firstNum+ " can correctly be divided by an element with the value of " + secondNum +".";
      results += "\n";
     Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.Value()/SecondElement.Value());

} 
Element Tests::TestElementModulo(string firstNum, string secondNum){
     results+= "Testing to see if an element with the value of "+ firstNum+ " can have the correct remainder from an element with the value of " + secondNum +".";
      results += "\n";
     Element FirstElement(firstNum);
    Element SecondElement(secondNum);
    return Element(FirstElement.IntValue()%SecondElement.IntValue());
} 
Operation* Tests::TestStringOperation(string testString){
     results+= "Testing to see if the operation "+ testString + " can be correctly performed";
      results += "\n";
    return new Operation(testString);
}
Operation* Tests::TestElementOperation( Element leftElem, char op,  Element rightElem){
     results+= "Testing to see if the operation "+ to_string(leftElem.Value())+ " "+ op +" "+ to_string(rightElem.Value()) + " can be correctly performed";
      results += "\n";
    return new Operation(leftElem, op, rightElem);
}
Element* Tests::TestParseString(string ParseOp){
    results+= "Testing to see if the equation "+ ParseOp +" is correctly peformed by the parse class.";
    results += "\n";
    Parser par;
    return par.Parse(ParseOp);
}

QString Tests::RunTests(){
    cout << "Testing started" << endl;
   
 if(CheckInt("4") == 0){
      results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
      return QString::fromStdString(results);
 }
 if(CheckInt("e") == 1){
      results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
     return QString::fromStdString(results);
 }
 if(CheckDouble("3.5") == 0){
      results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
     return QString::fromStdString(results);
 }
 if(CheckDouble("Hut.") == 1){
      results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
     return QString::fromStdString(results);
 }
  if(ValidOp("/") == 0){
      results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
      return QString::fromStdString(results);
 }
  if(ValidOp("!") == 4){
      results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
      return QString::fromStdString(results);
 }
 if(BothInts(3, "+", 7)== 10){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
       return QString::fromStdString(results);
 }
 if(BothInts(45, "-", 13)== 32){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
      return QString::fromStdString(results);
 }
   
   if(BothInts(8, "*", 8)== 64){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
      return QString::fromStdString(results);
 }
 if(BothInts(100, "/", 20)== 5){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
       return QString::fromStdString(results);
 }
  if(BothInts(64, "%", 7)== 1){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
      return QString::fromStdString(results);
 }
 if(FirstDouble(3.5, "+", 7) == 10.5){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
  if(FirstDouble(56.42, "-", 32) == 24.42){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(FirstDouble(43.24, "*", 7) == 302.68){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(FirstDouble(564.3, "/", 3) == 188.1){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(SecondDouble(46, "+", 35.4) == 81.4){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(SecondDouble(75, "-", 28.35) == 46.65){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(SecondDouble(23, "*", 4.5) == 103.5){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(SecondDouble(105, "/", 10.5) == 10.00){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(BothDoubles(34.5, "+", 79.1)== 113.6){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(BothDoubles(1463.37, "-", 111.11)== 1352.26){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(BothDoubles(7.5, "*", 45.3)== 339.75){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(BothDoubles(339.75, "/", 4.53)== 75){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(CreateIntElement(4)== 4){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(CreateDoubleElement(323.4)==323.4){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(IntStringElement("500")== 500){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(DoubleStringElement("43.1")== 43.1){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(ChangeValue("345.3", 1832.7)== 1832.7){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestIsDouble("34")== false){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
if(TestIsDouble("5734.2")== true){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestChangeType("400")== true){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestChangeType("43.56")== false){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
  if(TestIntValue(465.34)== 465){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
   if(TestIntValue(43)== 43){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestDoubleValue(4332849.1)== 4332849.1){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestDoubleValue(43)== 43.00){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestElementAddition("3", "1987.8").Value()== 1990.8){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestElementSubtraction("104", "33").Value()== 71){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestElementMultiplication("7", "36.423").Value()== 254.961){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
  if(TestElementDivision("254.961", "14").Value()== 18.2115){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
   if(TestElementModulo("1000", "35").Value()== 20){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
  if(TestStringOperation("400 + 104")->Value()== 504){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
   if(TestStringOperation("5.03 - 80.48")->Value()== -75.45){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
    if(TestStringOperation("35 * 102")->Value()== 3570){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
if(TestStringOperation("300 / 80")->Value()== 3.75){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 if(TestStringOperation("500 % 80")->Value()== 20){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
    Element first(400);
    Element second(3.06);
    if(TestElementOperation(first, '+', second)->Value() ==403.06){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
first.Value(92);
second.Value(81);
    if(TestElementOperation(first, '-', second)->Value() ==11){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
 first.Value(37);
second.Value(4.3);
  if(TestElementOperation(first, '*', second)->Value() ==159.1){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
first.Value(94);
second.Value(8);
if(TestElementOperation(first, '/', second)->Value() ==11.75){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }
    Element secondTolast(53234);
    Element last(4623);
if(TestElementOperation(secondTolast, '%', last)->Value() ==2381){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }   
 if(TestParseString("400 * ( 300 + 2 )")->Value()== 120800){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }  
  if(TestParseString("45 - 20 + 3")->Value()== 28){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }  
   if(TestParseString("45 - ( 20 + 3 )")->Value()== 22){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }  
 if(TestParseString("53.78 - ( 579 / 3 )")->Value()== -139.22){
     results+= "Result: Test passed \n";
 }
 else{
      results+= "Result: Test failed \n";
        return QString::fromStdString(results);
 }  
   
   cout << results << endl;
    cout << "Testing completed" << endl;
     return QString::fromStdString(results);
}