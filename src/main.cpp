//
//  main.cpp
//  VastSpace
//
//  Created by Syed Aftab Naqvi on 6/20/24.
//

#include <iostream>

#include "simulation.h"


int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

     int numTrucks = 5;
     int numStations = 3;
     double duration = 72.0 * 60.0; // 72 hours

    Simulation simulation(numTrucks, numStations);
    simulation.run(duration);

    return 0;
}

