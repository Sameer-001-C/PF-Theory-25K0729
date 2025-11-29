/*Question 2: A space research organization is developing a simulation to track the fuel levels of a
spacecraft as it travels between multiple planets. During its journey, the spacecraft consumes a fixed
amount of fuel at each planetary stop due to thrust and atmospheric entry. However, when it passes
through certain gravitational zones, it regenerates some fuel because of gravitational assists that
reduce energy usage. Additionally, after every fourth planetary stop, the spacecraft undergoes a
“solar recharge,” where its solar panels absorb extra energy from nearby stars, increasing its fuel
reserves. The mission control team wants to model this behavior using a recursive function
calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets) that
prints the remaining fuel after each planet in the format "Planet X: Fuel Remaining = Y", and
determines whether the spacecraft can complete its journey. The base case occurs when either the
fuel is exhausted or all planets have been visited, and the recursive case handles fuel adjustments for
each subsequent planet.
*/



//count of planets we have crossed already, in order to check every 4 planets passed, so that we can absorb solar energy
//check if count%4 == 0. this would be equal to 0 every 4 planets passed

//Objective:
//To print stuff related to remaining fuel after reaching a planet
//To determine whether the spacecraft can complete its journey or not

#include <stdio.h>

void calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets, int gravitationalRegions[]){
	//decrease fuel by fixed planetary amount
	fuel -= consumption;
	//increase planet count
	planet++;
	//if planet % 4 == 0, add some amount to the fuel, which indicates fuel regenerated due to solar recharge
	if(planet%4 == 0){
		fuel += solarBonus;
	}
	//if planet reaches a gravitational zone, increase fuel by fixed amount again
		//Here, we will use an array, which would store the locations of all the gravitational zones at that particular planet
	if(gravitationalRegions[planet-1] == 1){
		fuel += recharge;
	}		
	//base case: Check this before completing the print statement
	if(planet > totalPlanets){
		printf("\nMission Completed.\n");
		return;
	}	
	if(fuel < 0){
		printf("\nMission Failed.\n");
		return;
	}

	//the recursion case:

	printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);
	calculateFuel(fuel, consumption, recharge, solarBonus, planet, totalPlanets, gravitationalRegions);
	return;
}

int main(){
	int fuel, consumption;
	int recharge; //referring to gravitational recharge of fuel, per encounter of a gravitationl zone
	int solarBonus, totalPlanets;
	printf("Please enter total initial fuel: ");
	scanf("%d", &fuel);
	printf("Please enter fuel consumption per planet: ");
	scanf("%d", &consumption);
	printf("Please enter gravitational recharge amount: ");
	scanf("%d", &recharge);
	printf("Please enter solar bonus: ");
	scanf("%d", &solarBonus);
	printf("Please enter total planets to be visited: ");
	scanf("%d", &totalPlanets);
	
	int planet = 0;
	int gravitationalRegions[totalPlanets]; //this is our array. this array stores all the places, near a planet, where there are gravitational zones.
	
	int i;
	printf("\nPlease enter all the gravitationl regions near the corresponding planet.\n\n");
	printf("Enter 1 if gravitational zone exists. 0, if it does not.\n");
	for(i = 0; i < totalPlanets; i++){
		printf("Gravitational zone near planet %d: ", i+1);
		scanf("%d", &gravitationalRegions[i]);
	}
	printf("\n");
	calculateFuel(fuel, consumption, recharge, solarBonus, planet, totalPlanets, gravitationalRegions);
}
