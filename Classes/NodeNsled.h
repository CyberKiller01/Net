//
// Created by ilyaw on 19.10.2016.
//

#ifndef NET_NODENSLED_H
#define NET_NODENSLED_H
#include"Node.h"
#include<iostream>

using namespace std;


class NodeNsled: public Node {

public:

    NodeNsled(int index,int value);
    ~NodeNsled();
    int get_value() const;

    void printNode() {
        cout<<"("<<this->get_index()<<" , "<<this->get_value()<<" )"<<endl;
    }

    void scanfNode(){
        cout << "((index,value))";
        uint64_t index;
        int value;
        scanf("(%lld,%d)", &index,&value);
        this->_index = index;
        this->_value = value;

    }
private:
    int _value;

};


#endif //NET_NODENSLED_H
