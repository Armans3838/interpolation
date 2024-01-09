#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x;
    double y;
    double z;
};

std::vector<Point> generateWaypoints(const std::vector<Point>& points, double velocity) {
    std::vector<Point> waypoints;
    
    for (int i = 0; i < points.size() - 1; i++) {
        const Point& currentPoint = points[i];
        const Point& nextPoint = points[i + 1];
        
        double distance = std::sqrt(std::pow(nextPoint.x - currentPoint.x, 2) + std::pow(nextPoint.y - currentPoint.y, 2));
        int numWaypoints = std::ceil(distance / velocity);
        
        double dx = (nextPoint.x - currentPoint.x) / numWaypoints;
        double dy = (nextPoint.y - currentPoint.y) / numWaypoints;
        
        for (int j = 0; j < numWaypoints; j++) {
            double x = currentPoint.x + j * dx;
            double y = currentPoint.y + j * dy;
            double z = currentPoint.z;
            
            waypoints.push_back({x, y, z});
        }
    }
    
    return waypoints;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

struct Point {
    double x;
    double y;
    double z;
};

std::vector<Point> generateWaypoints(const std::vector<Point>& points, double velocity) {
    std::vector<Point> waypoints;
    
    for (int i = 0; i < points.size() - 1; i++) {
        const Point& currentPoint = points[i];
        const Point& nextPoint = points[i + 1];
        
        double distance = std::sqrt(std::pow(nextPoint.x - currentPoint.x, 2) + std::pow(nextPoint.y - currentPoint.y, 2));
        int numWaypoints = std::ceil(distance / velocity);
        
        double dx = (nextPoint.x - currentPoint.x) / numWaypoints;
        double dy = (nextPoint.y - currentPoint.y) / numWaypoints;
        
        for (int j = 0; j < numWaypoints; j++) {
            double x = currentPoint.x + j * dx;
            double y = currentPoint.y + j * dy;
            double z = currentPoint.z;
            
            waypoints.push_back({x, y, z});
        }
    }
    
    return waypoints;
}

int main() {
    // Example usage
    std::vector<Point> points = {
        {0.0, 0.0, 0.0},
        {1.0, 2.0, 0.0},
        {3.0, 1.0, 0.0},
        {4.0, 3.0, 0.0},
        {6.0, 2.0, 0.0}
    };
    
    double velocity = 0.5;
    
    std::vector<Point> waypoints = generateWaypoints(points, velocity);
    
    // Extract x and y coordinates from waypoints
    std::vector<double> xCoordinates;
    std::vector<double> yCoordinates;
    for (const Point& waypoint : waypoints) {
        xCoordinates.push_back(waypoint.x);
        yCoordinates.push_back(waypoint.y);
    }
    
    // Plot the waypoints
    plt::plot(xCoordinates, yCoordinates, "bo-");
    plt::title("Waypoints (Top-Down View)");
    plt::xlabel("X");
    plt::ylabel("Y");
    plt::show();
    
    return 0;
}
