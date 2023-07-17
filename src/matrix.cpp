#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "matrix.hpp"

Matrix::Matrix( unsigned int rows_ , unsigned int colums_) {

    if (rows_ > 0 && colums_ > 0 ) {
       rows = rows_ ;
       colums = colums_ ;
    }else {
       throw std::runtime_error("Error: el valor debe ser mayor que cero.");
    }

    elements.resize(rows, std::vector<double>(colums));

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // random seed
}

void Matrix::show(){

  for (const auto& fila : elements ) {
        for (double elemento : fila) {
            std::cout << std::setprecision(4) << elemento << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::randomInitialization( int min, int max) {

        for (int i = 0; i < rows ; ++i) {
             for (int j = 0; j < colums ; ++j) {
               double r = static_cast<double>(std::rand()) / RAND_MAX;
                elements[i][j] = min + r * (max - min);
            }
        }
}

void Matrix::scalarMultiply(double escalar){

  for (int i = 0; i < rows ; ++i) {
       for (int j = 0; j < colums ; ++j) {
           elements[i][j] =  elements[i][j] * escalar ;
       }
   }

}

unsigned int Matrix::getRows(){
  return rows ;
}

unsigned int Matrix::getColums(){
  return colums ;
}

double Matrix::getElement( int row , int col){
  return elements[row][col] ;
}

bool Matrix::sameDim(Matrix b){
   return b.getRows() == rows && b.getColums() == colums ;
}

void Matrix::sum( Matrix b ){

    if( ! this->sameDim(b) ){
      throw std::runtime_error("sum(A,B) must have the same dimension");
    }

    for (int i = 0; i < rows ; ++i) {
         for (int j = 0; j < colums ; ++j) {
             elements[i][j] =  elements[i][j] + b.getElement(i,j) ;
         }
     }
}

void Matrix::setElement(int row , int col , double new_ ){
     elements[row][col] = new_ ;
}

Matrix Matrix::copy(){

  Matrix copia = Matrix(rows,colums);

  for (int i = 0; i < rows ; ++i) {
       for (int j = 0; j < colums ; ++j) {
        copia.setElement(i,j,elements[i][j]) ;
      }
  }
  return copia ;
}

void Matrix::mulByTerms(Matrix b){

    if( ! this->sameDim(b) ){
      throw std::runtime_error("mulByTerms(A,B) must have the same dimension");
    }

    for (int i = 0; i < rows ; ++i) {
        for (int j = 0; j < colums ; ++j) {
                 elements[i][j] =  elements[i][j] * b.getElement(i,j) ;
        }
    }

}

bool Matrix::canMult( Matrix b){
  return colums == b.getRows();
}

void Matrix::mult(Matrix b) {

     if (! this->canMult(b) ) {
          throw std::runtime_error("A*B A columns must be equalto B rows ");
     }

     unsigned int new_rows = b.getColums();
     unsigned int new_cols = rows ;

     Matrix new_ = Matrix(new_rows,new_cols);


}

Matrix Matrix::transpose(){

  unsigned int new_rows = colums ;
  unsigned int new_cols = rows ;

  Matrix new_ = Matrix(new_rows,new_cols);

  for (int i = 0; i < rows ; ++i) {
       for (int j = 0; j < colums ; ++j) {
           new_.setElement(j,i,elements[i][j]);
       }
   }

   return new_ ;

}

void Matrix::aplayFuntion( double (*func)(double) ){

  for (int i = 0; i < rows ; ++i) {
       for (int j = 0; j < colums ; ++j) {
           elements[i][j] = func( elements[i][j] )  ;
       }
   }
}
