#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> nonlinearLinespace(double startVelocity, double endVelocity, int numPoints) {
    std::vector<double> velocities;
    double acceleration = (endVelocity * endVelocity - startVelocity * startVelocity) / (2 * numPoints);
    double deceleration = acceleration;
    double totalDistance = (endVelocity * endVelocity - startVelocity * startVelocity) / (2 * acceleration) + (endVelocity * endVelocity - startVelocity * startVelocity) / (2 * deceleration);
    double distancePerPoint = totalDistance / (numPoints - 1);
    double currentVelocity = startVelocity;

    for (int i = 0; i < numPoints; i++) {
        velocities.push_back(currentVelocity);
        double distanceCovered = (currentVelocity * currentVelocity - startVelocity * startVelocity) / (2 * acceleration) + (currentVelocity * currentVelocity - startVelocity * startVelocity) / (2 * deceleration);
        double remainingDistance = totalDistance - distanceCovered;
        double nextVelocity = std::sqrt(2 * (acceleration * remainingDistance + startVelocity * startVelocity));
        currentVelocity = nextVelocity;
    }

    return velocities;
}

int main() {
    double startVelocity = 10.0;
    double endVelocity = 30.0;
    int numPoints = 5;

    std::vector<double> velocities = nonlinearLinespace(startVelocity, endVelocity, numPoints);

    for (double velocity : velocities) {
        std::cout << velocity << " ";
    }

    return 0;
}
