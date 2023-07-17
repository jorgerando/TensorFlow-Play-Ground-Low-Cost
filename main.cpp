#include <iostream>
#include "matrix.hpp"

double plusOne(double x) {
  return x * x ;
}

Matrix A = Matrix(2,7);


int main() {

    std::cout << "Hola Mundo!" << std::endl;
    A.setElement(0,0,1.0);
    A.setElement(0,1,3.0);

    A.show();
    std::cout << "Hola Mundo!" << std::endl;
    Matrix a = A.transpose();
    A.aplayFuntion(&plusOne) ;
    A.show();
    /*
    A.show();
    std::cout << "----------------" << std::endl;
    B.show();
    std::cout << "----------------" << std::endl;
    Matrix C = A.copy();
    C.show();

    std::cout << "----------------" << std::endl;
    C.show();
    std::cout << "----------------" << std::endl;

    A.show();
    */

    //std::cout << A.sum(B) << std::endl;


    return 0;
}
