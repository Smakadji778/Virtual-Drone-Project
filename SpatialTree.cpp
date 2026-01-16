#include "SpatialTree.h"
#include <iostream>

SpatialTree::SpatialTree() : root(nullptr) {}

SpatialTree::~SpatialTree() {
    clear(root);
}

void SpatialTree::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

void SpatialTree::insert(Drone* drone) {
    insert(root, drone);
}

void SpatialTree::insert(Node*& node, Drone* drone) {
    if (!node) {
        node = new Node(drone);
        return;
    }

    int x = getX(drone);
    int y = getY(drone);
    int nx = getX(node->drone);
    int ny = getY(node->drone);

    if (x < nx || (x == nx && y < ny)) {
        insert(node->left, drone);
    } else {
        insert(node->right, drone);
    }
}

Drone* SpatialTree::search(int x, int y) const {
    return search(root, x, y);
}

Drone* SpatialTree::search(Node* node, int x, int y) const {
    if (!node) return nullptr;

    int nx = getX(node->drone);
    int ny = getY(node->drone);

    if (x == nx && y == ny) {
        return node->drone;
    }

    if (x < nx || (x == nx && y < ny)) {
        return search(node->left, x, y);
    } else {
        return search(node->right, x, y);
    }
}

void SpatialTree::traverseInOrder() const {
    traverseInOrder(root);
}

void SpatialTree::traversePreOrder() const {
    traversePreOrder(root);
}

void SpatialTree::traversePostOrder() const {
    traversePostOrder(root);
}

void SpatialTree::traverseInOrder(Node* node) const {
    if (!node) return;
    traverseInOrder(node->left);
    node->drone->displayDrone();
    traverseInOrder(node->right);
}

void SpatialTree::traversePreOrder(Node* node) const {
    if (!node) return;
    node->drone->displayDrone();
    traversePreOrder(node->left);
    traversePreOrder(node->right);
}

void SpatialTree::traversePostOrder(Node* node) const {
    if (!node) return;
    traversePostOrder(node->left);
    traversePostOrder(node->right);
    node->drone->displayDrone();
}
