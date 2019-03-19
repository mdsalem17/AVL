#include "arbre.hpp"

Arbre::Arbre() : 
  racine(nullptr)
{}

Arbre::~Arbre() {
  delete racine ;
}
