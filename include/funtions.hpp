#include <iostream>
#include <cmath>
#include <unordered_map>

typedef double (*FuncionPtr)(double);

double relu(double x);

double reluD(double x);

double sigmoide(double x);

double sigmoideD(double x);

double tanHip(double x);

double tanHipD(double x);

extern std::unordered_map<std::string,FuncionPtr> functions ;

extern std::unordered_map<std::string,FuncionPtr> derivative ;
