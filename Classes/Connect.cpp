//
// Created by ilyaw on 23.10.2016.
//

#include "Connect.h"
#include <iostream>

using namespace std;

int Connect::getIndex1() const {
    return this->_index1;
}

int Connect::getIndex2() const {
    return this->_index2;
}


Connect::Connect() {

}

Connect::Connect(int index1, int index2) {
    _index1 = index1;
    _index2 = index2;

}

void Connect::printConnect() {
    cout << "(" << this->getIndex1() << ")->(" << this->getIndex2() << ")" << endl;
}

void Connect::scanConnect() {
    cout<<"(index1,index2)"<<endl;
    int index1,index2;
    scanf("%d%d",&index1,&index2);
    this->_index1 = index1;
    this->_index2 = index2;

}

