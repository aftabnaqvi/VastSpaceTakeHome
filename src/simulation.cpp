//
//  simulation.cpp
//  VastSpace
//
//  Created by Syed Aftab Naqvi on 6/19/24.
//

#include <iostream>

#include "simulation.h"


Simulation::Simulation(int numTrucks, int numStations) : _currentTime(0) {
    for (int i = 0; i < numTrucks; ++i) {
        _trucks.push_back(std::make_shared<MiningTruck>(i));
    }
    for (int i = 0; i < numStations; ++i) {
        _stations.push_back(std::make_shared<UnloadStation>(i));
    }
    for (auto& truck : _trucks) {
        _eventQueue.push({truck->getStateEndTime(), truck});
    }
}

void Simulation::run(double duration) {
    while (_currentTime < duration) {
        if (_eventQueue.empty()) break;

        auto nextEvent = _eventQueue.top();
        _eventQueue.pop();
        _currentTime = nextEvent.first;
        auto truck = nextEvent.second;

        truck->updateState(_currentTime);

        if (truck->getState() == MiningTruck::TRAVELING_TO_STATION) { //} && _currentTime >= truck->getStateEndTime()) {
            int stationIndex = getShortestQueueStation();
            _stations[stationIndex]->addToQueue(truck);
            truck->setState(MiningTruck::WAITING);
        }

        for (auto& station : _stations) {
            station->processQueue(_currentTime);
        }

        _eventQueue.push({truck->getStateEndTime(), truck});
    }
    reportStatistics();
}

int Simulation::getShortestQueueStation() const {
    int shortestQueueIndex = 0;
    size_t shortestQueueSize = _stations[0]->queueSize();
    for (size_t i = 1; i < _stations.size(); ++i) {
        if (_stations[i]->queueSize() < shortestQueueSize) {
            shortestQueueIndex = i;
            shortestQueueSize = _stations[i]->queueSize();
        }
    }
    return shortestQueueIndex;
}

void Simulation::reportStatistics() const {
    std::cout << "Simulation Report:" << std::endl;
    for (const auto& truck : _trucks) {
        std::cout << "Truck " << truck->getId() << ": " << truck->getTotalMinedHelium() << " units of Helium-3 mined" << std::endl;
    }
    for (const auto& station : _stations) {
        std::cout << "Station " << station->getId() << ": " << station->getVisitCount() << " trucks unloaded, " << station->queueSize() << " trucks in queue" << std::endl;
    }
}
