#include <iostream>
#include <vector>
#include "matrix.hpp"
#include "funtions.hpp"

class Network {

private:

   std::vector<int> dim;
   std::vector<Matrix> W;
   std::vector<Matrix> X;
   std::vector<Matrix> deltas;
   std::vector<Matrix> WG;
   int layers ;
   std::string activation;

public :
   Network( std::vector<int> dim_,std::string act );

   void builtNet();

   void showNet();

   Matrix forward(Matrix data);

   Matrix error(Matrix pre , Matrix target);

   void calcGradients(Matrix pre, Matrix target);

   void updateWeights(double alfa);

};
