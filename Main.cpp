#include <iostream>
#include <string>
#include "Drone.h"
#include "AdvancedDrone.h"
#include "Depot.h"
#include "DroneManager.h"

using namespace std;

//Interact with drone
Drone* createBasicDrone() {
    string name;
    int id, x, y;

    cout << "Enter Drone Name: ";
    cin >> name;

    cout << "Enter Drone ID: ";
    cin >> id;

    cout << "Enter Initial X position: ";
    cin >> x;

    cout << "Enter Initial Y position: ";
    cin >> y;

    return new Drone(name, id, x, y);
}

//the advance drone
AdvancedDrone* createAdvancedDrone() {
    string name;
    int id, x, y;
    float battery;

    cout << "Enter Advanced Drone Name: ";
    cin >> name;

    cout << "Enter Drone ID: ";
    cin >> id;

    cout << "Enter Initial X position: ";
    cin >> x;

    cout << "Enter Initial Y position: ";
    cin >> y;

    cout << "Enter Battery Level (0–100): ";
    cin >> battery;

    return new AdvancedDrone(name, id, x, y, battery);
}

int main() {
    Depot depot;
    DroneManager<Drone> manager;

    int choice;

    while (true) {
        cout << "\n======== SkyRoute-II: Drone Control Network ========\n";
        cout << "1. Add Basic Drone\n";
        cout << "2. Add Advanced Drone\n";
        cout << "3. Show Fleet (vector)\n";
        cout << "4. Register Drone (Linked List)\n";
        cout << "5. Show Registered Drones (Linked List)\n";
        cout << "6. Remove Drone from Linked List\n";
        cout << "7. Queue: Enqueue Drone\n";
        cout << "8. Queue: Dequeue Drone\n";
        cout << "9. Stack: Push Drone\n";
        cout << "10. Stack: Pop Drone\n";
        cout << "11. Spatial Tree: Insert Drone\n";
        cout << "12. Spatial Tree: Search by Coordinates\n";
        cout << "13. Spatial Tree Traversal (In-Order)\n";
        cout << "14. Spatial Tree Traversal (Pre-Order)\n";
        cout << "15. Spatial Tree Traversal (Post-Order)\n";
        cout << "16. Sort Fleet by Name\n";
        cout << "17. Sort Fleet by ID\n";
        cout << "18. Sort Fleet by Position\n";
        cout << "19. Randomize Fleet Order\n";
        cout << "20. Print All Fleet Names\n";
        cout << "21. Search Drone by Name (Binary Search)\n";
        cout << "22. Search Drone by ID (Binary Search)\n";
        cout << "23. assign a task\n";
        cout << "24. Insert Dynamic Task Into Drone\n";
        cout << "25. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << "\n";

        if (choice == 25) break;

        switch (choice) {
                
        //choose what drone you want basic or advanced.
                
        case 1: {
            Drone* d = createBasicDrone();
            depot.addDroneToFleet(d);
            manager.addObject(d);
            cout << "Basic Drone Added!\n";
            break;
        }

        case 2: {
            AdvancedDrone* d = createAdvancedDrone();
            depot.addDroneToFleet(d);
            manager.addObject(d);
            cout << "Advanced Drone Added!\n";
            break;
        }

            
        //vector
        case 3: {
            cout << "\n--- Fleet Drones ---\n";
            for (size_t i = 0; i < depot.getFleetSize(); i++) {
                depot.getFleetDrone(i)->displayDrone();
            }
            break;
        }
        
        //linked list
        case 4: {
            int index;
            cout << "Enter fleet index of drone to register: ";
            cin >> index;

            Drone* d = depot.getFleetDrone(index);
            if (!d) cout << "Invalid index.\n";
            else {
                depot.addDroneToLinkedList(d);
                cout << "Drone registered via Linked List!\n";
            }
            break;
        }

        case 5:
            depot.printLinkedList();
            break;

        case 6: {
            int id;
            cout << "Enter ID to remove from linked list: ";
            cin >> id;
            if (depot.removeDroneFromLinkedList(id))
                cout << "Removed successfully.\n";
            else
                cout << "ID not found.\n";
            break;
        }

        //stack
        case 7: {
            int index;
            cout << "Enter fleet index of drone to enqueue: ";
            cin >> index;

            Drone* d = depot.getFleetDrone(index);
            if (!d) cout << "Invalid index.\n";
            else {
                depot.enqueueDrone(d);
                cout << "Drone Enqueued!\n";
            }
            break;
        }

        case 8: {
            Drone* d = depot.dequeueDrone();
            if (!d) cout << "Queue empty.\n";
            else {
                cout << "Dequeued:\n";
                d->displayDrone();
            }
            break;
        }

        case 9: {
            int index;
            cout << "Enter fleet index of drone to push onto stack: ";
            cin >> index;

            Drone* d = depot.getFleetDrone(index);
            if (!d) cout << "Invalid index.\n";
            else {
                depot.pushDrone(d);
                cout << "Drone pushed to stack.\n";
            }
            break;
        }

        case 10: {
            Drone* d = depot.popDrone();
            if (!d) cout << "Stack empty.\n";
            else {
                cout << "Popped from stack:\n";
                d->displayDrone();
            }
            break;
        }

        //spatial tree
        case 11: {
            int index;
            cout << "Enter fleet index of drone to add to spatial tree: ";
            cin >> index;

            Drone* d = depot.getFleetDrone(index);
            if (!d) cout << "Invalid index.\n";
            else {
                depot.insertDroneSpatial(d);
                cout << "Drone inserted into spatial tree.\n";
            }
            break;
        }

        case 12: {
            int x, y;
            cout << "Enter x and y: ";
            cin >> x >> y;
            Drone* d = depot.searchDroneByCoord(x, y);
            if (!d) cout << "No drone found at those coordinates.\n";
            else d->displayDrone();
            break;
        }

        case 13:
            cout << "\n--- Spatial Tree In-Order ---\n";
            depot.traverseSpatialInOrder();
            break;

        case 14:
            cout << "\n--- Spatial Tree Pre-Order ---\n";
            depot.traverseSpatialPreOrder();
            break;

        case 15:
            cout << "\n--- Spatial Tree Post-Order ---\n";
            depot.traverseSpatialPostOrder();
            break;

        //sorting/searching
        case 16:
            manager.sortDronesByName();
            cout << "Fleet sorted by Name.\n";
            break;

        case 17:
            manager.sortDronesByID();
            cout << "Fleet sorted by ID.\n";
            break;

        case 18:
            manager.sortDronesByPosition();
            cout << "Fleet sorted by position.\n";
            break;

        case 19:
            manager.randomizeDroneOrder();
            cout << "Fleet order randomized.\n";
            break;

        case 20:
            manager.printAllDroneNames();
            break;

        case 21: {
            string name;
            cout << "Enter name: ";
            cin >> name;
            int idx = manager.searchDroneByName(name);
            if (idx == -1) cout << "Name not found.\n";
            else depot.getFleetDrone(idx)->displayDrone();
            break;
        }

        case 22: {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            int idx = manager.searchDroneByID(id);
            if (idx == -1) cout << "ID not found.\n";
            else depot.getFleetDrone(idx)->displayDrone();
            break;
        }
        
        case 23: {
            int fleetIdx, taskIdx, x, y;
            string t;

            cout << "Enter fleet index of drone: ";
            cin >> fleetIdx;

            Drone* d = depot.getFleetDrone(fleetIdx);
            if (!d) {
                cout << "Invalid index.\n";
                break;
            }

            cout << "Enter task index (0–4): ";
            cin >> taskIdx;

            cout << "Enter task name: ";
            cin >> t;

            cout << "Enter task x position: ";
            cin >> x;

            cout << "Enter task y position: ";
            cin >> y;

            d->setTask(taskIdx, t);
            d->setTaskPosition(taskIdx, x, y);

            cout << "Task assigned successfully!\n";
            break;
        }
                
        case 24: {
            cout << "\n--- Dynamic Task Insertion (Bonus) ---\n";

            size_t idx;
            cout << "Enter fleet index of drone: ";
            
            cin >> idx;

            Drone* d = depot.getFleetDrone(idx);
                if (!d) {
                    cout << "Invalid drone index.\n";
                    break;
                }

            string taskName;
            int x, y;

            cout << "Enter NEW dynamic task name: ";
            cin >> taskName;

            cout << "Enter NEW task X coordinate: ";
            cin >> x;

            cout << "Enter NEW task Y coordinate: ";
            cin >> y;

            depot.insertDynamicTask(d, taskName, x, y);

                break;
            }

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
