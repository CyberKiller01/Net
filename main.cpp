#include"stdafx.h"
#include<algorithm>


using namespace std;

bool match(int N, int **A, int **B, int P[]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (A[i][j] != B[P[i]][P[j]])
                return false;
    return true;
}


bool isIsomorph(Net *net1, Net *net2) {

    int size = net1->get_node()->getSize();
    int size1 = net2->get_node()->getSize();

    if (size != size1)
        return false;

    int **G1 = new int *[size];
    int **G2 = new int *[size];
    for (int i = 0; i < size; i++) {
        G1[i] = new int[size];
        G2[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            G1[i][j] = 0;
            G2[i][j] = 0;
        }

    int N = net1->get_connects()->getSize();
    for (int i = 0; i <= N; i++) {
        Connect *c = (Connect *) net1->get_connects()->getNthq(i)->value;
        int ind1 = c->getIndex1();
        int ind2 = c->getIndex2();
        G1[ind1][ind2] = 1;
    }
    N = net2->get_connects()->getSize();
    for (int i = 0; i < N; i++) {
        Connect *c = (Connect *) net2->get_connects()->getNthq(i)->value;
        G2[c->getIndex1()][c->getIndex2()] = 1;
    }
    int *P = new int[size];
    for (int i = 0; i < size; i++)
        P[i] = i;

    do {
        if (match(size, G1, G2, P)) return true;
    } while (next_permutation(P, P + size));

    return false;
}


int main() {
    Net *net = new Net();
    int value = 2;

    net->addAtribute(Int, "size", &value, "Кол-во узлов");
    net->scanNet();

    /*NodeNsled *node01 = new NodeNsled(0, 5);
    NodeNsled *node1 = new NodeNsled(1, 5);
    NodeNsled *node2 = new NodeNsled(2, 3);

    net->addNode(node01);
    net->addNode(node1);
    net->addNode(node2);

    ConnectProiz *c1 = new ConnectProiz(1, 2, 4);
    ConnectProiz *c2 = new ConnectProiz(2, 1, 4);


    net->addConnection(c1);
    net->addConnection(c2);

    net->printNet();*/

    Net *net2 = new Net();
    net2->addAtribute(Int, "size", &value, "Кол-во узлов");

    net2->scanNet();

    /*Node *node11 = new Node(0);
    Node *node12 = new Node(1);
    Node *node13 = new Node(2);

    net2->addNode(node11);
    net2->addNode(node12);
    net2->addNode(node13);

    Connect *c11 = new Connect(1, 2);
    Connect *c22 = new Connect(2, 1);
    net2->addConnection(c11);
    net2->addConnection(c22);*/

    if (isIsomorph(net, net2))
        cout << "TRUE";
    else
        cout << "FALSE";



    //printfNet(net);

    delete net;
    delete net2;

    return 0;
}