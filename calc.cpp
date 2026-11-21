#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <QtQmlIntegration/qqmlintegration.h>
#include "calc.h"




using namespace std;

void calc::Reset(){
  firstNumAsInt = 0;
  firstNumAsDouble= 0.00;
  firstIsDouble = false;
  firstIsInt = false;
  secondNumAsInt = 0;
  secondNumAsDouble = 0.00;
  secondIsInt = false;
  secondIsDouble = false;
}
void calc::SetFirstNum(int FirstVal){
  firstNumAsInt = FirstVal;
  firstIsInt = true;
  firstIsDouble = false;

}
void calc::SetFirstNum(double FirstVal){
  firstNumAsDouble = FirstVal;
  firstIsDouble = true;
  firstIsInt = false;

}

void calc::SetSecondNum(int SecondVal){
  secondNumAsInt = SecondVal;
  secondIsInt = true;
  secondIsDouble = false;

}
void calc::SetSecondNum(double SecondVal){
  secondIsInt = false;
  secondIsDouble = true;
  secondNumAsDouble = SecondVal;
}


int calc::FirstCheckInt(QString firstNumber){
  try{
firstNumAsInt = firstNumber.toInt();
firstIsInt = true;
return 0;
  }
  catch(const invalid_argument&){
    return 1;
  }
}
int calc::CheckValidOp(QString Checking){  
  if(Checking.contains("+")){
    return 0;
  }
  if(Checking.contains("-")){
    return 0;
  }
  if(Checking.contains("*") ){
    return 0;
  }
  if(Checking.contains("/")){
    return 0;
  }
  if(Checking.contains("%") ){
    return 0;
  }
  return 4;
}
int calc::FirstCheckDouble(QString firstNumber){
  try{
firstNumAsDouble = firstNumber.toDouble();
firstIsDouble = true;
return 0;
  }
  catch(const invalid_argument&){  
    return 1;
  }
}
int calc::ThirdCheckInt(QString thirdvalue){
  try{
    secondNumAsInt = thirdvalue.toInt();
    secondIsInt = true;
    return 0;
  }
  catch(const invalid_argument&){  
    return 1;
  }
}
int calc::ThirdCheckDouble(QString thirdvalue){
  try{
    secondNumAsDouble = thirdvalue.toDouble();
    secondIsDouble = true;
  }
  catch(const invalid_argument&){  
    return 1;
  }
  return 0;
}

int calc::LookAtFirstValue(QString lengthCheck){
    if(lengthCheck.contains(".") ){
    if(FirstCheckDouble(lengthCheck)== 1){
      return 1;
    }
  }
  else{
    if(FirstCheckInt(lengthCheck)== 1){
      return 1;
    }
    }
  return 0;
}
int calc::LookAtThirdValue(QString thirdValue){
  if(thirdValue.contains(".")){
     if(ThirdCheckDouble(thirdValue)== 1){
      return 1;
     }
  }
  else{
     if(ThirdCheckInt(thirdValue)== 1){
      return 1;
     }
  }
  return 0;
}
int calc::CalculateInts(QString Op){
     if((Op.contains("/")) && secondNumAsInt == 0){
    throw domain_error("Error: Can't divide by 0");
  }
   if((Op.contains("%")) && secondNumAsInt == 0){
    throw domain_error("Error: Can't do modulo by 0");
  }

  if(Op.contains("+")){
    return firstNumAsInt + secondNumAsInt;
  }

   if(Op.contains("-")){
    return firstNumAsInt - secondNumAsInt;

  }
    if(Op.contains("*")){
    return firstNumAsInt * secondNumAsInt;
  }
    if(Op.contains("/")){
    return firstNumAsInt / secondNumAsInt;
  }
  if(Op.contains("%")){
    return firstNumAsInt % secondNumAsInt;
  }  
  return 0;
}
double calc::CalcFirstDouble(QString op){
    if((op.contains("/"))&& secondNumAsInt == 0){
    throw domain_error("Error: Can't divide by 0");
  }
   if((op.contains("%")) && secondNumAsInt == 0){
    throw domain_error("Error: Can't do modulo by 0");
  }
  if(op.contains("+") ){
    return firstNumAsDouble + secondNumAsInt;
  }
  if(op.contains("-")){
    return firstNumAsDouble - secondNumAsInt;
  }
   if(op.contains("*")){
    return firstNumAsDouble * secondNumAsInt;
  }
   if(op.contains("/")){
    return firstNumAsDouble / secondNumAsInt;
  }
  return 0.0;
}
double calc::CalcSecondDouble(QString op){
     if((op.contains("/")) && secondNumAsDouble == 0.0){
    throw domain_error("Error: Can't divide by 0");
  }
   if((op.contains("%") ) && secondNumAsDouble == 0.0){
    throw domain_error("Error: Can't do modulo by 0");
  }

  if(op.contains("+")){
    return firstNumAsInt + secondNumAsDouble;
  }
 if(op.contains("-")){
    return firstNumAsInt - secondNumAsDouble;
  }
   if(op.contains("*") ){
    return firstNumAsInt * secondNumAsDouble;
  }
   if(op.contains("/") ){
    return firstNumAsInt / secondNumAsDouble;
  }
  return 0.0;
}
double calc::CalcBothDoubles(QString op){
      if((op.contains("/")) && secondNumAsDouble == 0.0){
    throw domain_error("Error: Can't divide by 0");
  }
   if((op.contains("%")) && secondNumAsDouble == 0.0){
    throw domain_error("Error: Can't do modulo by 0");
  }
  if(op.contains("+") ){
    return firstNumAsDouble + secondNumAsDouble;
  }
   if(op.contains("-")){
    return firstNumAsDouble - secondNumAsDouble;
  }
   if(op.contains("*")){
    return firstNumAsDouble * secondNumAsDouble;
  }
   if(op.contains("/")){
    return firstNumAsDouble / secondNumAsDouble;
  }
  return 0.0;
}
int calc::OpenUpFile(QString inputFile ){


ifstream inFS;

 inFS.open(inputFile.toStdString());
 if(!inFS.is_open()){
  return 2;
 }
  return 0;
}

int calc::CheckInput(char* argv[]){
 QString firstUp = argv[1];
    if(LookAtFirstValue(firstUp)== 1){
     return 3;
     }
     QString op = argv[2];
   
   if(CheckValidOp(op)== 4){
    return 4;
   }
   QString thirdValue = argv[3];
   if(LookAtThirdValue(thirdValue)== 1){
    return 5;
   }
return 0;
}
int calc::CheckInput(QString argv[]){
 QString firstUp= argv[0];
    if(LookAtFirstValue(firstUp)== 1){
     return 3;
     }
      
     QString op= argv[1];
    
   if(CheckValidOp(op)== 4){
    return 4;
   }
   QString thirdValue =  argv[2];
   if(LookAtThirdValue(thirdValue)== 1){
    return 5;
   }
return 0;
}
void calc::WhichError(int ErrorNumber,QString argv[]){
    if (ErrorNumber== 3){
       cerr << "Error: Left operand "<< argv[0].toStdString() << " is not a valid number" << endl;
    }
     else if(ErrorNumber == 4){
       cerr << "Error: Invalid operator" << endl;
    
    }
    else if(ErrorNumber==5){
        cerr << "Error: Right operand "<< argv[2].toStdString() << " is not a valid number" << endl;
      
    }   

}

int calc::CheckValidEquation(QString op){
  if(op == "/"){
    if(secondIsInt && secondNumAsInt ==0){
      return 6;
    } 
   if(secondIsDouble && secondNumAsDouble == 0.0){
      return 6;
    }
  }
  if(op == "%"){
    if(firstIsDouble || secondIsDouble){
      return 7;
    }
    if(secondIsInt && secondNumAsInt == 0){
      return 8;
    }
  }

return 0;
}
void calc::RunCalculations(QString whichOp){
   if((firstIsInt == true)&& (secondIsInt == true)){
    cout << CalculateInts(whichOp);
   }
   else if((firstIsDouble == true)&& (secondIsInt== true)){
    cout << CalcFirstDouble(whichOp);
   }
   else if((firstIsInt == true)&& (secondIsDouble== true)){
    cout << CalcSecondDouble(whichOp);
   }
   else{
    cout << CalcBothDoubles(whichOp);
   }
}

void calc::WhichError(int ErrorNumber,char* argv[]){
    if (ErrorNumber== 3){
       cerr << "Error: Left operand "<< argv[1] << " is not a valid number" << endl;
    }
     else if(ErrorNumber == 4){
       cerr << "Error: Invalid operator" << endl;
    
    }
    else if(ErrorNumber==5){
        cerr << "Error: Right operand "<< argv[3] << " is not a valid number" << endl;  
    }   

}
void calc::WhichError(int ErrorNumber){
   if(ErrorNumber == 6){
    cerr << "Error: Can't divide by 0" << endl;
   }
   if(ErrorNumber == 7){
     cerr << "Error: Modulo is for integers only" << endl;
   } 
   if(ErrorNumber == 8){
    cerr << "Error: Can't perform modulo by 0" << endl;
   }

}

int calc::CheckLine(QString line){
 int firstSpace = line.indexOf(' ');
 QString firstValue = line.mid(0, firstSpace);
 if(firstValue.length()== 0){
  return 1;
 }
 QString afterFirst = line.mid(firstSpace+1);
 int secondSpace = afterFirst.indexOf(' ');
 QString secondValue = afterFirst.mid(0, 1);
 if(secondValue.length() == 0){
  return 1;
 }
 QString afterSecond= afterFirst.mid(secondSpace+1);
 if(afterSecond.length() == 0){
  return 1;
 }
return 0;

}
int calc::readThroughFile(QString inputFile){
  QString FirstNum;
  QString op;
  QString SecondNum;
  QString hold[3];
QString line;
string temp;
  int lineNumber = 0;
  ifstream inFS;
 inFS.open(inputFile.toStdString());
 while(!inFS.eof()){
  getline(inFS,temp);
  line = QString::fromStdString(temp);
  if(CheckLine(line)== 1){
    cerr << "Error: Line " <<lineNumber+1 << " is missing an element" << endl;
    return lineNumber+3;
  }
 
  FirstNum= line.mid(0, line.indexOf(' '));
  QString cutoff = line.mid(line.indexOf(' ')+1);
   hold[0] = FirstNum;
     op = cutoff.mid(0, cutoff.indexOf(' '));
   hold[1] = op;
   if(op.length()!= 1){
       cerr << "Error: Invalid operator" << endl;
       return 4;
   }
   SecondNum = line.mid(line.indexOf(op)+1);
   hold[2] = SecondNum;
  lineNumber++;  
  if (!inFS.fail()) {
    int inputStatus = CheckInput(hold);
  
    if(inputStatus != 0){

      WhichError(inputStatus, hold);  
      return 2 + lineNumber;
    }
   int opStatus = CheckValidEquation(op);
   if(opStatus!= 0){
    WhichError(opStatus);
    return 2 + lineNumber;
   }
   if(secondIsInt == true){
  
    if(secondNumAsInt == 0 && op.contains("%")){
      cerr << "Error: Can't perform modulo by 0" << endl;
      return 2 + lineNumber;
    }
      if(secondNumAsInt == 0 && op.contains("/")){
        cerr << "Error: Can't divide by 0" << endl;
      return 2 + lineNumber;
    }
   }
  else {

      if(secondNumAsDouble == 0.00 && op.contains("/") ){
        cerr << "Error: Can't divide by 0" << endl;
      return 2 + lineNumber;
    }
  }
   if(secondIsDouble == true || firstIsDouble == true){
    if(op.contains("%")){
      cerr << "Error: Modulo is for integers only" << endl;
      return 2 + lineNumber;
    }
   }  
   try{
     RunCalculations(op);
   }
  catch(const exception& e){
    cout << e.what() << endl;
    return 2 + lineNumber;

  }
    Reset();
  }
 }
 return 0;
}