//
//  truck.cpp
//  VastSpace
//
//  Created by Syed Aftab Naqvi on 6/19/24.
//

#include "mining_truck.h"


MiningTruck::MiningTruck(int id)
    : _id(id), _state(MINING), _stateEndTime(0), _totalMinedHelium(0), _travelTime(30.0), _unloadTime(5.0) {
    calculateStateEndTime(0);
}

int MiningTruck::getId() const {
    return _id;
}

MiningTruck::State MiningTruck::getState() const {
    return _state;
}

double MiningTruck::getStateEndTime() const {
    return _stateEndTime;
}

double MiningTruck::getTotalMinedHelium() const {
    return _totalMinedHelium;
}

void MiningTruck::setState(State state) {
    _state = state;
}

void MiningTruck::setStateEndTime(double time) {
    _stateEndTime = time;
}

void MiningTruck::calculateStateEndTime(double currentTime) {
    if (_state == MINING) {
        _stateEndTime = currentTime + (1 + rand() % 5) * 60; // in minutes
    } else if (_state == TRAVELING_TO_SITE || _state == TRAVELING_TO_STATION) {
        _stateEndTime = currentTime + _travelTime;
    } else if (_state == UNLOADING) {
        _stateEndTime = currentTime + _unloadTime;
    }
}

void MiningTruck::updateState(double currentTime) {
    if (currentTime >= _stateEndTime) {
        switch (_state) {
        case MINING:
            _state = TRAVELING_TO_STATION;
            break;
        case TRAVELING_TO_SITE:
            _state = MINING;
            break;
        case TRAVELING_TO_STATION:
            _state = UNLOADING;
            break;
        case UNLOADING:
            _state = TRAVELING_TO_SITE;
            ++_totalMinedHelium;
            break;
        default:
            break;
        }
        calculateStateEndTime(currentTime);
    }
}
