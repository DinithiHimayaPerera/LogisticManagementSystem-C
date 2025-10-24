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
void calculateCost(int distance, float weight, int vehicleIndex, float *deliveryCostLast,float *fuelUsedLast,float *fuelCostLast, float *totalCostLast,float *profitLast, float *finalChargeLast,float *estimateTimeLast);
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
        printf("%d\t",*cityCount+1);
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
    int index;
    if(*cityCount==0)
    {
        printf("\nYou did not enter any city name.\n");
        return;
    }

    printf("\nCities that were entered to the system.\n");

    printf("\n\tCities\n");
    printf("\t--------\n");

    for(int i=0; i<*cityCount; i++)
    {
        printf("%d\t%s\n",i+1,cityName[i]);
    }


    printf("\n\tRemove City\n");
    printf("\t------------\n\n");
    printf("Enter the index number of the city you want to remove :");
    scanf("%d",&index);


    int cityNo=index-1;

    if(cityNo>=*cityCount||cityNo<0)
    {
        printf("\nNo city found with that index.\n");
        return;
    }

    for(int i=cityNo; i<(*cityCount-1); i++)
    {
        int k=0;

        while((cityName[i][k]=cityName[i+1][k])!='\0')
        {
            k++;
        }
    }
    (*cityCount)--;
    printf("\nSuccessfully Removed......!\n");

}
void renameCity(char cityName[MAX_CITIES][NAME_LENGTH],int *cityCount)
{
    if(*cityCount==0)
    {
        printf("\nYou did not enter city name.\n");
        return;
    }
    printf("\nCities that were entered to the system.\n");

    printf("\n\tCities\n");
    printf("\t-------\n");
    for(int i=0; i<*cityCount; i++)
    {
        printf("%d\t%s\n",i+1,cityName[i]);
    }
    int index;

    printf("\n\tRename City\n");
    printf("\t-------------\n");
    printf("Enter the index number of the city you want to remove :");
    scanf("%d",&index);

    int cityNo=index-1;

    if(cityNo>=*cityCount||cityCount<0)
    {
        printf("\nNo city found with that index.\n");
        return;
    }
    printf("\nThe city name entered before :%s\n",cityName[cityNo]);

    printf("\nNew name :");
    scanf("%s",&cityName[cityNo]);

    printf("\nSuccessfully Renamed.........!\n");
}
int checkRepetition(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int newCityId)
{
    for(int i=0; i<cityCount; i++)
    {
        if(i==newCityId)
        {
            continue;
        }
        int k=0;
        int same=1;
        //check characters match and both strings are not finished
        while(cityName[i][k]==cityName[newCityId][k]&&cityName[i][k]!='\0'&&cityName[newCityId][k]!='0')
        {
            k++;
        }

        if(cityName[i][k]=='\0'&&cityName[newCityId][k]=='\0')
        {
            return 1; //found a duplicate city name
        }
    }
    return 0; //not found a duplicate city name
}
void distanceManagement(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES])
{
    if(cityCount<2)
    {
        printf("\nYou need at least two cities to manage distance management system.\n");
        return;
    }
    printf("\n\tDistance Management System");
    printf("\n\t==========================");
    for(int i=0; i<cityCount; i++)
    {
        for(int j=i; j<cityCount; j++)
        {
            if(i==j)
            {
                distance[i][j]=0;
                continue;
            }
            printf("\nDistance from %s to %s (km) :",cityName[i],cityName[j]);

            scanf("%d",&distance[i][j]);

            distance[j][i]=distance[i][j];
        }
        printf("\n");
    }
    printChart(cityName,cityCount,distance);
    printf("\n\n");
}
void printChart(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES])
{
    if(cityCount==0)
    {
        printf("\nYou did not enter city name.\n");
        return;
    }
    printf("\n\tDistance Chart");
    printf("\n\t--------------\n");

    printf("%-10s","");

    for(int i=0; i<cityCount; i++)
    {
        printf("|%-10s",cityName[i]);
    }
    printf("|\n");

    for(int k=0; k<cityCount; k++)
    {
        printf("%-10s",cityName[k]);

        for(int m=0; m<cityCount; m++)
        {
            printf("|%-10d",distance[k][m]);
        }
        printf("|\n");
    }
    printf("\n");

}
void deliveryRequest(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES])
{
 if(cityCount<2)
    {
        printf("\nYou need at least two cities to manage distance management system.\n");
        return;
    }

     printChart(cityName,cityCount,distance);

     int startingPoint, endPoint ,vehicleNumber;

     float weight;

     printf("Enter the index number of starting point(must be between 1 and %d  :", cityCount);
     scanf("%d",&startingPoint);
     printf("Enter the index number of destination point(must be between 1 and %d  :", cityCount);
     scanf("%d",&endPoint);

     if(startingPoint==endPoint){
        printf("The starting point and destination point can not be the same. \n");
        return;
     }
     printf("Weight :");
     scanf("%f",&weight);

     printf("Vehicle Type :");
     printf("\n(1=Van , 2=Truck , 3=Lorry)\n");
     scanf("%d",&vehicleNumber);

     if(vehicleNumber<1 || vehicleNumber>3){
        printf("\nInvalid vehicle number.\n");
        return;
     }
     if(weight>capacity[vehicleNumber-1]){
        printf("Sorry....The weight exceeds the vehicle capacity of %d kg.\n",capacity[vehicleNumber-1]);
       return;
     }
     int minDistance= minimumDistance(cityName,cityCount,distance,startingPoint-1,endPoint-1);

     if(minDistance>=999999){
        printf("There is no available route.\n");
    return;
     }
     float deliveryCost, fuelUsed, fuelCost, totalCost, profit, finalCharge, estimateTime;

     calculateCost(minDistance,weight, vehicleNumber-1, &deliveryCost,&fuelUsed, &fuelCost, &totalCost, &profit, &finalCharge, &estimateTime);
     printEstimation(deliveryCost, fuelUsed, fuelCost, totalCost, profit, finalCharge,estimateTime, cityName[startingPoint-1], cityName[endPoint-1], vehicleType[vehicleNumber-1], weight, minDistance);

}
int minimumDistance(char cityName[MAX_CITIES][NAME_LENGTH],int cityCount, int distance[MAX_CITIES][MAX_CITIES], int start, int end)
{
    int minimumDistanceRoute=distance[start][end];
//when you haven't a direct route
    if(minimumDistanceRoute==0 && start!=end)
    {
        minimumDistanceRoute=999999;
    }
    for(int i=0; i<cityCount; i++)
    {
        if(i==start || i==end)
        {
            continue;
        }
        if(distance[start][i]>0 && distance[i][end]>0)
        {
            int totalDistance=distance[start][i]+distance[i][end];
            if(totalDistance<minimumDistanceRoute)
            {
                minimumDistanceRoute=totalDistance;
            }
        }
    }
    for(int i=0; i<cityCount; i++)
    {
        if(i==start || i==end)
        {
            continue;
        }
        for(int j=0; j<cityCount; j++)
        {
            if(j==start || j==end || j==i)
            {
                continue;
            }
            if(distance[start][i]>0 && distance[i][end]>0 && distance[i][j]>0)
            {
                int totalDistance=distance[start][i]+ distance[i][end]+ distance[i][j];
                if(totalDistance<minimumDistanceRoute)
                {
                    minimumDistanceRoute=totalDistance;
                }
            }
        }
    }
    return minimumDistanceRoute;
}
void calculateCost(int distance, float weight, int vehicleIndex, float *deliveryCostLast,float *fuelUsedLast,float *fuelCostLast, float *totalCostLast,float *profitLast, float *finalChargeLast,float *estimateTimeLast)
{
float relatedRate=rate[vehicleIndex];
float speedS=avgSpeed[vehicleIndex];
float efficiency=fuelEfficiency[vehicleIndex];

*deliveryCostLast=(float)distance*relatedRate*(1+(weight/10000.00));
*fuelUsedLast=(float)distance/efficiency;
*fuelCostLast=*fuelUsedLast*FUEL_PRICE;
*totalCostLast=*deliveryCostLast+*totalCostLast;
*profitLast=*totalCostLast*0.25;
*finalChargeLast=*totalCostLast+*profitLast;
*estimateTimeLast=(float)distance/speedS;


}
void printEstimation(float deliveryCost, float fuelUsed, float fuelCost,float totalCost, float profit, float finalCharge,float estimateTime,const char* startCity, const char* endCity,const char* vehicleType, float weight, int distance)
{
printf("\n===============================================================\n");
printf("             DELIVERY COST ESTIMATION\n");
printf("---------------------------------------------------------------\n");
printf("From:               %s\n",startCity);
printf("To:                 %s\n",endCity);
printf("Vehicle:            %s\n",vehicleType);
printf("Weight:             %.2f kg\n",weight);
printf("Shortest Distance:  %d km\n",distance);
printf("---------------------------------------------------------------\n");
printf("Base Delivery Cost: %.2f LKR\n, delivery cost");
printf("Estimated Fuel Used:%.2f L\n", fuelUsed);
printf("Fuel Cost:          %.2f LKR\n",fuelCost);
printf("Total Operational Cost:%2f LKR\n",fuelCost);
printf("Profit Margin(25%%):%.2f LKR\n",profit);
printf("------------------------------------------------\n");
printf("FINAL CUSTOMER CHARGE: %2f LKR\n", finalCharge);
printf("ESTIMATED DELIVERY TIME: %.2f hours\n", estimateTime);
printf("================================================\n");
}
