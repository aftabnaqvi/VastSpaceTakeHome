#include <gtest/gtest.h>
#include "mining_truck.h"

TEST(MiningTruckTest, InitialState) {
    MiningTruck truck(1);
    EXPECT_EQ(truck.getId(), 1);
    EXPECT_EQ(truck.getState(), MiningTruck::MINING);
    EXPECT_DOUBLE_EQ(truck.getTotalMinedHelium(), 0.0);
}

TEST(MiningTruckTest, StateTransition) {
    MiningTruck truck(1);
    truck.updateState(1.0);
    EXPECT_EQ(truck.getState(), MiningTruck::TRAVELING_TO_STATION);
    
    truck.updateState(truck.getStateEndTime());
    EXPECT_EQ(truck.getState(), MiningTruck::WAITING);
}

TEST(MiningTruckTest, CalculateStateEndTime) {
    MiningTruck truck(1);
    truck.setState(MiningTruck::TRAVELING_TO_SITE);
    truck.calculateStateEndTime(0);
    EXPECT_DOUBLE_EQ(truck.getStateEndTime(), 0.5);
}


