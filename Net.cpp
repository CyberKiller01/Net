//
// Created by ilyaw on 15.10.2016.
//

#include "Net.h"

Net::Net() {
    _atribute = new List();
    _node = new List();
    _connects = new List();

}

Net::~Net() {
    delete _atribute;
    delete _connects;
    delete _node;

}


void Net::addAtribute(Type t,const char *n,void *v,const char* d) {
    Atribut *a = new Atribut(t,n,v,d);
    _atribute->pushBack(a);
}

void Net::addNode(Node *node) {
    _node->pushBack(node);
}

void Net::addConnection(Connect *c) {
    //Connect *c = new Connect(index1,index2);
    _connects->pushBack(c);
}

List *Net::get_atribute() const {
    return _atribute;
}

List *Net::get_node() const {
    return _node;
}

List *Net::get_connects() const {
    return _connects;
}

void Net::printNet()
{
    cout<<"Atributes: "<<endl;

    size_t atrSize = this->get_atribute()->getSize();// получаем кол-во атрибутов
    for(int i = 0; i< atrSize; i++){
        Atribut *atr = (Atribut*)this->get_atribute()->getNthq(i)->value;//получаем список Atribute-> получаем элемент по id -> получаем значение
        atr->printAtribute();//печатаем Atribut
    }
    //Дальше Анологично для Node и Connect
    cout<<"Nodes: "<<endl;

    size_t nodeSize = this->get_node()->getSize();
    for(int i=0; i < nodeSize; i++) {
        Node *node = (Node *) this->get_node()->getNthq(i)->value;
        node->printNode();
    }
    cout<<"Connetions: "<<endl;

    size_t conSize = this->get_connects()->getSize();
    for(int i = 0; i < conSize; i++){
        Connect *con = (Connect*)this->get_connects()->getNthq(i)->value;
        con->printConnect();
    }

}

Net &Net::operator=(const Net &right) {
        //проверка на самоприсваивание
        if (this == &right) {
            return *this;
        }
        _atribute = right._atribute;
        _node = right._node;
        _connects = right._connects;
        return *this;

}

void Net::scanNet() {
    int Nnode = 0 ;
    cout<<"Node(кол-во): ";
    cin>>Nnode;
    for(int i = 0 ; i < Nnode; i++){
        Node *node = new Node();
        node->scanNode();
        this->addNode(node);
    }
    int Ncon = 0 ;
    cout<<"Connection(кол-во): ";
    cin>>Ncon;

    for(int i = 0 ; i < Ncon; i++){
        Connect *con = new Connect();
        con->scanConnect();
        this->addConnection(con);
    }



}

/*-------------------------------------------------------------------------------------------*/


int ConnectProiz::getValue() const {
    return _value;
}

ConnectProiz::ConnectProiz(int index1, int index2, int value):Connect(index1,index2) {
    _value=value;

}

void ConnectProiz::printConnect() {
    Connect::printConnect();
    cout<<this->getValue()<<endl;
}
