#ifndef DRONEMANAGER_H
#define DRONEMANAGER_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
class DroneManager {
private:
    std::vector<T*> objects;

public:
    void addObject(T* obj) {
        objects.push_back(obj);
    }

    T* getObject(std::size_t index) {
        if (index < objects.size()) return objects[index];
        return nullptr;
    }

    std::size_t size() const { return objects.size(); }

    void sortDronesByName() {
        std::sort(objects.begin(), objects.end(),
                  [](T* a, T* b) {
                      return a->getName() < b->getName();
                  });
    }

    void sortDronesByID() {
        std::sort(objects.begin(), objects.end(),
                  [](T* a, T* b) {
                      return a->getID() < b->getID();
                  });
    }

    void sortDronesByPosition() {
        std::sort(objects.begin(), objects.end(),
                  [](T* a, T* b) {
                      int ax = a->getInitPosition(0);
                      int ay = a->getInitPosition(1);
                      int bx = b->getInitPosition(0);
                      int by = b->getInitPosition(1);
                      int da = ax*ax + ay*ay;
                      int db = bx*bx + by*by;
                      return da < db;
                  });
    }

    void randomizeDroneOrder() {
        if (objects.empty()) return;
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        for (int i = static_cast<int>(objects.size()) - 1; i > 0; --i) {
            int j = std::rand() % (i + 1);
            std::swap(objects[i], objects[j]);
        }
    }

    //assume the name for binary search
    int searchDroneByName(const std::string& name) const {
        int left = 0;
        int right = static_cast<int>(objects.size()) - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            const std::string& midName = objects[mid]->getName();

            if (midName == name) return mid;
            if (midName < name)   left = mid + 1;
            else                  right = mid - 1;
        }
        return -1;
    }

    //sorted by ID
    int searchDroneByID(int id) const {
        int left = 0;
        int right = static_cast<int>(objects.size()) - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int midID = objects[mid]->getID();

            if (midID == id) return mid;
            if (midID < id)  left = mid + 1;
            else             right = mid - 1;
        }
        return -1;
    }

    void printAllDroneNames() const {
        std::cout << "All drone names:\n";
        for (std::size_t i = 0; i < objects.size(); ++i) {
            std::cout << i << ": " << objects[i]->getName() << "\n";
        }
        std::cout << "---------------------------\n";
    }
};

#endif
