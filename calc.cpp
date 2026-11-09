#include <iostream>
#include <string>
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
int CheckValidEquation(std::string op);
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
int firstNumAsInt =0;
double firstNumAsDouble = 0.0;
bool firstIsDouble= false;
bool firstIsInt = false;
int secondNumAsInt = 0;
double secondNumAsDouble = 0.0;
bool secondIsDouble = false;
bool secondIsInt = false;
};
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


int calc::FirstCheckInt(string firstNumber){
  try{
firstNumAsInt = stoi(firstNumber);
firstIsInt = true;
return 0;
  }
  catch(const invalid_argument&){
    return 1;
  }
}
int calc::CheckValidOp(string Checking){  
  if(Checking.find("+") != string::npos){
    return 0;
  }
  if(Checking.find("-") != string::npos){
    return 0;
  }
  if(Checking.find("*") != string::npos){
    return 0;
  }
  if(Checking.find("/") != string::npos){
    return 0;
  }
  if(Checking.find("%") != string::npos){
    return 0;
  }
  return 4;
}
int calc::FirstCheckDouble(string firstNumber){
  try{
firstNumAsDouble = stod(firstNumber);
firstIsDouble = true;
return 0;
  }
  catch(const invalid_argument&){  
    return 1;
  }
}
int calc::ThirdCheckInt(string thirdvalue){
  try{
    secondNumAsInt = stoi(thirdvalue);
    secondIsInt = true;
    return 0;
  }
  catch(const invalid_argument&){  
    return 1;
  }
}
int calc::ThirdCheckDouble(string thirdvalue){
  try{
    secondNumAsDouble = stod(thirdvalue);
    secondIsDouble = true;
  }
  catch(const invalid_argument&){  
    return 1;
  }
  return 0;
}

int calc::LookAtFirstValue(string lengthCheck){
    if(lengthCheck.find(".")!= string::npos ){
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
int calc::LookAtThirdValue(string thirdValue){
  if(thirdValue.find(".")!= string::npos){
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
int calc::CalculateInts(string Op){
     if((Op.find("/") != string::npos) && secondNumAsInt == 0){
    throw domain_error("Error: Can't divide by 0");
  }
   if((Op.find("%") != string::npos) && secondNumAsInt == 0){
    throw domain_error("Error: Can't do modulo by 0");
  }

  if(Op.find("+") != string::npos){
    return firstNumAsInt + secondNumAsInt;
  }

   if(Op.find("-") != string::npos){
    return firstNumAsInt - secondNumAsInt;

  }
    if(Op.find("*") != string::npos){
    return firstNumAsInt * secondNumAsInt;
  }
    if(Op.find("/") != string::npos){
    return firstNumAsInt / secondNumAsInt;
  }
  if(Op.find("%") != string::npos){
    return firstNumAsInt % secondNumAsInt;
  }  
  return 0;
}
double calc::CalcFirstDouble(string op){
    if((op.find("/") != string::npos) && secondNumAsInt == 0){
    throw domain_error("Error: Can't divide by 0");
  }
   if((op.find("%") != string::npos) && secondNumAsInt == 0){
    throw domain_error("Error: Can't do modulo by 0");
  }
  if(op.find("+") != string::npos){
    return firstNumAsDouble + secondNumAsInt;
  }
  if(op.find("-") != string::npos){
    return firstNumAsDouble - secondNumAsInt;
  }
   if(op.find("*") != string::npos){
    return firstNumAsDouble * secondNumAsInt;
  }
   if(op.find("/") != string::npos){
    return firstNumAsDouble / secondNumAsInt;
  }
  return 0.0;
}
double calc::CalcSecondDouble(string op){
     if((op.find("/") != string::npos) && secondNumAsDouble == 0.0){
    throw domain_error("Error: Can't divide by 0");
  }
   if((op.find("%") != string::npos) && secondNumAsDouble == 0.0){
    throw domain_error("Error: Can't do modulo by 0");
  }

  if(op.find("+") != string::npos){
    return firstNumAsInt + secondNumAsDouble;
  }
 if(op.find("-") != string::npos){
    return firstNumAsInt - secondNumAsDouble;
  }
   if(op.find("*") != string::npos){
    return firstNumAsInt * secondNumAsDouble;
  }
   if(op.find("/") != string::npos){
    return firstNumAsInt / secondNumAsDouble;
  }
  return 0.0;
}
double calc::CalcBothDoubles(string op){
      if((op.find("/") != string::npos) && secondNumAsDouble == 0.0){
    throw domain_error("Error: Can't divide by 0");
  }
   if((op.find("%") != string::npos) && secondNumAsDouble == 0.0){
    throw domain_error("Error: Can't do modulo by 0");
  }
  if(op.find("+") != string::npos){
    return firstNumAsDouble + secondNumAsDouble;
  }
   if(op.find("-") != string::npos){
    return firstNumAsDouble - secondNumAsDouble;
  }
   if(op.find("*") != string::npos){
    return firstNumAsDouble * secondNumAsDouble;
  }
   if(op.find("/") != string::npos){
    return firstNumAsDouble / secondNumAsDouble;
  }
  return 0.0;
}
int calc::OpenUpFile(string inputFile ){
ifstream inFS;
 inFS.open(inputFile);
 if(!inFS.is_open()){
  return 2;
 }
  return 0;
}

int calc::CheckInput(char* argv[]){
 string firstUp = argv[1];
    if(LookAtFirstValue(firstUp)== 1){
     return 3;
     }
     string op = argv[2];
   
   if(CheckValidOp(op)== 4){
    return 4;
   }
   string thirdValue = argv[3];
   if(LookAtThirdValue(thirdValue)== 1){
    return 5;
   }
return 0;
}
int calc::CheckInput(string argv[]){
 string firstUp= argv[0];
    if(LookAtFirstValue(firstUp)== 1){
     return 3;
     }
      
     string op= argv[1];
    
   if(CheckValidOp(op)== 4){
    return 4;
   }
   string thirdValue =  argv[2];
   if(LookAtThirdValue(thirdValue)== 1){
    return 5;
   }
return 0;
}
void calc::WhichError(int ErrorNumber,string argv[]){
    if (ErrorNumber== 3){
       cerr << "Error: Left operand "<< argv[0] << " is not a valid number" << endl;
    }
     else if(ErrorNumber == 4){
       cerr << "Error: Invalid operator" << endl;
    
    }
    else if(ErrorNumber==5){
        cerr << "Error: Right operand "<< argv[2] << " is not a valid number" << endl;
      
    }   

}

int calc::CheckValidEquation(string op){
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
void calc::RunCalculations(string whichOp){
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

int calc::CheckLine(string line){
 int firstSpace = line.find(' ');
 string firstValue = line.substr(0, firstSpace);
 if(firstValue.length()== 0){
  return 1;
 }
 string afterFirst = line.substr(firstSpace+1);
 int secondSpace = afterFirst.find(' ');
 string secondValue = afterFirst.substr(0, 1);
 if(secondValue.length() == 0){
  return 1;
 }
 string afterSecond= afterFirst.substr(secondSpace+1);
 if(afterSecond.length() == 0){
  return 1;
 }
return 0;

}
int calc::readThroughFile(string inputFile){
  string FirstNum;
  string op;
  string SecondNum;
  string hold[3];
string line;

  int lineNumber = 0;
  ifstream inFS;
 inFS.open(inputFile);
 while(!inFS.eof()){
  getline(inFS,line);
  
  if(CheckLine(line)== 1){
    cerr << "Error: Line " <<lineNumber+1 << " is missing an element" << endl;
    return lineNumber+3;
  }
 
  FirstNum= line.substr(0, line.find(' '));
  string cutoff = line.substr(line.find(' ')+1);
   hold[0] = FirstNum;
     op = cutoff.substr(0, cutoff.find(' '));
   hold[1] = op;
   if(op.length()!= 1){
       cerr << "Error: Invalid operator" << endl;
       return 4;
   }
   SecondNum = line.substr(line.find(op)+1);
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
  
    if(secondNumAsInt == 0 && op.find("%") != string::npos){
      cerr << "Error: Can't perform modulo by 0" << endl;
      return 2 + lineNumber;
    }
      if(secondNumAsInt == 0 && op.find("/") != string::npos){
        cerr << "Error: Can't divide by 0" << endl;
      return 2 + lineNumber;
    }
   }
  else {

      if(secondNumAsDouble == 0.00 && op.find("/") != string::npos){
        cerr << "Error: Can't divide by 0" << endl;
      return 2 + lineNumber;
    }
  }
   if(secondIsDouble == true || firstIsDouble == true){
    if(op.find("%") != string::npos){
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