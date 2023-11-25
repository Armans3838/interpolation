#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>

// Define a struct to hold the x, y, and z values of a point in 3D space
struct Point3D {
    double x;
    double y;
    double z;
};

// Define a function to create a corkscrew resulting in a vector of x, y, and z values
std::vector<Point3D> createCorkscrew(double startDist, double endDist, double initAltitude, double bearing, int numScrews, double velocity) {
    // Define constants for the corkscrew shape
    const double pitch = 2 * M_PI / numScrews;
    const double radius = (endDist - startDist) / (2 * M_PI);
    const double altitudeStep = (initAltitude / numScrews);

    // Define variables for the current position and altitude
    double currentDist = startDist;
    double currentAltitude = initAltitude;

    // Define a vector to hold the resulting points
    std::vector<Point3D> points;

    // Loop through each corkscrew
    for (int i = 0; i < numScrews; i++) {
        // Loop through each point in the corkscrew
        for (double t = 0; t <= 2 * M_PI; t += 0.1) {
            // Calculate the x, y, and z values of the current point
            double x = currentDist * cos(bearing + t);
            double y = currentDist * sin(bearing + t);
            double z = currentAltitude + radius * t / (2 * M_PI);

            // Add the point to the vector
            points.push_back({x, y, z});

            // Update the current distance and altitude
            currentDist += velocity * 0.1;
            currentAltitude -= altitudeStep * 0.1;
        }

        // Update the current distance and altitude for the next corkscrew
        currentDist += radius * pitch;
        currentAltitude += altitudeStep;
    }

    // Return the resulting vector of points
    return points;
}

