/*Haw Distance*/

/*Created by Garcia Angus, German */

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>

/*declaring prototypes*/

double maxDistance(double a[][2], int length, int *location1, int *location2);
double degToRad(double deg);
double distanceKm(double lat1, double lon1, double lat2, double lon2);

#define M_PI 3.14159265358979323846 // pi values
#define  RADIUS 6378.388   // radius of earth.

int main(void)
{
	/*The arrays for latitude and longitude*/
	int size = 7;
	const char *locationName[] = { "Haw Hamburg ","Eiffel Tower","Palma de Mallorca","Las Vegas","Copacabana"
		,"Waikiki Beach","Surfer’s Paradise" };
	double locations[7][2] = {
	{ 53.557078 ,10.023109 },
	{ 48.858363,2.294481 },
	{ 39.562553,2.661947 },
	{ 36.156214,-115.148736 },
	{ -22.971177,-43.182543 },
	{ 21.281004,-157.837456 },
	{ -28.002695,153.431781 } };

	int loc1;
	int loc2;

	double distance = maxDistance(locations, size, &loc1, &loc2);
	printf(" < %s > and < %s > have the largest distance (< %f > Km).\n", locationName[loc1], locationName[loc2], distance);
	printf("-----------------------------------------------------\n");
	printf("HAW HAMBURG      |53.557078 |  10.023109 |%5.1f    km\n");
	printf("Eiffel Tower     |48.858363 |  2.294481  |%5.1f    km\n");
	printf("Palma de Mallorca|39.562553 |  2.661947  |%5.1f    km\n");
	printf("Las Vegas        |36.156214 | -115.148736|%5.1f    km\n");
	printf("Copacabana       |-22.971177|  -43.182543|%5.1f    km\n");
	printf("Waikiki Beach    |21.281004 | -157.837456|%5.1f    km\n");
	printf("Surfer's Paradise|-28.002695|  153.431781|%5.1f    km\n");
	getchar();
	return 0;
}

/*Function for degrees to radians*/

double degToRad(double deg)
{
	return deg * M_PI / 180;
}

double maxDistance(double a[][2], int length, int *location1, int *location2)
{
	double tmpDistance, max = 0.0;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			tmpDistance = distanceKm(a[i][0], a[i][1], a[j][0], a[j][1]);
			if (tmpDistance > max) {
				max = tmpDistance;
				*location1 = i;
				*location2 = j;
			}
		}
	}

	return max;
}
/*Function for calculating distance*/

double distanceKm(double lat1, double lon1, double lat2, double lon2)
{
	return RADIUS * acos(sin(degToRad(lat1)) * sin(degToRad(lat2))
		+ cos(degToRad(lat1)) * cos(degToRad(lat2)) * cos(degToRad(lon2 - lon1)));
}