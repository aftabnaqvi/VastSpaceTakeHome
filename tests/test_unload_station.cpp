#include <gtest/gtest.h>
#include "unload_station.h"

TEST(UnloadStationTest, InitialState) {
    MiningUnloadStation station(1);
    EXPECT_EQ(station.getId(), 1);
    EXPECT_EQ(station.getVisitCount(), 0);
    EXPECT_EQ(station.queueSize(), 0);
}

TEST(UnloadStationTest, AddToQueue) {
    auto truck = std::make_shared<MiningTruck>(1);
    MiningUnloadStation station(1);
    station.addToQueue(truck);
    EXPECT_EQ(station.queueSize(), 1);
}

TEST(UnloadStationTest, ProcessQueue) {
    auto truck = std::make_shared<MiningTruck>(1);
    truck->setState(MiningTruck::WAITING);
    MiningUnloadStation station(1);
    station.addToQueue(truck);
    
    station.processQueue(0);
    EXPECT_EQ(station.getVisitCount(), 0);

    station.processQueue(1.0);
    EXPECT_EQ(station.getVisitCount(), 1);
    EXPECT_EQ(station.queueSize(), 0);
}

