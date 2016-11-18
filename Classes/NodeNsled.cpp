//
// Created by ilyaw on 19.10.2016.
//

#include "NodeNsled.h"

NodeNsled::NodeNsled(int index, int value):Node(index) {
    _value = value;
}

/*NodeNsled::~NodeNsled(): ~Node() {


}*/

int NodeNsled::get_value() const {
    return _value;
}
