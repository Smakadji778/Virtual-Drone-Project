#ifndef DRONE_H
#define DRONE_H

#include <string>
#include <iostream>

class Drone {
private:
    std::string name;
    int ID;

    std::string tasks[5];
    int init_position[2];
    int task_positions[5][2];

    // Dynamic task insertion
    bool hasInsertedTask;       //allows one insersion
    int pendingInsertIndex;     //slot where dynamic task was inserted
    double pendingInsertCost;   // Distance cost

    // Linked list pointer
    Drone* nextDrone;

public:
    //constructor
    Drone();
    Drone(const std::string& n, int id, int init_x, int init_y);

    //linked list meth
    void setNextDrone(Drone* next);
    Drone* getNextDrone() const;

    //dynamic task
    bool canInsertDynamicTask() const {
        return !hasInsertedTask;
    }

    void recordDynamicInsertion(int idx, double cost) {
        hasInsertedTask = true;
        pendingInsertIndex = idx;
        pendingInsertCost = cost;
    }

    //getters
    std::string getName() const;
    int getID() const;
    std::string getTask(int index) const;
    int getInitPosition(int coord) const;
    int getTaskPosition(int task_index, int coord) const;

    //setters
    void setName(const std::string& n);
    void setID(int id);
    void setTask(int index, const std::string& t);
    void setInitPosition(int x, int y);
    void setTaskPosition(int index, int x, int y);

    //sort
    void sortByAscending();
    void sortByDescending();


    virtual void displayDrone() const;
    
    //operator
    void operator<<(const Drone& d);
    void operator-(Drone& d);

    // Needed for inheritance
    virtual ~Drone() = default;
};

#endif
