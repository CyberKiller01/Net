//
// Created by ilyaw on 08.10.2016.
//

#include "List.h"


List::List() {

    this->_dbLink = createDblLinkedList();

}

List::List(void *value) {

    this->_dbLink = createDblLinkedList();
    pushFront(value);
}


List::~List() {

    deleteDblLinkedList();
}

DblLinkedList *List::createDblLinkedList() {

    DblLinkedList *tmp = (DblLinkedList *) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;

}

void List::deleteDblLinkedList() {
    Unit *tmp = (this->_dbLink)->head;
    Unit *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(this->_dbLink);
    //(*_dbLink) = 0;
}

void List::pushFront(void *data) {//положить в начале
    Unit *tmp = (Unit *) malloc(sizeof(Unit));//создается новый элемент
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = this->_dbLink->head;//привязываем к предыдущей бошке
    tmp->prev = NULL;//ставим предыдущий элемент нулевым
    if (this->_dbLink->head) {//если голова уже есть
        this->_dbLink->head->prev = tmp;//то старой бошке устанавливаем новый элемени как в переди идущий
    }
    this->_dbLink->head = tmp;//и за голову принимаем новый элемент

    if (this->_dbLink->tail == NULL) {//если и конец тоже равен нулю
        this->_dbLink->tail = tmp;//то принимаем его за голову
    }
    this->_dbLink->size++;//увеличиваем кол-во элементов на один
}

void *List::popFront() {//удалить в начале
    Unit *prev;//создаем указатель , для того , чтобы потом удалить узел
    void *tmp;
    if (this->_dbLink->head == NULL) {
        exit(2);
    }

    prev = this->_dbLink->head;
    this->_dbLink->head = this->_dbLink->head->next;//переопределяем голову
    if (this->_dbLink->head) {
        this->_dbLink->head->prev = NULL;
    }
    if (prev == this->_dbLink->tail) {
        this->_dbLink->tail = NULL;
    }
    tmp = prev->value;
    free(prev);//очищаем память

    this->_dbLink->size--;
    return tmp;
}

void List::pushBack(void *value) {//положить в конце
    Unit *tmp = (Unit *) malloc(sizeof(Unit));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = this->_dbLink->tail;
    if (this->_dbLink->tail) {
        this->_dbLink->tail->next = tmp;
    }
    this->_dbLink->tail = tmp;

    if (this->_dbLink->head == NULL) {
        this->_dbLink->head = tmp;
    }
    this->_dbLink->size++;

}

void *List::popBack() {//удалить с конца
    Unit *next;
    void *tmp;
    if (this->_dbLink->tail == NULL) {
        exit(4);
    }

    next = this->_dbLink->tail;
    this->_dbLink->tail = this->_dbLink->tail->prev;
    if (this->_dbLink->tail) {
        this->_dbLink->tail->next = NULL;
    }
    if (next == this->_dbLink->head) {
        this->_dbLink->head = NULL;
    }
    tmp = next->value;
    free(next);

    this->_dbLink->size--;
    return tmp;
}

Unit *List::getNth(size_t index) {//Получение n-го элемента
    Unit *tmp = this->_dbLink->head;
    size_t i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

Unit *List::getNthq(
        size_t index) {//Быстрый поиск элемента . Если index находится во второй половине списка, то обход идет с конца
    Unit *tmp = NULL;
    size_t i;

    if (index < this->_dbLink->size / 2) {
        i = 0;
        tmp = this->_dbLink->head;
        while (tmp && i < index) {
            tmp = tmp->next;
            i++;
        }
    } else {
        i = this->_dbLink->size - 1;
        tmp = this->_dbLink->tail;
        while (tmp && i > index) {
            tmp = tmp->prev;
            i--;
        }
    }

    return tmp;
}

void List::insert(size_t index, void *value) {
    Unit *elm = NULL;
    Unit *ins = NULL;
    elm = getNth(index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (Unit *) malloc(sizeof(Unit));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;

    if (!elm->prev) {
        this->_dbLink->head = elm;
    }
    if (!elm->next) {
        this->_dbLink->tail = elm;
    }

    this->_dbLink->size++;

}

void *List::deleteNth(size_t index) {
    Unit *elm = NULL;
    void *tmp = NULL;
    elm = getNth(index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;

    if (!elm->prev) {
        this->_dbLink->head = elm->next;
    }
    if (!elm->next) {
        this->_dbLink->tail = elm->prev;
    }

    free(elm);

    this->_dbLink->size--;

    return tmp;
}

size_t List::getSize(void) {
    return this->_dbLink->size;
}

List &List::operator=(const List &right) {

    //проверка на самоприсваивание
    if (this == &right) {
        return *this;
    }
    _dbLink = right._dbLink;
    return *this;


}





