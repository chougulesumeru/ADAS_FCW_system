/*
we will define a class that takes the host vehicles speed and
the distance of a target vehicle to determine the safety state.
*/

#ifndef FCW_ENGINE_HPP
#define FCW_ENGINE_HPP

// create a enum
enum class SafetyState
{
    SAFE,
    WARNING,
    EMERGENCY_BRAKING
};

class FCWEngine
{
public:
    // parameters: TTC thresholds in seconds
    FCWEngine(double warningTTC, double brakingTTC);

    SafetyState monitor(double hostSpeed, double targetDistance, double targetSpeed);

private:
    double m_warningTTC;
    double m_brakingTTC;
}

#endif