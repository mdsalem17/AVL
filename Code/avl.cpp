#include "avl.hpp"

#include <iostream>

static int max(int a, int b) {
   return ((a > b) ? a : b);
}

static int height_noeud(Node* n) {
  if(n) return n-> height;
  else 
   return 0;
}

AVL::AVL() : 
  root(nullptr)
{}

AVL::~AVL() {
  delete root ;
}


Node* rotation_left(Node * n) {
  Node * tmp = n->right;
  n->right = tmp->left;
  tmp->left = n;

  n->height = 1 + max(height_noeud(n->left), height_noeud(n->right));
  tmp->height = 1 + max(height_noeud(tmp->left), height_noeud(tmp->right));

  return tmp;
}

Node* rotation_right(Node * n) {
  Node * tmp = n->left;
  n->left = tmp->right;
  tmp->right = n;

  n->height = 1 + max(height_noeud(n->left), height_noeud(n->right));
  tmp->height = 1 + max(height_noeud(tmp->left), height_noeud(tmp->right));

  return tmp;
}

static Node* insert_node(Node* n, int v) {
  if(n) {
    if(v > n->value) {
      n->right = insert_node(n->right, v) ;
    } else {
      n->left = insert_node(n->left, v) ;
    }

    n->height = 1 + max(height_noeud(n->right), height_noeud(n->left));

    int height = height_noeud(n->left) - height_noeud(n->right);

     // Déséquilibre à gauche de l'enfant gauche
     // Déséquilibre à left de l'enfant left
    if (height > 1 && v  < n->left->value){
        return rotation_right(n);
    }

    // Déséquilibre à droit de l'enfant gauche
    // Déséquilibre à right de l'enfant left
    if (height > 1 && v > n->left->value){  
        n->left = rotation_left(n->left);  
        return rotation_right(n);
    } 

    // Déséquilibre à droite de l'enfant droit
    // Déséquilibre à right de l'enfant right
    if (height < -1 && v > n->right->value){
        return rotation_left(n);
    }
  
    // Déséquilibre à gauche de l'enfant droit
    // Déséquilibre à left de l'enfant right
    if (height < -1 && v < n->right->value){  
        n->right = rotation_right(n->right);  
        return rotation_left(n);  
    }

    return n ;
  } else {
    return new Node(v) ;
  }
}

void AVL::insert(int v) {
  root = insert_node(root, v) ;
}


/**
*************************************************************************
*************************** Printing Features ***************************
*************************************************************************
**/
#ifndef AFFICHAGE_SIMPLE

static const char* SPLIT = "\xe2\x94\xa4" ;
static const char* V_BRANCH = "\xe2\x94\x82" ;
static const char* H_BRANCH = "\xe2\x94\x80" ;
static const char* UPPER_BRANCH = "\xe2\x95\xad" ;
static const char* LOWER_BRANCH = "\xe2\x95\xb0" ;

#else

static const char* SPLIT = "+" ;
static const char* V_BRANCH = "|" ;
static const char* H_BRANCH = "-" ;
static const char* UPPER_BRANCH = "+" ;
static const char* LOWER_BRANCH = "+" ;

#endif

static void afficher_Node(Node* n, int profondeur, int code) {
  int largeur = 5 ;
  if(n) {
    afficher_Node(n->right, profondeur+1, code*2+1) ;
    int i ;
    for(i = 0; i < profondeur-1; ++i) {
      if(((code >> (profondeur-i-1)) & 1 ) != ((code >> (profondeur-i-2)) & 1)) {
        std::cout << V_BRANCH;
      } else {
        std::cout << " " ;
      }
      for(int l = 0; l < largeur; ++l) {
        std::cout << " " ;
      }
    }
    if(code%2) {
      std::cout << UPPER_BRANCH ;
    } else {
      if(profondeur) {
        std::cout << LOWER_BRANCH ;
      }
    }
    if(profondeur) {
      for(int l = 0; l < largeur; ++l) {
        std::cout << H_BRANCH ;
      }
    }
    std::cout << SPLIT << n->value << " -- " << n->height << std::endl ;
    afficher_Node(n->left, profondeur+1, code*2) ;
  }
}

void AVL::afficher() {
    afficher_Node(root, 0, 0) ;

    std::cout<<std::endl<<"######### End of printing ############"<<std::endl<<std::endl;
}
