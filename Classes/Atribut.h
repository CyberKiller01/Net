#pragma once

#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

enum Type//Перечисление типа переменной
{
    Int,
    Double,
    Char,

};


class Atribut {
public:

    Atribut(Type t, const char *n, void *v, const char *d);

    ~Atribut();


    void Add(Type t, const char *n, void *v, const char *d);//Парсинг строки для дальнейшего занесения в атрибут
    Type getType();

    string getName();

    void *getValue();

    /*int getVariableInt();

    char getVariableChar();

    double getVariableDouble();*/

    string getTypetoString();

    string getDescription();

    /*Ввод и вывод атрибутов*/
    void printAtribute();

    void scanAtribute();


    Atribut &operator=(const Atribut &right);


private:
    Type _type;//Описание типа
    char *_name;
    /*int _int;//Переменная для Int
    char _char;//Переменная для Char
    double _double;*/
    void* _value;
    char *_description;//описание атрибута


};