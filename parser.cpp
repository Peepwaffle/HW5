#include <iostream>
#include <string>
#include "exceptions.h"
#include "element.h"
#include "parser.h"
#include <vector>
#include <stack>
#include "operation.h"
#include <stdexcept>
#include <fstream>

Parser::Parser(){
}
void Parser::SetParseFlag(string toFlag){
    if(toFlag== "c"){
        parseFlag = "c";
    }
    else if(toFlag == "No flag"){
        parseFlag = "o";
    }
    else{
        parseFlag = "f";
    }
}
void Parser::Reset(){
    paretheses = 0;
    operators = 0;
    numbers = 0;
    while(!NumStack.empty()){
        NumStack.pop();
    }
    parseFlag = "";
}
bool Parser::IsAnOP(string toCheck){
    if(toCheck.find('+')!= string::npos){
        if(toCheck.length()!= 1){
            throw InvalidEquationStructure("Successfully caught InvalidEquationStructure");
        }
        else{
            return true;
        }
    }
       if(toCheck== "/"){
       
        return true;
       }
     if(toCheck== "-"&& toCheck.length()== 1){
        return true;
    }
     if(toCheck.find('*')!= string::npos){
        if(toCheck.length()!= 1){
            throw InvalidEquationStructure("Successfully caught InvalidEquationStructure");
        }
        else{
            return true;
        }
     if(toCheck == "%"){
        if(toCheck.length()!= 1){
            throw InvalidEquationStructure("Successfully caught InvalidEquationStructure");
        }
        else{
            return true;
        }
    }
    }
    return false;
}

vector<string> Parser::GoThroughInput(const string& equationStr){
    numbers = 0;
    operators = 0;
    vector<string> Tokens;
    stringstream AsStream(equationStr);
    string token;
    while(getline(AsStream, token, ' ')){
         Tokens.push_back(token);
    } 
 unsigned int i;   
    for( i = 0; i < Tokens.size(); i++){   
        if(Tokens.at(i)== "%"){
         Ops.push(Tokens.at(i));
            operators+=1;
        }
       else if(Tokens.at(i)== "("|| Tokens.at(i)== ")"){
            paretheses+=1;
        }
        else if(IsAnOP(Tokens.at(i))== true){
            Ops.push(Tokens.at(i));
            operators+=1;
        }
        else{
            try{
               Element temp(Tokens.at(i));
                numbers += 1;     
                NumStack.push(temp);
            }
            catch(InvalidElement &e){
                throw InvalidElement("Invalid element value: "+ Tokens.at(i));
            }
        }
    }
    if(paretheses % 2 != 0){
        throw InvalidEquationStructure("Invalid element or order of components in equation");
    }
    if(numbers != (operators+1)){
        throw InvalidEquationStructure("Invalid element or order of components in equation");
    }
    return Tokens;
}
 int HowManyInPare(vector<string> Tokens){
    int counter = 0;
    for(unsigned int i = 0; i<Tokens.size(); i++){
        if(Tokens.at(i)== "+"){
            counter +=1;
        }
      else if(Tokens.at(i)== "-"){
            counter +=1;
        }
        else if(Tokens.at(i)== "*"){
            counter +=1;
        }
        else if(Tokens.at(i)== "/"){
            counter +=1;
        }
        else if(Tokens.at(i)== "%"){
            counter +=1;
        }
    }
    return counter;
 }
Element* Parser::PerformNextCalculation(string nextOp, vector<string> Tokens){
    string FirstElementValue;
    string SecondElementValue;
  unsigned int i;
 for( i = 0; i < Tokens.size(); i++){
    if(Tokens.at(i) == nextOp){
        FirstElementValue = Tokens.at(i-1);
        SecondElementValue= Tokens.at(i+1);       
        break;
    }
 }
 Element FirstElement(FirstElementValue);
if(stoi(FirstElementValue)== FirstElement.Value()&& FirstElement.IsDouble()==true){
    FirstElement.ChangeType();
}
 Element SecondElement(SecondElementValue);
 if(stoi(SecondElementValue)== SecondElement.Value()&& SecondElement.IsDouble()==true){
    SecondElement.ChangeType();
}
 try{
     Operation Operate(FirstElement, nextOp[0], SecondElement);
     return new Element(Operate.Value());
 }
 catch(DivideByZeroError &e){
    throw DivideByZeroError("Divide by zero error");
 }
 catch(InvalidOperator &e){
    throw InvalidOperator("Invalid element value:" + nextOp[0]);
 }
}
    Element* Parser::RunThroughNoParentheses(vector<string> Tokens){
while(Tokens.size()!= 1){
        string nextOp = WhichOp();      
        Element* Calculated = PerformNextCalculation(nextOp, Tokens);
        Tokens = Remove(Tokens, nextOp, Calculated);
        Ops = removeFromStack(nextOp);
        stack<string> temp = Ops;
        Ops = ReverseStack(temp);
}
return new Element(Tokens.front());
}
int Parser::numberofInstances(string toRemove){
    int number = 0;
    stack<string> copyStack(Ops);
    while(!copyStack.empty()){
        if(copyStack.top() == toRemove){
            number +=1;
        }
        copyStack.pop();
    }
    return number;
}
stack<string> Parser::removeFromStack(string toRemove){
    stack<string> copyStack= Ops;
    stack<string> newStack;
    bool foundOperator = false;
    while(foundOperator == false){
        if(copyStack.top()!= toRemove){
            newStack.push(copyStack.top());
            copyStack.pop();
        }
        else{
            copyStack.pop();
            foundOperator = true;
            break;
        }  
    }
    while(newStack.size()!= (Ops.size()-1)){
        newStack.push(copyStack.top());
            copyStack.pop();      
    }
   return newStack;
}
vector<string> Parser::Remove(vector<string> Tokens, string nextOp, Element* toReplace){
    vector<string> copy(Tokens);
     unsigned int i;
 for( i = 0; i < Tokens.size(); i++){
    if(Tokens.at(i)== nextOp){
       break;
    }
 }
 int k = short(i);
copy.erase(copy.begin()+(k-1), copy.begin()+(k+2));
copy.emplace(copy.begin()+(k-1), to_string(toReplace->Value()));
 return copy;
}
int Parser::OperatorPriority(string OptoCheck){
    if(OptoCheck == "+"){
        return 1;
    }
     if(OptoCheck == "-"){
        return 1;
    }
    if(OptoCheck == "*"){
        return 2;
    }
    if(OptoCheck == "/"){
        return 2;
    }
      if(OptoCheck == "%"){
        return 2;
    }
    return 0;
}
stack<string> Parser::ReverseStack(stack<string> OriginalStack){
    stack<string> newStack;
    stack<string> copyStack = OriginalStack;
    while(!copyStack.empty()){
        newStack.push(copyStack.top());
        copyStack.pop();
    }
    return newStack;
}
string Parser::WhichOp(){
    if(Ops.size()!= 1){
    stack<string> tempStack(Ops);
    string TopOp = tempStack.top();
    tempStack.pop();
    string nextOp = tempStack.top();
    if(OperatorPriority(TopOp) > OperatorPriority(nextOp)){
        return TopOp;
    }
    else if(OperatorPriority(TopOp) < OperatorPriority(nextOp)){ 
        return nextOp;
    }
    else{
        return TopOp;
    }
    }
    else{
        return Ops.top();
    }
}
int Parser::FindFirstPare(vector<string> Tokens) {
    int close = FindSecondPare(Tokens);
    if (close < 0) {
        return -1;
    }
    for (int i = close - 1; i >= 0; --i) {
        if (Tokens.at(i) == "(") {
            return i;
        }
    }
    return -1;
}

int Parser::FindSecondPare(vector<string> Tokens) {
    for (int i = 0; i < static_cast<int>(Tokens.size()); ++i) {
        if (Tokens.at(i) == ")") {
            return i;
        }
    }
    return -1;
}
vector<string> Parser::CreateTemp(vector<string> Tokens, unsigned int firstIndex, unsigned int secondIndex){
    vector<string> ParVector;
    if(Tokens.at(firstIndex+1)== "("){
       for(unsigned int i = firstIndex+2; i < secondIndex; ++i){
             ParVector.push_back(Tokens.at(i));
    }
    }
    else{
    for(unsigned int i = firstIndex+1; i < secondIndex; ++i){
             ParVector.push_back(Tokens.at(i));      
    }
    }
return ParVector;
}
int Parser::OpsInTemp(vector<string> Tokens){
    int counter = 0;
    for(unsigned int i = 0; i < Tokens.size(); i++){
          try{
            Element(Tokens.at(i));
        }
        catch(InvalidElement &e){
             counter+=1;
        }
    }
        return counter;
    }
int Parser::NumbersInTemp(vector<string> Tokens){
      int counter = 0;
    for(unsigned int i = 0; i < Tokens.size(); i++){
        try{
            Element(Tokens.at(i));
            counter+=1;
        }
        catch(InvalidElement &e){
        }
    }
    return counter;
}
bool Parser::HasInnerPare(vector<string> checking){
      for(unsigned int f = 0; f < checking.size(); f++){
        if(checking.at(f)== "("){
            return true;
        }
      }
return false;
}
Element* Parser::GoParentheses(vector<string> Tokens){
    while(paretheses !=0){
       unsigned int firstIndex = FindFirstPare(Tokens);
      unsigned  int secondIndex = FindSecondPare(Tokens);
      vector<string> temp = CreateTemp(Tokens, firstIndex, secondIndex);
      if(HasInnerPare(temp)== true){
        temp.push_back(")");
      }  
      if(OpsInTemp(temp) == 1){
        Element first(temp.at(0));
        char op = temp.at(1)[0];
        Element second(temp.at(2));
        Element* OneOp = new Element(Operation(first, op, second).Value());
       Ops = removeFromStack(temp.at(1));
       if(firstIndex== 0 && Tokens.at(1)== "("){
          Tokens.erase(Tokens.begin()+firstIndex+1, Tokens.begin()+secondIndex+1);
         Tokens.emplace(Tokens.begin()+firstIndex+1, to_string(OneOp->Value()));
       }
       else{
         paretheses -=2;
        Tokens.erase(Tokens.begin()+firstIndex, Tokens.begin()+secondIndex+1);
         Tokens.emplace(Tokens.begin()+firstIndex, to_string(OneOp->Value()));
         }
      }
      else{
            paretheses -=2;
        stack<string> TempStack = Ops;
        while(!Ops.empty()){
            Ops.pop();
        }
        string ParString = ChangeString(temp);
       Element* NewValue;
       temp = GoThroughInput(ParString);
         NewValue = RunThroughNoParentheses(temp);
         Tokens.erase(Tokens.begin()+firstIndex, Tokens.begin()+secondIndex+1);
         Tokens.insert(Tokens.begin()+firstIndex, to_string(NewValue->Value()));  
       Ops = TempStack;
       for(unsigned int i = 0; i< temp.size(); i++){
      if(temp.at(i)[0]== '%'|| IsAnOP(temp.at(i))== true){
         Ops = removeFromStack(temp.at(i));
      }
       }
      }
    }
    return RunThroughNoParentheses(Tokens);
}

 string Parser::ChangeString(vector<string> Tokens){
    string newString = "";
    for(unsigned int i = 0; i < Tokens.size(); i++) {
        if(i == 0){
            newString = newString+Tokens.at(i);
        }
        else{
            newString = newString +" "+ Tokens.at(i);
        }
    }
    return newString;
}

Element* Parser::CreateNoFlag(vector<string> Tokens, const string& equationStr){
  if(paretheses == 0 && operators!= 1){
        return RunThroughNoParentheses(Tokens);
    }
    else if(paretheses != 0){
        return GoParentheses(Tokens);
    }
    if(operators == 1){
        try{
            string Changed = ChangeString(Tokens); 
         Operation operate(Changed);
         return new Element(operate.Value());
         }
         catch(ModuloByDoubleError &e){
            throw ModuloByDoubleError("Error: Cannot perform modulo with doubles");
         }
         catch(DivideByZeroError &e){
            throw DivideByZeroError(equationStr+ " = Divide by zero error");
         }
         catch(InvalidOperator &e){
            throw InvalidOperator("Invalid element value: " + Tokens.at(1));
         }  
    }
    return new Element();
}
 void Parser::readThroughFile(string fileName){
   string line;
      ifstream inFS;
 inFS.open(fileName);
 while(!inFS.eof()){
     getline(inFS, line);
    if(line != ""){
     cout << *Parse(line) << endl;
     }
     Reset();
 }
 }
Element* Parser::Parse(const string& equationStr){
    Reset();
    if(equationStr.find(' ')== string::npos && parseFlag != "f"){
        return new Element(equationStr);
    }
    if(parseFlag == "c"){
          initialValues =  GoThroughInput(equationStr);
        Operation operate(equationStr);   
        return new Element(operate.Value());
    }
    else{
        initialValues = GoThroughInput(equationStr);
        stack<string> temp = Ops;
        Ops = ReverseStack(temp);
        return CreateNoFlag(initialValues, equationStr);
    }   
}