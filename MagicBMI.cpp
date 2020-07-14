/*
 * MagicBMI.cpp
 *
 * Copyright (c) 2020 Drew Markel
 * All rights reserved.
*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std; // Reduce repetition

int main()
{
	/* Declare variables */
	int userPreference; // userPreference
	float userWeight; // userWeight
	float userHeight; // userHeight
	int userHeightFT; // userHeightFT
	float userHeightIN; // userHeightIN
	float userBMI; // userBMI
	string healthStatus; // healthStatus

	/* Introduction */
	cout << endl << "MagicBMI" << endl; // Title
	cout << endl << "Copyright (c) 2020 Drew Markel" << endl; // Copyright
	cout << "All right reserved." << endl; // Rights

	/* Get the user's preferred measurement system */
	cout << endl << "What measurement system would you like to use?" << endl; // Ask the user for their preferred measurement system
	cout << endl << "1. Imperial" << endl; // Imperial
	cout << "2. Metric" << endl; // Metric
	cout << endl << "Option: "; // Get user preference
	cin >> userPreference; // Get user preference
	cout << endl; // Add spacing

	/* Execute instructions based on the value of userPreference */
	if (userPreference == 1) // Imperial
	{
		/* Get user weight */
		cout << "Weight (lbs): "; // Weight
		cin >> userWeight; // Weight
		cout << endl; // Add spacing

		/* Get user height */
		cout << "Height (ft): "; // Height
		cin >> userHeightFT; // Height
		cout << endl << "Height (in): "; // Height
		cin >> userHeightIN; // Height
		cout << endl; // Add spacing

		/* Convert values to metric */
		userWeight /= 2.205; // Weight
		userHeight = (userHeightFT / 3.281) + (userHeightIN / 39.37); // Height
	}
	else if (userPreference == 2) // Metric
	{
		/* Get user weight */
		cout << "Weight (kg): "; // Weight
		cin >> userWeight; // Weight
		cout << endl; // Add spacing

		/* Get user height */
		cout << "Height (m): "; // Height
		cin >> userHeight; // Height
		cout << endl; // Add spacing
	}
	else // Handle invalid option
	{
		cout << endl << "Please select a valid option." << endl; // Tell user the issue
		terminate(); // Terminate the program
	}

	/* Calculate BMI */
	userBMI = userWeight / pow(userHeight, 2); // BMI

	/* http://faculty.salisbury.edu/~dxdefino/RoundOff.htm */
	userBMI = float(int(userBMI * 10 + 0.5)) / 10; // Round BMI

	/* Calculate the health status */
	if (userBMI < 18.5) // Underweight
	{
		healthStatus = "Underweight"; // Assign new health status
	}
	else if (18.5 <= userBMI && userBMI <= 24.9) // Normal Weight
	{
		healthStatus = "Normal Weight"; // Assign new health status
	}
	else if (25 <= userBMI && userBMI <= 29.9) // Overweight
	{
		healthStatus = "Overweight"; // Assign new health status
	}
	else if (userBMI >= 30) // Obese
	{
		healthStatus = "Obese"; // Assign new health status
	}
	else // Error
	{
		healthStatus = "An error occurred while calculating the health status."; // Assign new health status
	}

	/* Print calculations */
	cout << "\n\033[1m" // Begin bold text
		<< "BMI: " // BMI
		<< setprecision(1) // Only show 4 characters
		<< fixed // Prevent rounding
		<< userBMI // BMI
		<< " " // Add a space
		<< healthStatus // healthStatus
		<< endl // Add spacing
		<< endl // Add spacing
		<< "\033[0m"; // End bold text

	return 0;
}