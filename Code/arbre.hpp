#pragma once

#include "noeud.hpp"

class Arbre {

  public :

    Arbre() ;
    ~Arbre() ;

    void inserer(int valeur) ;

  private :

    Noeud* racine ;
} ;
