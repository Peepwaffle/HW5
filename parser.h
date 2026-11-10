#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <iostream>
#include <string>
#include "exceptions.h"
#include "element.h"
#include <vector>
#include <stack>
#include "operation.h"
#include <stdexcept>
#include <fstream>
using namespace std;
class Parser{
    public:
    Parser();
    stack<string> ReverseStack(stack<string> OriginalStack);
    Element* Parse(const string& equationStr);
    void SetParseFlag(string toFlag);
    vector<string> GoThroughInput(const string& equationStr);
    bool IsAnOP(string toCheck);
    void Reset();
    Element* CreateNoFlag(vector<string> Tokens, const string& equationStr);
    Element* RunThroughNoParentheses(vector<string> Tokens);
    string WhichOp();
    int OperatorPriority(string OptoCheck);
    Element* PerformNextCalculation(string nextOp, vector<string> Tokens);
    vector<string> Remove(vector<string> Tokens, string nextOp, Element* toReplace);
    stack<string> removeFromStack(string toRemove);
    int numberofInstances(string toRemove);
    vector<string> initialValues;
    void readThroughFile(string fileName);
    Element* GoParentheses(vector<string> Tokens);
    int FindFirstPare(vector<string> Tokens);
    int FindSecondPare(vector<string> Tokens);
    int NumbersInTemp(vector<string> Tokens);
    int OpsInTemp(vector<string> Tokens);
    int HowManyInPare(vector<string> Tokens);
    string ChangeString(vector<string> Tokens);
    bool HasInnerPare(vector<string> checking);
    vector<string> CreateTemp(vector<string> Tokens, unsigned int firstIndex, unsigned int secondIndex);
 

    private:
   string parseFlag;
   stack<Element> NumStack;
   stack<string> Ops;
     int paretheses = 0;
    int operators = 0;
    int numbers = 0;
  
};
#endif