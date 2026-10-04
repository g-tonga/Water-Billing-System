#include <stdio.h>
int main(){
    int houses;

    printf("How many households do you wish to check? ");
    scanf("%d",&houses);

    int houseProcessed = 0;
    int validHouses = 0;
    int invalidHouses = 0;
    float totalWaterConsumed = 0;
    float totalRevenue = 0;
    float averageConsumption;
    for(int h = 1;h<=houses;h++){

   char Mnum[10];
   float consumedWater;
    float waterCharge;
    char *category;
    char *ConserveMessage;

   printf("\nEnter meter number;");
   scanf("%s",Mnum);
   printf("Enter amount of water consumed:");
   scanf("%f",&consumedWater);

   //Calculate the water charge using a tariff
    if( consumedWater < 0){
    printf("Invalid consumption");
    invalidHouses++;
  continue;
   }

   validHouses++;

    if(consumedWater >=0 && consumedWater<=6){
    waterCharge = 50 * consumedWater;
     category = "Low Usage";
     ConserveMessage = "Water usage is within the low-usage range.";
   }
   else if(consumedWater >6 && consumedWater <=20){
    waterCharge = (6 * 50) + ((consumedWater - 6) * 60);
    category = "Normal Usage";
    ConserveMessage = "Please continue monitoring your water usage.";
   }
   else if(consumedWater >20 && consumedWater<=50){
    waterCharge = (6 * 50) + ((20 - 6) * 60) +((consumedWater - 20) * 75);
    category = "High Usage";
    ConserveMessage = "Consider reducing unnecessary water consumption.";
   }
   else if(consumedWater>50){
    waterCharge = (6 * 50) + ((20 - 6) * 60) + ((50 - 20) * 75) + ((consumedWater - 50)* 90);
    category = "Very High Usage";
    ConserveMessage = "High consumption detected.Please conserve water.";
   }

   totalWaterConsumed+=consumedWater;
   totalRevenue+=waterCharge;
   houseProcessed=h;

   printf("\nHouse number %d\n",h);
   printf("Meter Number: %s\n",Mnum);
   printf("Consumption: %.2f m3\n",consumedWater);
   printf("Usage Category: %s\n",category);
   printf("Water Bill: Ksh %.2f\n",waterCharge);
   printf("%s\n",ConserveMessage);


  if(validHouses > 0){
    averageConsumption = totalWaterConsumed / validHouses;
  }
  else{
   return 0;
  }


  }
    //SUMMARY
  printf("\nHouseholds processed: %d\n",houseProcessed);
  printf("Valid households: %d\n",validHouses);
  printf("Invalid households: %d\n",invalidHouses);
  printf("Total water consumed: %.2f\n",totalWaterConsumed);
  printf("Total revenue: Ksh %.2f\n",totalRevenue);
  printf("Average consumption: %.2f\n",averageConsumption);

  return 0;

    }



