// Group Members
// David Henry - 1007604
// Rockell London - 1037481



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int points, i, inside = 0;
double x, y, r, py;

int main()
{
	printf("How many values of Pi to generate ? : ");

	scanf("%d", &points);

	// srand takes a seed number that is used to generate random numbers 
	// if this isn't done rand() will generate the same numbers everytime
	// in this case we use time as a seed

	srand((unsigned) time(NULL));

	for (i = 0; i < points; i++)
	{
		// we're generating values between 0 and 1 to create the circle (r2=x2+y2)
		// divide rand/randmax to get values between 0 and 1

		x = (double) rand() / RAND_MAX;
		y = (double) rand() / RAND_MAX;

		r = (pow(x, 2) + pow(y, 2));	// no need for sqrt since we're checking to see if r < 1 to determine if the point is inside the circle

		if (r < 1)
		{
			inside++;
		}

		py = 4 * (double) inside /  points;	//4 *inside count / total sample size = approx py

		printf("Calculation #%d : %f\n", i + 1, py);
	}

	printf("Final calculation of Pi after %d iterations is approximately:  %f\n", points, py);
	
	return 0;
}

/**FROM THE WIKI https://en.wikipedia.org/wiki/Monte_Carlo_method#Overview

Draw a square, then inscribe a quadrant within it

Uniformly scatter a given number of points over the square

Count the number of points inside the quadrant, i.e. having a distance from the origin of less than 1

The ratio of the inside-count and the total-sample-count is an estimate of the ratio of the two areas, π/4

Multiply the result by 4 to estimate π.

**/