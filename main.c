#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_CITIES 30
#define NAME_LENGTH 50
#define FUEL_PRICE 310.00
#define VEHICLES 3

const char *vehicleType[VEHICLES]= {"Van","Truck","Lorry"};
const int capacity[VEHICLES]= {1000, 5000, 10000};
const float rate[VEHICLES]= {30,40,80};
const float avgSpeed[VEHICLES]= {60,50,45};
const float fuelEfficiency[VEHICLES]= {12,6,4};

void cityManagement(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount);
void addCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount);
void removeCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount);
void renameCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount);
int checkRepetition(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int newCityId);

void distanceManagement(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES]);
void printChart(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES]);

void deliveryRequest(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES]);
int minimumDistance(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES], int start, int end);
void calculateCost(int distance, float weight, int vehicleIndex, float *deliveryCostLast,float fuelUsedLast,float *fuelCostLast, float *totalCostLast,float *profitLast, float *finalChargeLast,float *estimateTimeLast);
void printEstimation(float deliveryCost, float fuelUsed, float fuelCost,float totalCost, float profit, float finalCharge,float estimateTime,const char* startCity, const char* endCity,const char* vehicleType, float weight, int distance);


int main()
{
    int choice;
    char cityName[MAX_CITIES][NAME_LENGTH];
    int cityCount=0;
    int distance[MAX_CITIES][MAX_CITIES];

    printf("\tLogistic Management System");
    printf("\n\t==========================");

    do
    {
        printf("\n\n\tMain Menu\n\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Delivery Request Handling and Delivery Cost\n");
        printf("4. Exit \n");

        printf("\nEnter the choice :");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            cityManagement(cityName,&cityCount);
            break;

        case 2:
            distanceManagement(cityName,cityCount,distance);
            break;

        case 3:
            deliveryRequest(cityName,cityCount,distance);
            break;

        case 4:
            printf("\nExit from the Logistic Management System................!\n");
            break;

        default:
            printf("\nInvalid Choice.\n");


        }

    }
    while(choice!=4);


    return 0;
}
void cityManagement(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount)
{
    int choice;
    do
    {

        printf("\n\tCity Management System\n");
        printf("\t----------------\n");
        printf("1-Add a new city\n");
        printf("2-Rename city\n");
        printf("3-Remove city\n");
        printf("4-Exit\n");

        printf("\nEnter your choice :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addCity(cityName,cityCount);
            break;

        case 2:
            renameCity(cityName,cityCount);
            break;

        case 3:
            removeCity(cityName,cityCount);
            break;

        case 4:
            printf("\nExiting from the City Management System\n");
            break;

        default:
            printf("\nInvalid choice.........!\n\n");


        }
    }
    while(choice!=4);
}
void addCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount)
{
    int newCityCount;
//check number of cities reaches the maximum number[30] before entering new cities
    if(*cityCount>=MAX_CITIES)
    {
        printf("\nSorry.....\nYou have not enough space to enter another city.\n");
        return;
    }
    printf("\nEnter the number of cities that you want to enter :");
    scanf("%d",&newCityCount);

    //check if the number of cities reaches the maximum number[30] after entering new cities
    if(*cityCount+newCityCount>MAX_CITIES)
    {
        printf("\nSorry.....\nYou have not enough space %d cities",newCityCount);
        return;
    }
//print the list if the all cities
    printf("Enter the city name :");
    printf("\nNumber\tCity Name\n");

    for(int i=0; i<newCityCount; i++)
    {
        printf("%d",*cityCount+1);
        scanf("%s",cityName[*cityCount]);

        int duplicates=checkRepetition( cityName,*cityCount,*cityCount);
        //check if the city name you entered already exists in the system
        if(duplicates==1)
        {
            printf("This city name is already exists.....!\n");
            i--;
        }
        else
        {
            (*cityCount)++;
            printf("City added succtssfully.........!\n\n");
        }

    }

}
void removeCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount)
{

}
void renameCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount)
{

}
int checkRepetition(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int newCityId)
{
for(int i=0;i<cityCount;i++){
    if(i==newCityId){
        continue;
    }
    int k=0;
    int same=1;
    //check characters match and both strings are not finished
    while(cityName[i][k]==cityName[newCityId][k]&&cityName[i][k]!='\0'&&cityName[newCityId][k]!='0'){
        k++;
    }

    if(cityName[i][k]=='\0'&&cityName[newCityId][k]=='\0'){
        return 1; //found a duplicate city name
    }
}
return 0; //not found a duplicate city name
}
void distanceManagement(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES])
{

}
void printChart(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES])
{

}
void deliveryRequest(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES])
{

}
int minimumDistance(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES], int start, int end)
{

}
void calculateCost(int distance, float weight, int vehicleIndex, float *deliveryCostLast,float fuelUsedLast,float *fuelCostLast, float *totalCostLast,float *profitLast, float *finalChargeLast,float *estimateTimeLast)
{

}
void printEstimation(float deliveryCost, float fuelUsed, float fuelCost,float totalCost, float profit, float finalCharge,float estimateTime,const char* startCity, const char* endCity,const char* vehicleType, float weight, int distance)
{

}
