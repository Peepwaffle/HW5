#ifndef CALC_H

#define CALC_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

#include <QObject>
#include <QtQmlIntegration/qqmlintegration.h>

using namespace std;
class calc: public QObject{
      Q_OBJECT
  QML_ELEMENT
public:
void Reset();
    Q_INVOKABLE int FirstCheckInt(QString firstNumber);
    Q_INVOKABLE int CheckValidOp(QString Checking);
    Q_INVOKABLE int FirstCheckDouble(QString firstNumber);
     Q_INVOKABLE int ThirdCheckInt(QString thirdvalue);
    Q_INVOKABLE int ThirdCheckDouble(QString thirdvalue);
    Q_INVOKABLE int LookAtFirstValue(QString lengthCheck);
Q_INVOKABLE int LookAtThirdValue(QString lengthCheck);
Q_INVOKABLE int CalculateInts(QString Op);
Q_INVOKABLE double CalcFirstDouble(QString op);
Q_INVOKABLE double CalcSecondDouble(QString op);
Q_INVOKABLE double CalcBothDoubles(QString op);
Q_INVOKABLE int OpenUpFile(QString inputFile);
Q_INVOKABLE int CheckInput(char* argv[]);
Q_INVOKABLE int CheckInput(QString argv[]);
Q_INVOKABLE void WhichError(int ErrorNumber, QString argv[]);
Q_INVOKABLE int CheckValidEquation(QString op);
Q_INVOKABLE void RunCalculations(QString whichOp);
Q_INVOKABLE void WhichError(int ErrorNumber, char* argv[]);
Q_INVOKABLE void WhichError(int ErrorNumber);
Q_INVOKABLE int readThroughFile(QString inputFile);
    Q_INVOKABLE void SetFirstNum(int FirstVal);
    Q_INVOKABLE void SetFirstNum(double FirstVal);
    Q_INVOKABLE void SetSecondNum(int SecondVal);
    Q_INVOKABLE void SetSecondNum(double SecondVal);
Q_INVOKABLE int CheckLine(QString line);
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