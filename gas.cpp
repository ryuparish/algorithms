#include <vector>
#include <iostream>

int main() {
    int d, gas, orig, stops, a, current, count, distance;

    // Read in the parameters
    std::cin >> d >> gas >> stops;
    int* stations;
    stations = new (std::nothrow) int[stops];
    if (stations == nullptr) {
        std::cout << "\n Heap Memory could not be allocated .";
        return 1;
    }

    // Read in the distances of the stops
    for (int i = 0; i < stops; ++i) {
        std::cin >> a;
        stations[i] = a;
    }

    // distance will now become our distance marker, and count will be our counter for the number of stops
    orig = gas;
    distance = 0;
    count = 0; 
    current = 0;

    // While the car has not reached it's destination
    // Note: You can either use the current distance and the total distance or the current station and the last station as indictor of if you are done looping. Either way, you will need to keep track of how many stop you have made. ( 
    while ((d - distance) - gas > 0) {

        // For checking if the next stop changes (if not the closest is unreachable)
        int previousstop = *stations;

        // We only drive until we arrive at the last possible stop or until we run out of gas (in the case that we arrive at the last possible stop and still cannot reach the goal, the if statement below will catch that error
        while(current <= stops-1 && gas - (*stations - distance) >= 0) {
            gas -= (*stations - distance);
            distance += *stations - distance;
            current++;
            stations++;
        }

        // Refueling
        gas += orig - gas;

        // If the station is in the same spot as before the inner while loop, this means that the closest station is not reachable and therefor we must return -1
        if (*(stations) - *(stations - 1) > gas) {
            std::cout << -1;
            return 1;
        }

        count += 1;
    }
    

    std::cout << count;
    delete [] stations;
    return 0;
}

