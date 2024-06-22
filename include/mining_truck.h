//
//  mining_truck.h
//  VastSpace
//
//  Created by Syed Aftab Naqvi on 6/19/24.
//

#ifndef MINING_TRUCK_H
#define MINING_TRUCK_H

#include <random>
#include <memory>


class MiningTruck {
public:
    enum State { MINING, TRAVELING_TO_SITE, TRAVELING_TO_STATION, UNLOADING, WAITING };
    
    // Constructor
    MiningTruck(int id);

    // Getters
    int getId() const;
    State getState() const;
    double getStateEndTime() const;
    double getTotalMinedHelium() const;

    // Setters
    void setState(State state);
    void setStateEndTime(double time);

    // operations
    // calculates state end time
    void calculateStateEndTime(double currentTime);
    
    // update the state - sets next state in _state member
    void updateState(double currentTime);

private:
    int _id;                    // Truck ID
    State _state;               // truct state, e.g. MIMING etc
    double _stateEndTime;       // state end time
    double _totalMinedHelium;   // total mined helium
    double _travelTime;         // travel time
    double _unloadTime;         // unload time
};

#endif // MINING_TRUCK_H
