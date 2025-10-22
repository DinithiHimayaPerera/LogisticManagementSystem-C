#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_CITIES 30
#define NAME_LENGTH 50
#define FUEL_PRICE 310.00
#define VEHICLES 3

const char *vehicleType[VEHICLES]={"Van","Truck","Lorry"};
const int capacity[VEHICLES]={1000, 5000, 10000};
const float rate[VEHICLES]={30,40,80};
const float avgSpeed[VEHICLES]={60,50,45};
const float fuelEfficiency[VEHICLES]={12,6,4};

void cityManagement(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount);
void addCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount);
void removeCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount);
void renameCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount);
void checkRepetition(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int newCityId);

void distanceManagement(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES]);
void printChart(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES]);

void deliveryRequest(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES]);
int minimumDistance(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES], int start, int end);
void calculateCost(int distance, float weight, int vehicleIndex, float *deliveryCostLast,float fuelUsedLast,float *fuelCostLast, float *totalCostLast,float *profitLast, float *finalChargeLast,float *estimateTimeLast);
void printEstimation(float deliveryCost, float fuelUsed, float fuelCost,float totalCost, float profit, float finalCharge,float estimateTime,const char* startCity, const char* endCity,const char* vehicleType, float weight, int distance);


int main()
{


        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Delivery Request Handling and Delivery Cost\n");
        printf("4. Exit \n");


    return 0;
}
