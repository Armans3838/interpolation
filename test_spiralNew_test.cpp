#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>
#include "spiralNew.cpp"

int main() {
    double startDist = 0.0;
    double endDist = 1000.0;
    double altitude = 100.0;
    double bearing = M_PI / 4;
    double radius = 100.0;
    double velocity = 10.0;
    int numSpirals = 5;

    std::vector<Waypoint> waypoints = createSpiral(startDist, endDist, altitude, bearing, radius, velocity, numSpirals);

    for (int i = 0; i < waypoints.size(); i++) {
        std::cout << "Waypoint " << i << ": (" << waypoints[i].latitude << ", " << waypoints[i].longitude << ", " << waypoints[i].altitude << ")" << std::endl;
    }

    return 0;
}