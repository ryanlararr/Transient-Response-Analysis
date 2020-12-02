/*
* Filename:				menu.h
* Version:				1.0
* Author:				Ryan Arreola
* Student No.:			040950298
* Course Name/Number:	Numerical Computing - CST8233
* Lab Sect:				311
* Assignment #:			3
* Assignment name:		Transient-Response Analysis of 1st Order Systems
* Due Date:				December 6, 2020
* Submission Date:
* Professor:			Hala Own
* Purpose:				Defining menu functions to avoid clutter in main function.
*/

#pragma once
#include <iostream>

using namespace std;

/*********************************
* Function Name:			menuOptions
* Purpose:					Display the main menu options.
* Function In parameters:	none
* Function out parameters:	none
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
void menuOptions() {
	cout << "\n>> Choose the method for solving the ODE\n";
	cout << "1. Euler's Method\n";
	cout << "2. Runge-Kutta 2nd Order Method\n";
	cout << "3. Runge-Kutta 3rd Order Method\n";
	cout << "4. Runge-Kutta 4th Order Method\n";
	cout << "5. Exit\n";
}

/*********************************
* Function Name:			tableHeader
* Purpose:					Display the headers for the differentation table.
* Function In parameters:	none
* Function out parameters:	none
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
void tableHeader() {
	cout << "\nTime\t\t" << "Exact\t\t" << "Est.\t\t" << "Percentage Error" << endl;
}

/*********************************
* Function Name:			validateMenuInput
* Purpose:					Validation of the menu inpu tto be within options and the correct data type.
* Function In parameters:	int &opt
* Function out parameters:	none
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
void validateMenuInput(int& opt) {
	do {
		cin >> opt;
		if (!cin || (opt < 1 || opt > 5)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Try again.\n";
		}
		else break;
	} while (true);
	opt--; if (opt == 4) exit(0);
}

/*********************************
* Function Name:			validateStepInput
* Purpose:					Validation of the step input to be within options and the correct data type.
* Function In parameters:	double &h
* Function out parameters:	none
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
void validateStepInput(double& h) {
	cout << "\nChoose step size \"h\" (0.8, 0.2, 0.05)" << endl;
	do {
		cin >> h;
		if (!cin || (h != 0.8 && h != 0.2 && h != 0.05)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input. Try again.\n";
		}
		else break;
	} while (true);
}