#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

struct Point3D {
    double x, y, z;
};


vector<double> cosineInterpolation(Point3D start, Point3D end, int numpoints) {
    vector<double> zValues;
    double distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2) + pow(end.z - start.z, 2));
    for (int i = 0; i < numpoints; i++) {
        double t = (double)i / (numpoints - 1);
        double v = (1 - cos(t * M_PI)) / 2;
        double z = start.z * (1 - v) + end.z * v;
        zValues.push_back(z);
    }
    return zValues;
}


int main() {
    Point3D start = {0, 0, 0};
    Point3D end = {1, 1, 1};
    int numpoints = 10;
    std::vector<double> zValues = cosineInterpolation(start, end, numpoints);
    for (int i = 0; i < numpoints; i++) {
        std::cout << zValues[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
