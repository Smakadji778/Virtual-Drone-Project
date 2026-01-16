#ifndef DEPOT_H
#define DEPOT_H

#include <vector>
#include <cstddef>
#include <string>
#include "Drone.h"
#include "SpatialTree.h"

class Depot {
private:
    // base storage
    std::vector<Drone*> fleet;

    // linked list
    Drone* head;

    // FIFO queue
    Drone* queueFront;
    Drone* queueRear;

    // LIFO stack
    Drone* stackTop;

    SpatialTree spatialTree;

public:
    Depot();

    // Vector functions
    void addDroneToFleet(Drone* drone);
    Drone* getFleetDrone(std::size_t index) const;
    std::size_t getFleetSize() const;

    // Linked List
    void addDroneToLinkedList(Drone* drone);
    bool removeDroneFromLinkedList(int id);
    void printLinkedList() const;

    // Queue dispatch
    void enqueueDrone(Drone* drone);
    Drone* dequeueDrone();
    void printQueue() const;

    // Stack (maintenance)
    void pushDrone(Drone* drone);
    Drone* popDrone();
    void printStack() const;

    // Spatial Tree
    void insertDroneSpatial(Drone* drone);
    Drone* searchDroneByCoord(int x, int y) const;
    void traverseSpatialInOrder() const;
    void traverseSpatialPreOrder() const;
    void traverseSpatialPostOrder() const;

    // ================================
    // BONUS – Dynamic Task Insertion
    // ================================
    double computeDistance(int x1, int y1, int x2, int y2) const;
    void insertDynamicTask(Drone* d, const std::string& task, int x, int y);
};

#endif
