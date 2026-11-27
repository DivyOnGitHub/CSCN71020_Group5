#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"

bool analyzeRectangle(
    double x1, double y1,
    double x2, double y2,
    double x3, double y3,
    double x4, double y4,
    double* perimeter,
    double* area
) {
    // Calculate the four side vectors
    double abX = x2 - x1;
    double abY = y2 - y1;

    double bcX = x3 - x2;
    double bcY = y3 - y2;

    double cdX = x4 - x3;
    double cdY = y4 - y3;

    double daX = x1 - x4;
    double daY = y1 - y4;

    // Calculate side lengths
    double ab = sqrt(abX * abX + abY * abY);
    double bc = sqrt(bcX * bcX + bcY * bcY);
    double cd = sqrt(cdX * cdX + cdY * cdY);
    double da = sqrt(daX * daX + daY * daY);

    // Reject zero-length sides
    if (ab == 0 || bc == 0 || cd == 0 || da == 0) {
        return false;
    }

    // Check that adjacent sides are perpendicular
    double dotProduct = abX * bcX + abY * bcY;

    if (fabs(dotProduct) > 1e-9 * ab * bc) {
        return false;
    }

    // Check that opposite sides are parallel
    double crossAB_CD = abX * cdY - abY * cdX;
    double crossBC_DA = bcX * daY - bcY * daX;

    if (fabs(crossAB_CD) > 1e-9 * ab * cd ||
        fabs(crossBC_DA) > 1e-9 * bc * da) {
        return false;
    }

    // Calculate perimeter and area
    *perimeter = ab + bc + cd + da;
    *area = ab * bc;

    return true;
}