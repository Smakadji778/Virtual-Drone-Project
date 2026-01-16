#include "AdvancedDrone.h"
#include <iostream>

AdvancedDrone::AdvancedDrone()
    : Drone(), batteryLevel(100.0f), autopilotEnabled(false) {}

AdvancedDrone::AdvancedDrone(const std::string& n, int id,
                             int init_x, int init_y,
                             float battery)
    : Drone(n, id, init_x, init_y),
      batteryLevel(battery),
      autopilotEnabled(false) {}

void AdvancedDrone::setBatteryLevel(float level) {
    if (level < 0.0f) level = 0.0f;
    if (level > 100.0f) level = 100.0f;
    batteryLevel = level;
}

float AdvancedDrone::getBatteryLevel() const {
    return batteryLevel;
}

void AdvancedDrone::enableAutopilot()  { autopilotEnabled = true;  }
void AdvancedDrone::disableAutopilot() { autopilotEnabled = false; }
bool AdvancedDrone::isAutopilotEnabled() const {
    return autopilotEnabled;
}

void AdvancedDrone::updateBattery(float delta) {
    setBatteryLevel(batteryLevel + delta);
}

void AdvancedDrone::autoReorderTasks() {
    //if battery is low reverse
    if (batteryLevel >= 30.0f) return;

    std::string tempTasks[5];
    int tempPos[5][2];

    for (int i = 0; i < 5; ++i) {
        tempTasks[i] = getTask(i);
        tempPos[i][0] = getTaskPosition(i, 0);
        tempPos[i][1] = getTaskPosition(i, 1);
    }

    // Reverse tasks and positions
    for (int i = 0; i < 5; ++i) {
        int j = 4 - i;
        setTask(i, tempTasks[j]);
        setTaskPosition(i, tempPos[j][0], tempPos[j][1]);
    }
}

void AdvancedDrone::displayDrone() const {
    // Call base version first
    Drone::displayDrone();
    std::cout << "Battery Level: " << batteryLevel << "%\n";
    std::cout << "Autopilot: "
              << (autopilotEnabled ? "Enabled" : "Disabled") << "\n";
    std::cout << "===========================\n";
}
