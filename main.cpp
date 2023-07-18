#include <iostream>
#include "matrix.hpp"
#include "funtions.hpp"

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
    Matrix x1 = W1.mult(x0).aplayFuntion(functions["relu"]);
    x1.show();
    Matrix x2 = W2.mult(x1).aplayFuntion(functions["relu"]);
    std::cout << "----------------" << std::endl;
    x2.show();
    Matrix x3 = W3.mult(x2).aplayFuntion(functions["relu"]);
    std::cout << "----------------" << std::endl;
    x3.show();

    return 0;
}
