#include <iostream>
#include <vector>
#include <cmath>

struct Waypoint {
    double x;
    double y;
    double z;
};


std::vector<Waypoint> createCorkscrewWaypoints(const Waypoint& start, const Waypoint& end, double velocity, double radius, double bearing) {
    std::vector<Waypoint> waypoints;
    
    // Calculate the number of waypoints based on the distance between start and end
    double distance = std::sqrt(std::pow(end.x - start.x, 2) + std::pow(end.y - start.y, 2) + std::pow(end.z - start.z, 2));
    int numWaypoints = static_cast<int>(std::ceil(distance / velocity));
    
    // Calculate the angle increment for each waypoint
    double angleIncrement = 360.0 / numWaypoints;
    
    // Create the corkscrew waypoints
    for (int i = 0; i < numWaypoints; i++) {
        double angle = bearing + i * angleIncrement;
        double angleRadians = angle * M_PI / 180.0; // Convert angle to radians
        
        double x = start.x + radius * std::cos(angleRadians);
        double y = start.y + radius * std::sin(angleRadians);
        double z = start.z + (end.z - start.z) * (i / static_cast<double>(numWaypoints - 1));
        
        waypoints.push_back({x, y, z});
    }
    
    return waypoints;
}

int main() {
    Waypoint start = {0, 0, 0};
    Waypoint end = {10, 10, 5};
    double velocity = 1.0;
    double radius = 5.0;
    double bearing = 180.0;
    
    std::vector<Waypoint> corkscrewWaypoints = createCorkscrewWaypoints(start, end, velocity, radius, bearing);
    
    // Print the corkscrew waypoints
    for (const auto& waypoint : corkscrewWaypoints) {
        std::cout << "Waypoint: (" << waypoint.x << ", " << waypoint.y << ", " << waypoint.z << ")\n";
    }
    
    return 0;
}
