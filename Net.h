/*#ifndef NET_H
#define NET_H*/

#include"Classes/Node.h"
#include"Classes/List.h"
#include"Classes/Atribut.h"
#include "Classes/Connect.h"

/*typedef struct _Connect {
    uint64_t index1, index2;

} Connect ;*/


class Net {

public:
    Net();

    ~Net();


    void addAtribute(Type t,const char *n,void *v,const char* d);

    void addNode(Node *node);

    void addConnection(Connect *c);

    /*Получение списков*/
    List *get_atribute() const;

    List *get_node() const;

    List *get_connects() const;

    /*Ввод и вывод матрицы*/
    void printNet();
    void scanNet();


    Net& operator=(const Net& right);

private:
    List *_atribute, *_node, *_connects;
};



class ConnectProiz:public Connect
{
public:
    ConnectProiz(int index1,int index2,int value);
    int getValue() const;
    void printConnect();

protected:
    int _value;
};