#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct point {
    double x, y, z;
};

vector<double> interpolatePoints(point start, point end, int numPoints) {
    vector<double> zValues;
    double xDiff = end.x - start.x;
    double yDiff = end.y - start.y;
    double zDiff = end.z - start.z;
    double xIncrement = xDiff / (numPoints - 1);
    double yIncrement = yDiff / (numPoints - 1);
    double zIncrement = zDiff / (numPoints - 1);
    for (int i = 0; i < numPoints; i++) {
        double x = start.x + i * xIncrement;
        double y = start.y + i * yIncrement;
        double z = start.z + i * zIncrement;
        zValues.push_back(z);
    }
    return zValues;
}

int main() {
    point start = {0, 0, 0};
    point end = {1, 1, 1};
    int numPoints = 5;
    vector<double> zValues = interpolatePoints(start, end, numPoints);
    for (double z : zValues) {
        cout << z << endl;
    }
    return 0;
}