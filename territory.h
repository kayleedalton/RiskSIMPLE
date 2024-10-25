#ifndef TERRITORY_H
#define TERRITORY_H

#include <vector>

class Territory {
public:
    int id;  // Unchanging territory ID
    int owner;  // Player 1 or Player 2
    int troops;  // Number of troops in the territory
    std::vector<int> adjacent;  // Adjacency list (IDs of adjacent territories)

    Territory(int id, int owner, int troops);
};

#endif // TERRITORY_H
