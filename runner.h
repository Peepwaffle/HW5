#ifndef RUNNER_H_INCLUDED
#define RUNNER_H_INCLUDED
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
class Runner{
    string CorrectlySpace(string toStart);
    bool CanBeOp(string trying);
    string ConvertToString(char* array[], int size, string flag);
    string CheckFlags(int argc,char* argv[]);
    int Run(int argc, char* argv[]);

}
#endif