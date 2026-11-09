#ifndef CALC_H

#define CALC_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;
class calc{
public:
void Reset();
int FirstCheckInt(string firstNumber);
int CheckValidOp(string Checking);
int FirstCheckDouble(string firstNumber);
int ThirdCheckInt(std::string thirdvalue);
int ThirdCheckDouble(std::string thirdvalue);
int LookAtFirstValue(std::string lengthCheck);
int LookAtThirdValue(std::string lengthCheck);
int CalculateInts(std::string Op);
double CalcFirstDouble(std::string op);
double CalcSecondDouble(std::string op);
double CalcBothDoubles(std::string op);
int OpenUpFile(std::string inputFile);
int CheckInput(char* argv[]);
int CheckInput(std::string argv[]);
void WhichError(int ErrorNumber, std::string argv[]);
int CheckValidEquation(string op);
void RunCalculations(std::string whichOp);
void WhichError(int ErrorNumber, char* argv[]);
void WhichError(int ErrorNumber);
int readThroughFile(string inputFile);
void SetFirstNum(int FirstVal);
void SetFirstNum(double FirstVal);
void SetSecondNum(int SecondVal);
void SetSecondNum(double SecondVal);
int CheckLine(string line);
private:
int firstNumAsInt = 0;
double firstNumAsDouble = 0.00;
bool firstIsDouble= false;
bool firstIsInt = false;
int secondNumAsInt = 0;
double secondNumAsDouble = 0.00;
bool secondIsDouble = false;
bool secondIsInt = false;
};
#endif 