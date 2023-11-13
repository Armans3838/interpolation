#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>

struct Waypoint {
    double latitude;
    double longitude;
    double altitude;
};

// end refers to the distance from the origin of the spiral while start refers to the distance from the origin of the spiral. SWAP START AND END
std::vector<Waypoint> createSpiral(double startDist, double endDist, double altitude, double bearing, double radius, double velocity, int numSpirals) {
    double angleBetweenSpirals = 2 * M_PI / numSpirals;
    double totalDistance = endDist - startDist;
    int numPoints = totalDistance * velocity;
    double distanceBetweenPoints = totalDistance / numPoints;
    std::vector<Waypoint> waypoints;

    for (int i = 0; i < numPoints; i++) {
        double distanceFromOrigin = startDist + i * distanceBetweenPoints;
        double angle = i * angleBetweenSpirals;
        double latitude = asin(sin(bearing) * cos(distanceFromOrigin / radius) + cos(bearing) * sin(distanceFromOrigin / radius) * cos(angle));
        double longitude = atan2(sin(angle) * sin(distanceFromOrigin / radius) * cos(bearing), cos(distanceFromOrigin / radius) - sin(bearing) * sin(latitude));
        waypoints.push_back({latitude, longitude, altitude});
    }

    return waypoints;
}


// end refers to the distance from the origin of the spiral while start refers to the distance from the origin of the spiral. SWAP START AND END
std::vector<Waypoint> createSpiralWithAltitude(double startDist, double endDist, double startAltitude, double endAltitude, double bearing, double radius, double velocity, int numSpirals) {
    double angleBetweenSpirals = 2 * M_PI / numSpirals;
    double totalDistance = endDist - startDist;
    int numPoints = totalDistance * velocity;
    double distanceBetweenPoints = totalDistance / numPoints;
    double altitudeIncrement = (endAltitude - startAltitude) / numPoints;
    std::vector<Waypoint> waypoints;

    for (int i = 0; i < numPoints; i++) {
        double distanceFromOrigin = startDist + i * distanceBetweenPoints;
        double angle = i * angleBetweenSpirals;
        double latitude = asin(sin(bearing) * cos(distanceFromOrigin / radius) + cos(bearing) * sin(distanceFromOrigin / radius) * cos(angle));
        double longitude = atan2(sin(angle) * sin(distanceFromOrigin / radius) * cos(bearing), cos(distanceFromOrigin / radius) - sin(bearing) * sin(latitude));
        double altitude = startAltitude + i * altitudeIncrement;
        waypoints.push_back({latitude, longitude, altitude});
    }

    return waypoints;
}