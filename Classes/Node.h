//
// Created by ilyaw on 11.10.2016.
//

#ifndef NET_NODE_H
#define NET_NODE_H

#include <cstdint>


class Node {

protected:
    uint64_t _index;

public:
    Node(uint64_t index);
    Node();

    ~Node();

    uint64_t get_index() const;

    virtual void printNode();

    virtual void scanNode();
};
#endif //NET_NODE_H
