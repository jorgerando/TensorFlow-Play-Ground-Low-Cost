#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>

typedef double (*FuncionPtr)(double);

double relu(double x){
  if ( x > 0 ){
    return x ;
  }else{
    return 0 ;
  }
}

double reluD(double x){
  if ( x > 0 ){
    return 1 ;
  }else{
    return 0 ;
  }
}

double sigmoide(double x){
   double e = M_E;
   return 1/(1 + pow(e, -x));
}

double sigmoideD(double x){
  return sigmoide(x)*(1-sigmoide(x));
}

double tanHip(double x){
    double e = M_E;
    double num = pow(e,x) - pow(e,-x);
    double dem = pow(e,x) + pow(e,-x);
    return num/dem ;
}

double tanHipD(double x){
  return 1 - (tanHip(x)*tanHip(x));
}

std::unordered_map<std::string,FuncionPtr> functions = {
  {"relu" , &relu } ,
  {"sigmoide" , &sigmoide },
  {"tanHip" , &tanHip }
} ;

std::unordered_map<std::string,FuncionPtr> derivative = {
  {"relu" , &reluD } ,
  {"sigmoide" , &sigmoideD },
  {"tanHip" , &tanHipD }
} ;
