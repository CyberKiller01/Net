//
// Created by ilyaw on 11.10.2016.
//

#include "Node.h"
#include <iostream>

using namespace std;

uint64_t Node::get_index() const {
    return _index;
}

Node::Node() {

}

Node::Node(uint64_t index) {

    this->_index = index;
}

Node::~Node() {

}

void Node::printNode() {
    cout << "(" << this->get_index() << ")" << endl;
}

void Node::scanNode() {
    printf("(index)\n");
    uint64_t index;
    scanf("%d", &index);
    this->_index = index;
}


