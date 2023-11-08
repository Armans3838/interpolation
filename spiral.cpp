#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>
#include <iostream>

struct LLA {
    double lat;
    double lon;
    double alt;
};

std::vector<LLA> generate_spiral(double start_dist, double end_dist, double altitude, double bearing, double radius, double velocity, int num_spirals) {
    std::vector<LLA> waypoints;

    // Define the spiral parameters
    double a = (end_dist - start_dist) / (2 * M_PI);
    double b = start_dist;
    double dt = 1.0 / (velocity * num_spirals);

    // Generate the spiral waypoints
    for (int i = 0; i < num_spirals; i++) {
        for (double t = 0; t <= 4 * M_PI; t += dt) {
            double x = a * t * cos(t) + b;
            double y = a * t * sin(t);
            double lat = y / radius + 0.0; // convert to radians
            double lon = x / (radius * cos(bearing)) + 0.0; // convert to radians
            LLA waypoint = {lat, lon, altitude};
            waypoints.push_back(waypoint);
        }
        b += 2 * M_PI * radius;
    }

    return waypoints;
}
