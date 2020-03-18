#include "node.hpp"

Node::Node(int v) :
  left(nullptr),
  right(nullptr),
  value(v)
{}

Node::~Node() {
  delete left ;
  delete right ;
}
