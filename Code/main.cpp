#include "avl.hpp"

#include <random>

int main() {
  AVL a ;


  std::mt19937 alea ;

#ifndef DEBUG
  std::random_device vrai_alea ;
  alea.seed(vrai_alea()) ;
#endif

  std::uniform_int_distribution<int> nombre(0, 100) ;

  for(int i = 0; i < 15; ++i) {
    //a.insert(nombre(alea)) ;
    a.insert(i) ;
  }

  a.afficher() ;

  
  return 0 ;
}
