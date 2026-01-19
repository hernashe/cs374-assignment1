/*
* Sheryll Hernandez
* hernashe_assignment1.c
* Programming Assignment 1: Basic Formulas 
* This program computes the total surface area and volume of 
* spherical segments based on user input. It validates all input,
* processes n valid spherical segments, and prints average results.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    /* Constants */ 
    const double PI = 3.14159265359;

    /* # of spherical segments to evaluate */
    int n;

    /* Input variables */
    double R;           // radius of sphere
    double ha;          // height of the top area of spherical segment
    double hb;          // height of the bottom area of spherical segment

    /* Computation variables */ 
    double a;           // radius of top of circular face
    double b;           // radius of bottom of circular face
    double h;           // height of spherical segment

    /* Output variables */
    double topSA;       // surface area of top circle    
    double bottomSA;    // surface area of bottom circle 
    double lateralSA;   // lateral surface area
    double totalSA;     // total surface area
    double volume;      // volume of spherical segment

    /* Accumulators for averages */
    double sumSA = 0.0; // sum of surface areas
    double sumV = 0.0;  // sum of volumes

    /* Ask for n until valid */
    do {
        printf("How many spherical segments you want to evaluate [2-10]?\n");
        scanf("%d", &n);
    } while (n < 2 || n > 10);

    /* Process the segments until we have n valid sets */
    int seg = 1;
    while (seg <= n) {

        printf("Obtaining data for spherical segment number %d\n", seg);

        /* read in the exact order: R, ha, hb */
        printf("What is the radius of the sphere (R)?\n");
        scanf("%lf", &R);

        printf("What is the height of the top area of the spherical segment (ha)?\n");
        scanf("%lf", &ha);

        printf("What is the height of the bottom area of the spherical segment (hb)?\n");
        scanf("%lf", &hb);

        /* print entered values before validation */
        printf("Entered data: R = %.2f ha = %.2f hb = %.2f.\n", R, ha, hb);

        /* validate input values */
        if (R <= 0 || ha <= 0 || hb <= 0 || ha > R || hb > R || ha < hb) {
            printf("Invalid Input,\n");
            continue;
        }

        /* Compute geometry values */
        a = sqrt(R * R - ha * ha);
        b = sqrt(R * R - hb * hb);
        h = ha - hb;

        /* Compute the surface area */
        topSA = PI * a * a;
        bottomSA = PI * b * b;
        lateralSA = 2.0 * PI * R * h;
        totalSA = topSA + bottomSA + lateralSA;

        /* Compute volume */
        volume = (1.0 / 6.0) * PI * h * (3.0 * a * a + 3.0 * b * b + h * h);

        /* print results */
        printf("Total Surface Area = %.2f Volume = %.2f.\n", totalSA, volume);

        /* add to totals for averages */
        sumSA += totalSA;
        sumV += volume;

        seg++;
    }

    /* print average results*/
    printf("Total averal results:\n");
    printf("Average Surface Area = %.2f Average Volume = %.2f.\n", sumSA / n, sumV / n);

    return 0;
}
