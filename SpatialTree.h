#ifndef SPATIALTREE_H
#define SPATIALTREE_H

#include "Drone.h"

class SpatialTree {
private:
    struct Node {
        Drone* drone;
        Node* left;
        Node* right;
        Node(Drone* d) : drone(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, Drone* drone);
    Drone* search(Node* node, int x, int y) const;
    void traverseInOrder(Node* node) const;
    void traversePreOrder(Node* node) const;
    void traversePostOrder(Node* node) const;
    void clear(Node* node);

    static int getX(Drone* d) { return d->getInitPosition(0); }
    static int getY(Drone* d) { return d->getInitPosition(1); }

public:
    SpatialTree();
    ~SpatialTree();

    void insert(Drone* drone);
    Drone* search(int x, int y) const;

    void traverseInOrder() const;
    void traversePreOrder() const;
    void traversePostOrder() const;
};

#endif
