#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{

    int m1 = 3;
    double theta1 = 65.0 * PI / 180.0;
    double lambda1 = 530e-9;
    int m2 = 2;
    double theta2, lambda2 = 700e-9;


    double d = m1 * lambda1 / sin(theta1);


    theta2 = asin(m2 * lambda2 / d);


    theta2 = theta2 * 180.0 / PI;

    printf("The angle of the second-order bright spot for red light is:  %.2f degrees.\n", theta2);

    return 0;
}