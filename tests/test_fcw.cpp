// adding GTest

#include <gtest/gtest.h>
#include "..src/FCWEngine.hpp"

TEST(FCWTest, DetectEmergencyBraking)
{
    FCWEngine adas(2.5, 1.2) // warning at 2.5 sec, brake at 1.2 sec

        // host 30m/s , target 10m/s (rel=20m/s), dist 20m-> TTC=1.0s

        EXPECT_EQ(adas.monitor(30.0, 20.0, 10.0), SafetyState::EMERGENCY_BRAKING);
}

TEST(FCWTest, SafeWhenTargetIsFaster)
{
    FCWEngine adas(2.5, 1.2)

        // target is moving away

        EXPECT_EQ(adas.monitor(20.0, 50.0, 30.0), SafetyState::SAFE);
}