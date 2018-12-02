/*Route length(1 - D arrays)*/
/*Created by Garcia Angus, German */

#define _CRT_SECURE_NO_DEPRECATE
#define M_PI 3.14159265358979323846
#define  RADIUS 6378.388   // radius of earth.



#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double degToRad(double deg);
double distanceKm(double lat1, double lon1, double lat2, double lon2);
double hawRoundTrip(double latitude[], double longitude[], int size);

int main(void)

/* Declaring variables */
{
	double distanceKm;
	double longitudes[] = { 10.022918, 10.021343, 10.020297,10.014906,10.015426,10.016568,10.023244,10.022142,10.022632 };
	double latitudes[] = { 53.557029, 53.557166, 53.557274,53.560288,53.561306,53.562015,53.558241,53.557900,53.557203 };
	int size = sizeof longitudes / sizeof longitudes[0];

	distanceKm = hawRoundTrip(latitudes, longitudes, size);
	printf("Round trip distance of the HAW is: %.2f km\n", distanceKm);

	getchar();
	return 0;
}

double degToRad(double deg)
{
	return deg * M_PI / 180;
}

double distanceKm(double lat1, double lon1, double lat2, double lon2)
{
	double f;
	f = sin(degToRad(lat1)) * sin(degToRad(lat2)) + cos(degToRad(lat1)) * cos(degToRad(lat2)) * cos(degToRad(lon2 - lon1));
	return RADIUS * acos(f);
}

/*Function for determining the maximum distance */
double hawRoundTrip(double latitude[], double longitude[], int size)
{
	double sum = 0.0;

	for (int i = 0; i < size - 1; i++)
	{
		sum += distanceKm(latitude[i], longitude[i], latitude[i + 1], longitude[i + 1]);
	}
	return sum;
}