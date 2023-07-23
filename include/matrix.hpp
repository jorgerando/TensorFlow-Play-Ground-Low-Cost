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

    Matrix scalarMultiply(double escalar); // A * esc

    Matrix sum( Matrix b ); // A + B

    Matrix sub( Matrix b); // A - B 

    Matrix mulByTerms(Matrix b); // A *? B

    bool canMult( Matrix b); // A * B

    Matrix mult(Matrix b) ; // A * B

    Matrix transpose() ; // A^T

    Matrix aplayFuntion( double (*func)(double) ) ; // f(A)

};
