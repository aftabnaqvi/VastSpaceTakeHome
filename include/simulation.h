//
//  simulation.h
//  VastSpace
//
//  Created by Syed Aftab Naqvi on 6/19/24.
//

#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <memory>
#include <queue>

#include "mining_truck.h"
#include "unload_station.h"


class Simulation {
public:
    // Constructor
    Simulation(int numTrucks, int numStations);
    
    // operations
    void run(double duration);
    void reportStatistics() const;

private:
    double _currentTime;                                    // current time
    std::vector<std::shared_ptr<MiningTruck>> _trucks;      // all trucks
    std::vector<std::shared_ptr<UnloadStation>> _stations;  // all stations
    std::priority_queue<std::pair<double, std::shared_ptr<MiningTruck>>,
        std::vector<std::pair<double, std::shared_ptr<MiningTruck>>>,
        std::greater<>> _eventQueue;                        // priority queue

    // gets shortest queue station
    int getShortestQueueStation() const;
};

#endif /* SIMULATION_H */
