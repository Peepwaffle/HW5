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
#include <QObject>
#include <QtQmlIntegration/qqmlintegration.h>
using namespace std;
class Parser: public QObject {
   Q_OBJECT
   QML_ELEMENT
    public:
    Parser();
    Q_INVOKABLE int CanGoParetheses(vector<string> Tokens);
    Q_INVOKABLE int CanGoNoParentheses(vector<string> Tokens);
    Q_INVOKABLE int CanPerformNextCalc(string nextOp, vector<string> Tokens);
    Q_INVOKABLE void SetQMLParseFlag(QString toFlag);
    Q_INVOKABLE stack<string> ReverseStack(stack<string> OriginalStack);
    Q_INVOKABLE Element* Parse(const string& equationStr);
   Q_INVOKABLE  void SetParseFlag(string toFlag);
   Q_INVOKABLE  vector<string> GoThroughInput(const string& equationStr);
    Q_INVOKABLE bool IsAnOP(string toCheck);
  Q_INVOKABLE   void Reset();
   Q_INVOKABLE  Element* CreateNoFlag(vector<string> Tokens, const string& equationStr);
   Q_INVOKABLE  Element* RunThroughNoParentheses(vector<string> Tokens);
  Q_INVOKABLE   string WhichOp();
  Q_INVOKABLE   int OperatorPriority(string OptoCheck);
 Q_INVOKABLE    Element* PerformNextCalculation(string nextOp, vector<string> Tokens);
 Q_INVOKABLE    vector<string> Remove(vector<string> Tokens, string nextOp, Element* toReplace);
 Q_INVOKABLE    stack<string> removeFromStack(string toRemove);
  Q_INVOKABLE   int numberofInstances(string toRemove);
  Q_INVOKABLE  vector<string> initialValues;
  Q_INVOKABLE   void readThroughFile(string fileName);
  Q_INVOKABLE   Element* GoParentheses(vector<string> Tokens);
  Q_INVOKABLE   int FindFirstPare(vector<string> Tokens);
  Q_INVOKABLE   int FindSecondPare(vector<string> Tokens);
  Q_INVOKABLE   int NumbersInTemp(vector<string> Tokens);
  Q_INVOKABLE   int OpsInTemp(vector<string> Tokens);
  Q_INVOKABLE int IsGoodInput(QString equationStr);
   int HowManyInPare(vector<string> Tokens);
   Q_INVOKABLE int IsGoodNoFlag(QString equationStr);
   Q_INVOKABLE  Element* ParseQML(QString equationStr);
   Q_INVOKABLE  string ChangeString(vector<string> Tokens);
  Q_INVOKABLE   bool HasInnerPare(vector<string> checking);
   Q_INVOKABLE  vector<string> CreateTemp(vector<string> Tokens, unsigned int firstIndex, unsigned int secondIndex);
 

    private:
   string parseFlag;
   stack<Element> NumStack;
   stack<string> Ops;
     int paretheses = 0;
    int operators = 0;
    int numbers = 0;
  
};
#endif