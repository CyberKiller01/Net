#include "Atribut.h"


using namespace std;

Atribut::Atribut(Type t, const char *n, void *v, const char *d) {

    _name = new char[1000];
    _description = new char[1000];
    Add(t, n, v, d);
}

void Atribut::Add(Type t, const char *n, void *v, const char *d)//Парсинг строки для дальнейшего занесения в атрибут
{
    this->_type = t;
    strcpy(this->_name, n);
    this->_value = v;
    strcpy(this->_description, d);
}

Type Atribut::getType() {
    return Type();
}

string Atribut::getName() {
    return this->_name;
}

/*int Atribut::getVariableInt() {
    return (this->_type == Type::Int) ? this->_int : 0;//Если тип данных Int , то овзвращаем значение иначе 0
}

char Atribut::getVariableChar() {
    return (this->_type != Type::Char) ? (char) 0 : this->_char;//Если тип данных Char , то возвращаем значение иначе 0
}

double Atribut::getVariableDouble() {
    return (this->_double != Double) ? 0 : this->_double;//Если тип данных Double , то возвращаем значение иначе 0
}
*/
string Atribut::getTypetoString() {
    switch (this->_type) {
        case Type::Int:
            return "int";
        case Type::Double:
            return "double";
        case Type::Char:
            return "char";
        default:
            return "\0";
    }
}

string Atribut::getDescription() {
    return _description;
}

void *Atribut::getValue() {
    return this->_value;
}

void Atribut::printAtribute() {

    cout << this->getTypetoString();
    cout << " ";
    cout << this->getName();
    cout << " = ";
    cout << this->getValue();
    cout << " ; //";
    cout << this->getDescription();
    cout << endl;
}

Atribut::~Atribut() {
    delete _name;
    delete _description;
}

Atribut &Atribut::operator=(const Atribut &right) {


    //проверка на самоприсваивание
    if (this == &right) {
        return *this;
    }
    this->_type = right._type;
    this->_value = right._value;
    strcpy(this->_name, right._name);
    strcpy(this->_description, right._description);
    return *this;


}

void Atribut::scanAtribute() {

    cout << "(type name = value;//description)" << endl;
    char name[1000];
    char type[1000];
    int *value = new int;
    char description[1000];

    scanf("%s %s = %d;//%s", type, name, value, description);
    this->_type = Int;
    strcpy(this->_name, name);
    this->_value = (void *) value;

}

