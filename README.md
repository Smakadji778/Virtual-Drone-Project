# Virtual-Drone-Project
SkyRoute-II: Drone Control Network System is a C++-based, menu-driven application for managing and optimizing a fleet of drones. The system supports adding, searching, sorting, manipulating drones, reordering tasks, and computing optimized flight routes using classical algorithms.

Team Member Contributions


Souleymane Makadji:


Depot Class:
Fleet (Vector)
Header file
addDroneToFleet(Drone* d)
getFleetDrone(int index)
getFleetSize()
displayAllDrones()
printAllNames()
randomizeOrder()
writeDepotToFile()


Linked List (Drone Registration System):
addDroneToLinkedList(Drone* d)
removeDroneFromLinkedList(int id)
printLinkedList()


Queue (FIFO Dispatch System):
enqueueDrone(Drone* d)
dequeueDrone()
printQueue()
Stack (LIFO Maintenance System):
pushDrone(Drone* d)
popDrone()
printStack()


Spatial Binary Tree (2D Drone Placement):
Integration of SpatialTree structure
insertDroneSpatial(Drone* d)
searchDroneByCoord(x, y)
traverseSpatialInOrder()
traverseSpatialPreOrder()
traverseSpatialPostOrder()
Task and Data Manipulation:
swapDroneData(int index1, int index2)
copyDrone(int index1, int index2)
insertDroneTask(...)
sortDroneDataAscending(int idx)
sortDroneDataDescending(int idx)
Route Optimization Algorithms:
implementLocalOptimumRoute()
implementGlobalOptimumRoute()
calculateDistance()
nearestNeighborTSP()
bruteForceTSP()
calculateRouteDistance()
writeOptimizedRoutesToFile()


BONUS – Dynamic Task Insertion Feature:
insertDynamicTask(Drone* d, const std::string& task, int x, int y)
computeDistance()
Optimal slot replacement based on cost analysis






Dean Kaushal:


Drone Class
Header file & full class definition
Constructors
Getters & Setters
sortByAscending()
sortByDescending()
displayDrone()
Operator overloading (<<, -)
Linked-list pointer integration (setNextDrone, getNextDrone)
Added virtual destructor & support for inheritance


Advanced Drone:
Derived class implementation
Overridden displayDrone()
Extended behavior for task handling (polymorphism)
Search & Sorting:
sortByName()
sortByID()
sortByPosition()
searchDroneByName(std::string& name)
searchDroneByID(int id)


Template Programming:
DroneManager<T> template class
Generic add, retrieve, sort functionality


Main Class:
The interactive menu functions:
displayMenu()
addDroneInteractive()
retrieveDroneInteractive()
searchDroneByNameInteractive()
searchDroneByIDInteractive()
swapDroneDataInteractive()
insertDroneTaskInteractive()
copyDroneInteractive()
sortDroneDataAscendingInteractive()
sortDroneDataDescendingInteractive()
Tree traversal menu integrations
Queue, Stack, Linked List menu integrations
Full system demo logic
Overall user interface flow
BONUS menu option:
insertDynamicTaskInteractive()


