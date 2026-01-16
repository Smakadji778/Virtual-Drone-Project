#include "Drone.h"
#include <algorithm>   // for std::swap

//constructors
Drone::Drone()
    : name(""),
      ID(0),
      nextDrone(nullptr),
      hasInsertedTask(false),
      pendingInsertIndex(-1),
      pendingInsertCost(0.0)
{
    init_position[0] = 0;
    init_position[1] = 0;

    for (int i = 0; i < 5; i++) {
        tasks[i] = "";
        task_positions[i][0] = 0;
        task_positions[i][1] = 0;
    }
}

Drone::Drone(const std::string& n, int id, int init_x, int init_y)
    : name(n),
      ID(id),
      nextDrone(nullptr),
      hasInsertedTask(false),
      pendingInsertIndex(-1),
      pendingInsertCost(0.0)
{
    init_position[0] = init_x;
    init_position[1] = init_y;

    for (int i = 0; i < 5; i++) {
        tasks[i] = "";
        task_positions[i][0] = 0;
        task_positions[i][1] = 0;
    }
}

//linked list meth
void Drone::setNextDrone(Drone* next) {
    nextDrone = next;
}

Drone* Drone::getNextDrone() const {
    return nextDrone;
}

//getters
std::string Drone::getName() const { return name; }
int Drone::getID() const { return ID; }

std::string Drone::getTask(int index) const {
    return (index >= 0 && index < 5) ? tasks[index] : "";
}

int Drone::getInitPosition(int coord) const {
    return (coord >= 0 && coord < 2) ? init_position[coord] : 0;
}

int Drone::getTaskPosition(int task_index, int coord) const {
    if (task_index >= 0 && task_index < 5 && coord >= 0 && coord < 2)
        return task_positions[task_index][coord];
    return 0;
}

//setters
void Drone::setName(const std::string& n) { name = n; }
void Drone::setID(int id) { ID = id; }

void Drone::setTask(int index, const std::string& t) {
    if (index >= 0 && index < 5)
        tasks[index] = t;
}

void Drone::setInitPosition(int x, int y) {
    init_position[0] = x;
    init_position[1] = y;
}

void Drone::setTaskPosition(int index, int x, int y) {
    if (index >= 0 && index < 5) {
        task_positions[index][0] = x;
        task_positions[index][1] = y;
    }
}

//sort
void Drone::sortByAscending() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (tasks[j] > tasks[j + 1]) {
                std::swap(tasks[j], tasks[j + 1]);
                std::swap(task_positions[j][0], task_positions[j + 1][0]);
                std::swap(task_positions[j][1], task_positions[j + 1][1]);
            }
        }
    }
}

void Drone::sortByDescending() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (tasks[j] < tasks[j + 1]) {
                std::swap(tasks[j], tasks[j + 1]);
                std::swap(task_positions[j][0], task_positions[j + 1][0]);
                std::swap(task_positions[j][1], task_positions[j + 1][1]);
            }
        }
    }
}

//display
void Drone::displayDrone() const {
    std::cout << "Drone Name: " << name << "\n";
    std::cout << "Drone ID: " << ID << "\n";
    std::cout << "Initial Position: (" << init_position[0]
              << ", " << init_position[1] << ")\n";

    std::cout << "Tasks:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "  Task " << i << ": " << tasks[i]
                  << " at (" << task_positions[i][0]
                  << ", " << task_positions[i][1] << ")\n";
    }

    if (hasInsertedTask) {
        std::cout << "Dynamic Insert → slot " << pendingInsertIndex
                  << " | cost = " << pendingInsertCost << "\n";
    }

    std::cout << "---------------------\n";
}

//operator overload
// Copy drone data
void Drone::operator<<(const Drone& d) {
    name = d.name;
    ID = d.ID;

    init_position[0] = d.init_position[0];
    init_position[1] = d.init_position[1];

    for (int i = 0; i < 5; i++) {
        tasks[i] = d.tasks[i];
        task_positions[i][0] = d.task_positions[i][0];
        task_positions[i][1] = d.task_positions[i][1];
    }

    hasInsertedTask = d.hasInsertedTask;
    pendingInsertIndex = d.pendingInsertIndex;
    pendingInsertCost = d.pendingInsertCost;
}

// Swap drone task data
void Drone::operator-(Drone& d) {
    for (int i = 0; i < 5; i++) {
        std::swap(tasks[i], d.tasks[i]);
        std::swap(task_positions[i][0], d.task_positions[i][0]);
        std::swap(task_positions[i][1], d.task_positions[i][1]);
    }

    std::swap(hasInsertedTask, d.hasInsertedTask);
    std::swap(pendingInsertIndex, d.pendingInsertIndex);
    std::swap(pendingInsertCost, d.pendingInsertCost);
}
