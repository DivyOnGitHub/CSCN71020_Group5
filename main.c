#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {
    bool continueProgram = true;

    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {

        case 1: {
            printf_s("Triangle selected.\n");

            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);

            char* result = analyzeTriangle(
                triangleSidesPtr[0],
                triangleSidesPtr[1],
                triangleSidesPtr[2]
            );

            printf_s("%s\n", result);

            if (strcmp(result, "Not a triangle") != 0) {
                calculateTriangleAngles(
                    triangleSidesPtr[0],
                    triangleSidesPtr[1],
                    triangleSidesPtr[2]
                );
            }

            break;
        }

        case 2: {
            printf_s("Rectangle selected.\n");

            double x1, y1, x2, y2, x3, y3, x4, y4;
            double perimeter = 0;
            double area = 0;

            printf_s("Enter coordinates of point 1 (x y): ");
            scanf_s("%lf %lf", &x1, &y1);

            printf_s("Enter coordinates of point 2 (x y): ");
            scanf_s("%lf %lf", &x2, &y2);

            printf_s("Enter coordinates of point 3 (x y): ");
            scanf_s("%lf %lf", &x3, &y3);

            printf_s("Enter coordinates of point 4 (x y): ");
            scanf_s("%lf %lf", &x4, &y4);

            bool isRectangle = analyzeRectangle(
                x1, y1,
                x2, y2,
                x3, y3,
                x4, y4,
                &perimeter,
                &area
            );

            if (isRectangle) {
                printf_s("The points form a rectangle.\n");
                printf_s("Perimeter: %.2f\n", perimeter);
                printf_s("Area: %.2f\n", area);
            }
            else {
                printf_s("The points do not form a rectangle.\n");
            }

            break;
        }

        case 0:
            continueProgram = false;
            break;

        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }

    return 0;
}

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("0. Exit\n");

    int shapeChoice = -1;

    printf_s("Enter number: ");
    scanf_s("%d", &shapeChoice);

    return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
    printf_s("Enter the three sides of the triangle: ");

    for (int i = 0; i < 3; i++) {
        scanf_s("%d", &triangleSides[i]);
    }

    return triangleSides;
}