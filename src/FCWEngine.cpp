/*
The core of ADAS is the time-to-collision formula:

TTC = d/v(host)- v(target)

note: only valid if the host is fater than the target
*/

// adding header file which is previoulsy created

#include "FCWEngine.hpp"

FCWEngine::FCWEngine(double warningTTC, double brakingTTC)
    : m_warningTTC(warningTTC), m_brakingTTC(brakingTTC) {}

SafetyState FCWEngine::monitor(double hostSpeed, double targetDistance, double targetSpeed)
{
    double relativeVelocity = hostSpeed - targetSpeed;

    if (relativeVelocity <= 0)
        return SafetyState::SAFE;

    double ttc = targetDistance / relativeVelocity;

    if (ttc <= m_brakingTTC)
        return SafetyState::EMERGENCY_BRAKING;
    if (ttc <= m_warningTTC)
        return SafetyState::WARNING;

    return SafetyState::SAFE;
}