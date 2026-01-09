#include <iostream>
#include <vector>
#include <iomanip> // For clean table formatting
#include "FCWEngine.hpp"

// A simple structure to represent one "frame" of sensor data
struct SensorFrame {
    double hostSpeed;
    double targetDistance;
    double targetSpeed;
};

int main() {
    // Initialize our ADAS Engine
    // Thresholds: Warning at 2.5s, Emergency Braking at 1.2s
    FCWEngine adas(2.5, 1.2);

    // Simulate a stream of incoming LiDAR data (Distance is decreasing)
    std::vector<SensorFrame> logData = {
        {25.0, 100.0, 20.0}, // Safe: TTC is 20.0s
        {25.0, 40.0,  20.0}, // Warning: TTC is 8.0s
        {25.0, 10.0,  20.0}, // Warning: TTC is 2.0s
        {25.0, 5.0,   20.0}, // Braking: TTC is 1.0s
        {25.0, 2.0,   20.0}  // Braking: TTC is 0.4s
    };

    std::cout << "--- ADAS Forward Collision Warning System Active ---" << std::endl;
    std::cout << std::setw(10) << "Dist(m)" << std::setw(15) << "Rel_V(m/s)" << std::setw(20) << "System State" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    for (const auto& frame : logData) {
        // Process the data
        SafetyState currentState = adas.monitor(frame.hostSpeed, frame.targetDistance, frame.targetSpeed);

        // Convert enum to string for printing
        std::string stateStr;
        switch (currentState) {
            case SafetyState::SAFE: stateStr = "SAFE"; break;
            case SafetyState::WARNING: stateStr = "(!) WARNING"; break;
            case SafetyState::EMERGENCY_BRAKING: stateStr = "[!!] BRAKING [!!]"; break;
        }

        // Print results
        double relV = frame.hostSpeed - frame.targetSpeed;
        std::cout << std::setw(10) << frame.targetDistance 
                  << std::setw(15) << relV 
                  << std::setw(20) << stateStr << std::endl;
    }

    return 0;
}