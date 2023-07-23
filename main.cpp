#include <iostream>
#include "Network.hpp"

double f(double x){
  double m = 2.0 ;
  double b = 0.5 ;
  return x*m+b ;
}

double random_(){
   double min = -1 ;
   double max = 1 ;
   double r = static_cast<double>(std::rand()) / RAND_MAX;
   return min + r * (max - min);
}

double escalon(double x){
   if (x > 0.0 ){
     return 1.0 ;
   }else {
   return -1.0 ;
   }
}

int main() {

   std::vector<int> dim = {3,4,5,2,1};
   Network net = Network(dim,"sigmoide");
   net.builtNet();
   //net.showNet();
   Matrix x0 = Matrix(3,1);
   Matrix target = Matrix(1,1);

   x0.setElement(0,0,2);
   x0.setElement(1,0,2);
   x0.setElement(2,0,1);
   target.setElement(0,0,1);

   Matrix pre = net.forward(x0) ;
   net.showNet();

   std::cout << "-------------"<< std::endl;
   Matrix err = net.error(pre,target) ;
   //err.show();

   net.calcGradients(pre,target);

   net.updateWeights(0.5);

   net.showNet();



  /*
  Matrix W = Matrix(1,3);
  Matrix x0 = Matrix(3,1);
  Matrix eti = Matrix(1,1);
  W.randomInitialization(-5,5);

  while(true){

      double x = random_();
      double y = random_();

      if ( f(x) > y ){
         eti.setElement(0,0,1);
      }else {
         eti.setElement(0,0,-1);
      }

      x0.setElement(0,0,x);
      x0.setElement(1,0,y);
      x0.setElement(2,0,1);

      Matrix pre = W.mult(x0).aplayFuntion(&escalon);

      Matrix error = pre.sub(eti) ;

      double alfa = 0.05 ;
      Matrix gradient = error.mult(x0.transpose());
      W = W.sub( gradient.scalarMultiply(alfa) ) ;

      double w1 = W.getElement(0,0) ;
      double w2 = W.getElement(0,1) ;
      double w3 = W.getElement(0,2) ;

      double m = -(w1/w2);
      double b_ = -(w3/w2);

      std::cout << "Error :"<< error.getElement(0,0)*error.getElement(0,0) << std::endl;
      std::cout << "M :"<< m << " B :"<< b_ << std::endl;

}
*/
    return 0;
}
