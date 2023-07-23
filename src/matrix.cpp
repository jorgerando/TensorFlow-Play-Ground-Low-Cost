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

}

void Matrix::show(){

  for (const auto& fila : elements ) {
        for (double elemento : fila) {
            std::cout << /*std::setprecision(4) << */ elemento << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::randomInitialization( int min, int max) {
       std::srand(static_cast<unsigned int>(std::time(nullptr))); // random seed
        for (int i = 0; i < rows ; ++i) {
             for (int j = 0; j < colums ; ++j) {
               double r = static_cast<double>(std::rand()) / RAND_MAX;
                elements[i][j] = min + r * (max - min);
            }
        }
}

Matrix Matrix::scalarMultiply(double escalar){

  Matrix result = Matrix(rows,colums) ;

  for (int i = 0; i < rows ; ++i) {
       for (int j = 0; j < colums ; ++j) {
            result.setElement(i,j,elements[i][j] * escalar) ;
       }
   }

   return result ;

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

Matrix Matrix::sum( Matrix b ){

    if( ! this->sameDim(b) ){
      throw std::runtime_error("sum(A,B) must have the same dimension");
    }

    Matrix result = Matrix(rows,colums);

    for (int i = 0; i < rows ; ++i) {
         for (int j = 0; j < colums ; ++j) {
             result.setElement(i,j,  elements[i][j] + b.getElement(i,j) ) ;
         }
     }

     return result ;
}

Matrix Matrix::sub( Matrix b ){

    if( ! this->sameDim(b) ){
      throw std::runtime_error("sum(A,B) must have the same dimension");
    }

    Matrix result = Matrix(rows,colums);

    for (int i = 0; i < rows ; ++i) {
         for (int j = 0; j < colums ; ++j) {
             result.setElement(i,j,elements[i][j] - b.getElement(i,j) ) ;
         }
     }

     return result ;
}

void Matrix::setElement(int row , int col , double new_ ){

     if ( row > rows ){ throw std::runtime_error("Out of index row");}

     if (col > colums){ throw std::runtime_error("Out of index colums"); }

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

Matrix Matrix::mulByTerms(Matrix b){

    if( ! this->sameDim(b) ){
      throw std::runtime_error("mulByTerms(A,B) must have the same dimension");
    }

    Matrix result = Matrix(rows,colums);

    for (int i = 0; i < rows ; ++i) {
        for (int j = 0; j < colums ; ++j) {
                 result.setElement(i,j,elements[i][j] * b.getElement(i,j) );
        }
    }
    return result ;

}

bool Matrix::canMult( Matrix b){
  return colums == b.getRows();
}

Matrix Matrix::mult(Matrix b) {

     if (! this->canMult(b) ) {
          throw std::runtime_error("A*B A columns must be equalto B rows ");
     }

     Matrix new_ = Matrix(rows,b.getColums());

     for (int i = 0; i < rows ; ++i) {
        for (int j = 0; j < b.getColums() ; ++j) {
            double sum = 0;
            for (int k = 0; k < colums ; ++k) {
                sum = sum + elements[i][k] * b.getElement(k,j);
            }
            new_.setElement(i,j,sum);
        }
    }

     return new_;
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

Matrix Matrix::aplayFuntion( double (*func)(double) ){

  Matrix result = Matrix(rows,colums);

  for (int i = 0; i < rows ; ++i) {
       for (int j = 0; j < colums ; ++j) {
           result.setElement(i,j,func( elements[i][j] ) )  ;
       }
   }

   return result ;
}
