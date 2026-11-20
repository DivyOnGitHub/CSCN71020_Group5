Triangle C

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {

    char* result = "";

    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        result = "Not a triangle";
    }
    else if ((long long)side1 + side2 <= side3 ||
        (long long)side1 + side3 <= side2 ||
        (long long)side2 + side3 <= side1) {
        result = "Not a triangle";
    }
    else if (side1 == side2 && side2 == side3) {
        result = "Equilateral triangle";
    }
    else if (side1 == side2 ||
        side1 == side3 ||
        side2 == side3) {
        result = "Isosceles triangle";
    }
    else {
        result = "Scalene triangle";
    }

    return result;
}


void calculateTriangleAngles(int side1, int side2, int side3) {

    double angleA, angleB, angleC;

    angleA = acos(((double)side2 * side2 +
        (double)side3 * side3 -
        (double)side1 * side1) /
        (2.0 * side2 * side3));

    angleB = acos(((double)side1 * side1 +
        (double)side3 * side3 -
        (double)side2 * side2) /
        (2.0 * side1 * side3));

    angleC = acos(((double)side1 * side1 +
        (double)side2 * side2 -
        (double)side3 * side3) /
        (2.0 * side1 * side2));

    angleA = angleA * 180.0 / 3.141592653589793;
    angleB = angleB * 180.0 / 3.141592653589793;
    angleC = angleC * 180.0 / 3.141592653589793;

    printf_s("Angle A: %.2f degrees\n", angleA);
    printf_s("Angle B: %.2f degrees\n", angleB);
    printf_s("Angle C: %.2f degrees\n", angleC);
}