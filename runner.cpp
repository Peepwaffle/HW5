#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "calc.h"
#include "exceptions.h"
#include "element.h"
#include "operation.h"
#include "Tests.h"
#include <vector>
#include <unistd.h>
#include "parser.h"

using namespace std;

string CorrectlySpace(string toStart){
  string CorrectString = "";
  string part;
   stringstream AsStream(toStart);
    while(AsStream >> part){
         CorrectString+= part+ " ";
      }   
  return CorrectString;
}
bool CanBeOp(string trying){
string test = CorrectlySpace(trying);
try{
Operation tryer(test);
}
catch(InvalidOperator &e){
  return false;
}
catch(InvalidElement &e){
 return false;
}
  return true;
}
string ConvertToString(char* array[], int size, string flag){
  string Converted;
  if(flag == "No flag"){
  for(int i = 1; i <  size; i++){
    if(i+ 1 == size){
        Converted = Converted+array[i];
    }
    else{
       Converted = Converted+array[i]+ " ";
       }
  }
  }
  else{
     for(int i = 2; i <  size; i++){ 
    if((i+ 1) == size){
        Converted = Converted+array[i];
    }
    else{
       Converted = Converted+array[i]+ " ";}
  }
  }
  return Converted;
}

string CheckFlags(int argc,char* argv[]){
  int opt;
  while((opt =getopt(argc, argv, "c:f"))!= -1){
    switch (opt){
     case 'f':
     return "f";
     case 'c':
     return "c";
     case '?':
     try{
       Element test(opt);
      return "No flag";
     }
     catch(const InvalidElement& e){
       return "Not found";
     }
    }
  }
return "No flag";
}

int Run(int argc, char* argv[]){
  string flag = CheckFlags(argc, argv);
  if(flag == "Not found"){
    cerr << "Error: Flag not found" << endl;
    return 2;
  }
  if(flag == "-f"&& argc != 3){
    cerr << "Error: Too many elements" << endl;
    return 2;
  }
  string test = argv[1];
  if(argc == 2&& test == "test"){
      Tests r;
      r.RunTests(); 
return 0;
  }
 calc calculator;
  if(argc == 1){
        cerr << "Enter a filename to parse or an equation to be parsed in the format of Left_Element Operator Right_Element" << endl;
        return 1;
    }
    try{
      if(flag == "f"){
        if(calculator.OpenUpFile(argv[2])== 2){
          cerr << "Cannot open file" << endl;
          return 2;
        }
      }
      if(flag == "c"){
        if(argc != 5){
          cerr << "Error: Not enough elements in input" << endl;
          return 2;
        }
        string opValue = argv[3];
        if(opValue.length()!=1){
          cerr << "Error: Operator is too long" << endl ;
          return 4;
        }
      }  
      string Converted = ConvertToString(argv, argc, flag);    
if(flag == "No flag"&& argc == 2){
Converted = CorrectlySpace(Converted);
}
      Parser test;
      test.SetParseFlag(flag);
      if(flag == "f"){
        try{
         test.readThroughFile(Converted);}
        catch(DivideByZeroError &e){
          cerr << e.what();
          return 4;
        }
      }
    else{
  string asOne = "";
      if(flag == "No flag"){
        for(int i = 1; i< argc; ++i){
          if(CanBeOp(argv[i]) == true){
           string Converted2 = argv[i];
            Converted2 = CorrectlySpace(Converted2);
            Element* hold = test.Parse(Converted2);
      for(unsigned int index = 0; index < test.initialValues.size(); index++){
        cout << test.initialValues.at(index) << " ";
     }
      cout << "= ";
            cout << *hold << endl;
          }
          else{
          asOne = asOne+ argv[i]+" ";
          try{
            asOne = CorrectlySpace(asOne);
            Operation tempOperation(asOne);
            test.Parse(asOne);
        cout << test.initialValues.at(0) << " = " << test.initialValues.at(0) << endl;
            asOne = "";
          }
          catch(InvalidElement &e){
            continue;
          }    
          }
        }
        if(asOne!= ""){
        string correct = CorrectlySpace(asOne);
           Element* hold = test.Parse(correct);
            cout << correct << "= " << *hold << endl;}
      }  
      else{
       Element* hold = test.Parse(Converted);
     cout << *hold << endl;
   
    }
    }
    }
    catch(const InvalidEquationStructure& e){
      cerr << e.what() << endl;
      return 5;
    }
    catch(const InvalidOperator& e){
      cerr << e.what() << endl;
        return 3;
      }
    catch(const DivideByZeroError& e){
       cerr<< e.what() << endl;
      return 3;
    }
      catch(const ModuloByDoubleError& e){
      cerr << e.what() << endl;
      return 5;
    }
    catch(const InvalidElement& e){
      cerr << e.what() << endl;
      return 3;
    }
return 0;
}