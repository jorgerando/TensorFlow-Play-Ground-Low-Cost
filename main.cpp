#include <iostream>
#include "matrix.hpp"

double Relu(double x) {

  if (x > 0) {
     return x ;
  }else{
     return 0 ;
  }

}

Matrix x0 = Matrix(2,1);
Matrix W1 = Matrix(3,2);
Matrix W2 = Matrix(2,3);
Matrix W3 = Matrix(1,2);

int main() {

    x0.setElement(0,0,1);
    x0.setElement(1,0,1);

    W1.randomInitialization(0,1);
    W2.randomInitialization(0,1);
    W3.randomInitialization(0,1);

    x0.show();
    std::cout << "----------------" << std::endl;
    Matrix x1 = W1.mult(x0).aplayFuntion(&Relu);
    x1.show();
    Matrix x2 = W2.mult(x1).aplayFuntion(&Relu);
    std::cout << "----------------" << std::endl;
    x2.show();
    Matrix x3 = W3.mult(x2).aplayFuntion(&Relu);
    std::cout << "----------------" << std::endl;
    x3.show();

    return 0;
}
