#ifndef MICLASE_H
#define MICLASE_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>

class Matrix {

private:

  unsigned int rows , colums ;
  std::vector<std::vector<double>> elements ;

public:

    Matrix( unsigned int rows_ , unsigned int colums_ );

    void show();

    void randomInitialization(int min , int max );

    unsigned int getRows();

    unsigned int getColums();

    double getElement( int row ,  int col );

    void setElement(int row , int col , double new_ );

    Matrix copy();

    bool sameDim( Matrix b );

    void scalarMultiply(double escalar); // A * esc

    void sum( Matrix b ); // A + B

    void mulByTerms(Matrix b); // A *? B

    bool canMult( Matrix b); // A * B

    void mult(Matrix b) ; // A * B

    Matrix transpose() ; // A^T

    void aplayFuntion( double (*func)(double) ) ; // f(A)

};

#endif
