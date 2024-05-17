#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define MIN_WAVELENGTH 380.0
#define MAX_WAVELENGTH 750.0

double calculate_theta(double wavelength, double slit_width, int m)
{


    if (wavelength < MIN_WAVELENGTH || wavelength > MAX_WAVELENGTH)
    {
        return NAN;
    }

    const double conversion_factor = 1e3;
    double theta_rad = asin((m * wavelength) / (slit_width * conversion_factor));
    return theta_rad * 180 / PI;
}

int main()
{
    double wavelength, slit_width[3];

    printf("Enter the wavelength of light (in nm):  ");
    while (scanf("%lf", &wavelength) != 1 || wavelength < MIN_WAVELENGTH || wavelength > MAX_WAVELENGTH)
    {
        printf("Out of the range. Please enter a valid number:  ");
        scanf("%*[^\n]");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Enter the width of slit %d (in µm): ", i + 1);
        while (scanf("%lf", &slit_width[i]) != 1 || slit_width[i] <= 0)
        {
            printf("Invalid slit width. Please enter a positive number: ");
            scanf("%*[^\n]");
        }
    }

    double theta_values[3];
    int min_theta_index = -1;
    double min_theta = INFINITY;

    for (int i = 0; i < 3; i++)
    {
        theta_values[i] = calculate_theta(wavelength, slit_width[i], 1);
        if (!isnan(theta_values[i]) && theta_values[i] < min_theta)
        {
            min_theta = theta_values[i];
            min_theta_index = i;
        }
    }

    if (min_theta_index != -1)
    {
        printf("\nSlit width %d (%.2f µm) bends the light the most with an angle of %.2f degrees.\n", min_theta_index + 1, slit_width[min_theta_index], min_theta);
    }
    else
    {
        printf("\nThere might be errors in entered values. Please check and re-run.\n");
    }
 if(wavelength>=380 && wavelength<=750)
        {

            if(wavelength<=380)
            {
                printf("Violet");
            }
            else if(wavelength<=485)
            {
                printf("blue");
            }

            else if(wavelength<=500 )
            {
                printf("cyan");
            }
            else if(wavelength<=565 )
            {
                printf("green");
            }
            else if(wavelength<=590 )
            {
                printf("yellow");
            }
            else if(wavelength<=625 )
            {
                printf("orange");
            }
            else if(wavelength<=750 )
            {
                printf("red");
            }
        }
        else
        {
            printf("Out of the range. Please enter a valid number.");
        }
        return 0;
}