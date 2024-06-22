#include <gtest/gtest.h>
#include "simulation.h"

TEST(SimulationTest, Initialization) {
    Simulation simulation(5, 3);
    // Simulation should initialize with 5 trucks and 3 stations
    EXPECT_NO_THROW(simulation.run(0.1));
}

TEST(SimulationTest, ShortestQueueStation) {
    Simulation simulation(5, 3);
    EXPECT_EQ(simulation.getShortestQueueStation(), 0);
}

TEST(SimulationTest, RunSimulation) {
    Simulation simulation(5, 3);
    simulation.run(1.0);
    // Checking if the trucks have mined some Helium-3
    EXPECT_TRUE(simulation.getTrucks()[0]->getTotalMinedHelium() > 0);
    EXPECT_TRUE(simulation.getStations()[0]->getVisitCount() > 0);
}

