//
// Created by ilyaw on 23.10.2016.
//

#ifndef NET_CONNECT_H
#define NET_CONNECT_H


class Connect {
protected:
    int _index1, _index2;

public:

    Connect();

    Connect(int index1, int index2);

    int getIndex1() const;

    int getIndex2() const;

    virtual void printConnect();

    virtual void scanConnect();

};


#endif //NET_CONNECT_H
