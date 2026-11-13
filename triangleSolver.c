#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3)
{

    char* result = "";

    // Check if all sides are positive
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        result = "Not a triangle";
    }

    // Check if the sides form a valid triangle
    else if (side1 + side2 <= side3 ||
        side1 + side3 <= side2 ||
        side2 + side3 <= side1) {
        result = "Not a triangle";
    }

    // Check for equilateral triangle
    else if (side1 == side2 && side2 == side3) {
        result = "Equilateral triangle";
    }

    // Check for isosceles triangle
    else if (side1 == side2 ||
        side1 == side3 ||
        side2 == side3) {
        result = "Isosceles triangle";
    }

    // Otherwise, it is scalene
    else {
        result = "Scalene triangle";
    }

    return result;
}
