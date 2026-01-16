#include "Depot.h"
#include <iostream>

Depot::Depot()
    : head(nullptr),
      queueFront(nullptr),
      queueRear(nullptr),
      stackTop(nullptr) {}

//vector

void Depot::addDroneToFleet(Drone* drone) {
    if (!drone) return;
    fleet.push_back(drone);
}

Drone* Depot::getFleetDrone(std::size_t index) const {
    if (index < fleet.size()) return fleet[index];
    return nullptr;
}

std::size_t Depot::getFleetSize() const {
    return fleet.size();
}

//linked list
// Insert by ascending ID

void Depot::addDroneToLinkedList(Drone* drone) {
    if (!drone) return;

    // If list is empty or new drone ID is smallest
    if (!head || drone->getID() < head->getID()) {
        drone->setNextDrone(head);
        head = drone;
        return;
    }

    Drone* current = head;
    while (current->getNextDrone() &&
           current->getNextDrone()->getID() < drone->getID()) {
        current = current->getNextDrone();
    }

    drone->setNextDrone(current->getNextDrone());
    current->setNextDrone(drone);
}

bool Depot::removeDroneFromLinkedList(int id) {
    if (!head) return false;

    // Remove at head
    if (head->getID() == id) {
        Drone* toRemove = head;
        head = head->getNextDrone();
        toRemove->setNextDrone(nullptr);
        return true;
    }

    Drone* prev = head;
    Drone* curr = head->getNextDrone();

    while (curr) {
        if (curr->getID() == id) {
            prev->setNextDrone(curr->getNextDrone());
            curr->setNextDrone(nullptr);
            return true;
        }
        prev = curr;
        curr = curr->getNextDrone();
    }

    return false;
}

void Depot::printLinkedList() const {
    std::cout << "Linked List (by ID):\n";
    Drone* current = head;
    while (current) {
        std::cout << "ID: " << current->getID()
                  << ", Name: " << current->getName() << "\n";
        current = current->getNextDrone();
    }
    std::cout << "---------------------------\n";
}

//Fifo

void Depot::enqueueDrone(Drone* drone) {
    if (!drone) return;
    drone->setNextDrone(nullptr);

    if (!queueRear) {
        // empty queue
        queueFront = queueRear = drone;
    } else {
        queueRear->setNextDrone(drone);
        queueRear = drone;
    }
}

Drone* Depot::dequeueDrone() {
    if (!queueFront) return nullptr;

    Drone* front = queueFront;
    queueFront = queueFront->getNextDrone();

    if (!queueFront) {
        queueRear = nullptr;
    }

    front->setNextDrone(nullptr);
    return front;
}

void Depot::printQueue() const {
    std::cout << "Queue (dispatch order):\n";
    Drone* current = queueFront;
    while (current) {
        std::cout << "ID: " << current->getID()
                  << ", Name: " << current->getName() << "\n";
        current = current->getNextDrone();
    }
    std::cout << "---------------------------\n";
}

//stack LIFO

void Depot::pushDrone(Drone* drone) {
    if (!drone) return;
    drone->setNextDrone(stackTop);
    stackTop = drone;
}

Drone* Depot::popDrone() {
    if (!stackTop) return nullptr;

    Drone* top = stackTop;
    stackTop = stackTop->getNextDrone();
    top->setNextDrone(nullptr);
    return top;
}

void Depot::printStack() const {
    std::cout << "Stack (maintenance order):\n";
    Drone* current = stackTop;
    while (current) {
        std::cout << "ID: " << current->getID()
                  << ", Name: " << current->getName() << "\n";
        current = current->getNextDrone();
    }
    std::cout << "---------------------------\n";
}

//spatial tree

void Depot::insertDroneSpatial(Drone* drone) {
    if (!drone) return;
    spatialTree.insert(drone);
}

Drone* Depot::searchDroneByCoord(int x, int y) const {
    return spatialTree.search(x, y);
}

void Depot::traverseSpatialInOrder() const {
    spatialTree.traverseInOrder();
}

void Depot::traverseSpatialPreOrder() const {
    spatialTree.traversePreOrder();
}

void Depot::traverseSpatialPostOrder() const {
    spatialTree.traversePostOrder();
}

double Depot::computeDistance(int x1, int y1, int x2, int y2) const {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx*dx + dy*dy);
}

void Depot::insertDynamicTask(Drone* d, const std::string& task, int x, int y) {
    if (!d) {
        std::cout << "ERROR: Null drone.\n";
        return;
    }
    
    if (!d->canInsertDynamicTask()) {
        std::cout << "Drone already used its one-time bonus task insertion.\n";
        return;
    }
    
    // Find best insertion slot among 5 tasks
    int bestIndex = 0;
    double bestCost = 1e9;
    
    int baseX = d->getInitPosition(0);
    int baseY = d->getInitPosition(1);
    
    for (int i = 0; i < 5; i++) {
        double oldCost = computeDistance(baseX, baseY,
                                         d->getTaskPosition(i,0),
                                         d->getTaskPosition(i,1));
        
        double newCost = computeDistance(baseX, baseY, x, y);
        double diff = newCost - oldCost;
        
        if (diff < bestCost) {
            bestCost = diff;
            bestIndex = i;
        }
    }
    
    // Perform task replacement
    d->setTask(bestIndex, task);
    d->setTaskPosition(bestIndex, x, y);
    
    // Record the insertion
    d->recordDynamicInsertion(bestIndex, bestCost);
    
    std::cout << "\nDynamic task inserted at index " << bestIndex
    << " with cost change = " << bestCost << "\n";
    
}


