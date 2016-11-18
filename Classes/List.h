//
// Created by ilyaw on 08.10.2016.
//

#ifndef NET_LIST_H
#define NET_LIST_H

#include<iostream>
#include <malloc.h>

/*Структуры для списка*/
typedef struct _Unit {
    void *value;
    struct _Unit *next;
    struct _Unit *prev;
} Unit;

typedef struct _DblLinkedList {
    size_t size;
    Unit *head;
    Unit *tail;
} DblLinkedList;

/*-------------------------------*/

class List {
public:
    List();

    List(void *value);

    ~List();


    /*Функции создания и удаления двусвязного списка*/
    DblLinkedList *createDblLinkedList();

    void deleteDblLinkedList();
    /*-------------------------------------------*/

    /*Функции для работы с головой и последним элементом*/
    void pushFront(void *data);

    void *popFront();

    void pushBack(void *value);

    void *popBack();


    /*Функции для вставки и удаления в производное место*/
    Unit *getNth(size_t index);

    Unit *getNthq(size_t index);

    void insert(size_t index, void *value);

    void *deleteNth(size_t index);

    /*-------------------------------------------------------*/
    size_t getSize(void);

    List &operator=(const List &right);

private:
    //Unit _unit;
    DblLinkedList *_dbLink;


};


#endif //NET_LIST_H
