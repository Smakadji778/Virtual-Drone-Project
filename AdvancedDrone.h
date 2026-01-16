#ifndef ADVANCEDDRONE_H
#define ADVANCEDDRONE_H

#include "Drone.h"

class AdvancedDrone : public Drone {
private:
    float batteryLevel;      // percentage 0–100
    bool autopilotEnabled;

public:
    AdvancedDrone();
    AdvancedDrone(const std::string& n, int id,
                  int init_x, int init_y,
                  float battery = 100.0f);

    void setBatteryLevel(float level);
    float getBatteryLevel() const;

    void enableAutopilot();
    void disableAutopilot();
    bool isAutopilotEnabled() const;

    void updateBattery(float delta);   //delta can be negative

    //if batter less than 30% reorder
    void autoReorderTasks();

    void displayDrone() const override;
};

#endif
