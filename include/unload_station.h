//
//  unload_station.h
//  VastSpace
//
//  Created by Syed Aftab Naqvi on 6/19/24.
//

#ifndef UNLOAD_STATION_H
#define UNLOAD_STATION_H

#include <queue>
#include <memory>


class MiningTruck;

class UnloadStation {
public:
    // Constructor
    UnloadStation(int id);

    // Getters
    int getId() const;
    std::queue<std::shared_ptr<MiningTruck>> getQueue() const;
    int getVisitCount() const;

    // Setters
    void setId(int id);
    void setQueue(std::queue<std::shared_ptr<MiningTruck>> queue);

    // Add truck to the station queue
    void addToQueue(std::shared_ptr<MiningTruck> truck);
    
    // Process the queue (unload trucks if possible)
    void processQueue(double currentTime);
    
    // Get current queue size
    size_t queueSize() const;

private:
    int _id;                                            // Station ID
    std::queue<std::shared_ptr<MiningTruck>> _queue;    // Queue of trucks waiting to unload
    int _visitCount;                                    // Count of visits to the station for unloading
};

#endif // UNLOAD_STATION_H
