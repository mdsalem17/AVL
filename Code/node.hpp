#pragma once

struct Node {
  Node(int value) ;
  ~Node() ;

  Node* left ;
  Node* right ;
  int height = 1;
  int value ;
} ;
