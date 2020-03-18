#pragma once

#include "node.hpp"

class AVL {

  public :

    AVL() ;
    ~AVL() ;

    void insert(int value) ;
    void left_rotation();
    void right_rotation();
    void afficher() ;

  private :
    Node* root ;
} ;
