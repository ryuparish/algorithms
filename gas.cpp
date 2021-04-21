#include <vector>
#include <iostream>

int main() {
    int d, gas, num_stops, a;

    // Read in the parameters
    std::cin >> d >> gas >> num_stops;
    std::vector<long long> stations;

    // The way to do this is just to follow the lecture and not make it more complicated than it is. Doing so will begin a series of infinite bugs and paradoxes (this will happen anyway if you are not good enough and you then learn to be better)
    // Start off with the first stop being zero like in the lecture
    stations.push_back(0);

    // Read in the distances of the stops
    while(std::cin >> a) {
        stations.push_back(a);
    }
    
    // Have the ending point be the ending distance so we can use the algorithm described in the lecture
    stations.push_back(d);

    // Define the current_station and last refill variables
    int current_station = 0, last_refill = 0, refills = 0;
    while (current_station <= num_stops) {
        last_refill = current_station;
        while (current_station <= num_stops && stations[current_station + 1] - stations[last_refill] <= gas) {
            current_station++;
        }
        if (last_refill == current_station) {
            std::cout << -1;
            return 1;
        }
        if (current_station <= num_stops) {
            refills++;
        }
    }
    std::cout << refills;
    return 0;
}

