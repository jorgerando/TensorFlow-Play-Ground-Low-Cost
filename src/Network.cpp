#include <iostream>
#include <vector>
#include <string>
#include "Network.hpp"

Network::Network( std::vector<int> dim_ , std::string act ){
  dim = dim_;
  layers = dim.size() ;
  activation = act ;
  Matrix _ = Matrix(1,1);
  deltas.resize(layers-1,_);
  WG.resize(layers-1,_);
}

void Network::builtNet(){

   Matrix x0 = Matrix(dim[0],1) ;
   X.push_back(x0);

   for (int i = 1 ; i < layers; i++){

       Matrix wi = Matrix(dim[i],dim[i-1]);
       wi.randomInitialization(-1,1);
       W.push_back(wi);

       Matrix xi = Matrix(dim[i],1);
       X.push_back(xi);

   }

}

void Network::showNet(){

  std::cout << "---- X0 ----" << std::endl;
  X[0].show();

  for (int i = 1 ; i < layers ; i++){
      std::cout << "---- W"<<i<<" ----" << std::endl;
      W[i-1].show();
      std::cout << "---- X"<<i<<" ----" << std::endl;
      X[i].show();
  }

}

Matrix Network::forward(Matrix data){

  if (data.sameDim(X[0])){
    X[0] = data ;
  }else{
     throw std::runtime_error("Data bat dimesion");
  }

  for (int i = 1 ; i < layers  ; i++){

      Matrix wi = W[i-1] ;
      X[i] = wi.mult(X[i-1]).aplayFuntion(functions[activation]) ;
      //std::cout << "-------------------- " << std::endl;
      //X[i].show();
  }

  return X[layers -1] ;
}

Matrix Network::error(Matrix pre , Matrix target){

  if (! target.sameDim(pre) ){
     throw std::runtime_error("Pre and target bat dimesion");
  }

  Matrix sub_1 = pre.sub(target) ;
  Matrix sub_2 = sub_1.copy() ;

  return sub_1.mulByTerms(sub_2);

}

void Network::calcGradients(Matrix pre, Matrix target){

  if (! target.sameDim(pre) ){
     throw std::runtime_error("Pre and target bat dimesion");
  }

  Matrix xl = X[ X.size() - 2 ]; // xl-1
  Matrix Wl = W[ W.size() - 1 ]; // Wl

  //deltaL = (xl - t) . f'( Wl * xl-1 )
  Matrix sub = pre.sub(target);
  double errorj = sub.getElement(0,0);
  Matrix deltaL = Wl.mult(xl).aplayFuntion(derivative[activation]).scalarMultiply(errorj) ;
  deltas[deltas.size() - 1] = deltaL ;
  //deltas.insert(deltas.begin() + deltas.size() - 1, deltaL);

  //std::cout << "----------DELTA-L--------"<< std::endl;
  // G(E/Wi) = deltai * xi^T
  Matrix Gwl = deltaL.mult( X[X.size()-2].transpose() );
  //Gwl.show();
  WG[ WG.size() - 1] = Gwl ;
  //WG.insert(WG.begin() + WG.size() - 1, Gwl);

  for(int i = W.size()-2 ; i >= 0 ; i--){

      // deltai = ( Wi+1^T * deltai+1 ) . f'(Wi*xi-1)
      Matrix Wi = W[i] ; // Wi
      Matrix deltai_1 = deltas[i+1]; //deltai+1
      Matrix Wi_1 = W[i+1] ; // Wi+1
      Matrix xi_1_ = X[i] ; //Xi-1 ( Pongo i por X tiene un elemento mas que W AHAHAH)
      Matrix deltai = Wi_1.transpose().mult(deltai_1).mulByTerms( Wi.mult(xi_1_).aplayFuntion(derivative[activation]) );

      //deltas.insert(deltas.begin() + i, deltai);
      deltas[i] = deltai ;
      //deltai.show();
      //std::cout << "-------------"<< std::endl;
      // G(E/Wi) = deltai * xi^T
      Matrix Gwi = deltai.mult( X[i].transpose() );
      WG[i] = Gwi ;
      //Gwi.show();
      //WG.insert(WG.begin() + i , Gwi);

  }



}

void Network::updateWeights(double alfa){
  //std::cout << "------ggg-------"<< std::endl;
  for(int i = 0 ; i < deltas.size() ; i++ ){
     Matrix upi = W[i].copy().sub( WG[i].scalarMultiply(alfa) );
     W[i] = upi ;
     //W[i].show();
     //std::cout << "-------------"<< std::endl;
  }

}
