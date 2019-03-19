#include "arbre.hpp"

Arbre::Arbre() : 
  racine(nullptr)
{}

Arbre::~Arbre() {
  delete racine ;
}

static Noeud* inserer_noeud(Noeud* n, int v) {
  if(n) {
    if(v > n->valeur) {
      n->droite = inserer_noeud(n->droite, v) ;
    } else {
      n->gauche = inserer_noeud(n->gauche, v) ;
    }
    return n ;
  } else {
    return new Noeud(v) ;
  }
}

void Arbre::inserer(int v) {
  racine = inserer_noeud(racine, v) ;
}
