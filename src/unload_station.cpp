//
//  unload_station.cpp
//  VastSpace
//
//  Created by Syed Aftab Naqvi on 6/19/24.
//

#include "mining_truck.h"
#include "unload_station.h"


UnloadStation::UnloadStation(int id) : _id(id), _visitCount(0) {}

int UnloadStation::getId() const {
    return _id;
}

std::queue<std::shared_ptr<MiningTruck>> UnloadStation::getQueue() const {
    return _queue;
}

int UnloadStation::getVisitCount() const {
    return _visitCount;
}

void UnloadStation::setId(int id) {
    _id = id;
}

void UnloadStation::setQueue(std::queue<std::shared_ptr<MiningTruck>> queue) {
    _queue = queue;
}

void UnloadStation::addToQueue(std::shared_ptr<MiningTruck> truck) {
    _queue.push(truck);
    truck->setState(MiningTruck::WAITING);
}

void UnloadStation::processQueue(double currentTime) {
    if (!_queue.empty()) {
        auto truck = _queue.front();
        if (truck->getState() == MiningTruck::WAITING) {
            _queue.pop();
            truck->setState(MiningTruck::UNLOADING);
            truck->calculateStateEndTime(currentTime);
            ++_visitCount; // Increment visit count when a truck starts unloading
        }
    }
}

size_t UnloadStation::queueSize() const {
    return _queue.size();
}
