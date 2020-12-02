/*
* Filename:				differentiation.h
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
* Purpose:				Defining functions used for differentiation.
*/

#pragma once

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

/*********************************
* Function Name:			actual
* Purpose:					Calculation of the actual value of y with respect to x.
* Function In parameters:	double x, double y
* Function out parameters:	double: actual value of y at x.
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
double exact(double x) {
	return 0.1 * cos(4 * x) + 0.2 * sin(4 * x) + 2.9 * exp(-2 * x);
}

/*********************************
* Function Name:			derive
* Purpose:					Calculates the derivative given x and y.
* Function In parameters:	double x, double y
* Function out parameters:	double: The derivative of x and y
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
double derive(double  x, double y) {
	double test = cos(4 * x);
	double t2 = 2 * y;
	return cos(4 * x) - 2 * y;
}

/*********************************
* Function Name:			rk2
* Purpose:					Calculates next y using 2nd Order Runge-Kutta
* Function In parameters:	double x, double y, double h
* Function out parameters:	Approximated value of y at the next data point.
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
double rk2(double x, double y, double h) {
	double k1 = derive(x, y);
	double k2 = derive(x + h, y + k1 * h);
	return y + h * (k1 + k2) / 2;
}

/*********************************
* Function Name:			rk3
* Purpose:					Calculates next y using 3rd Order Runge-Kutta
* Function In parameters:	double x, double y, double h
* Function out parameters:	Approximated value of y at the next data point.
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
double rk3(double x, double y, double h) {
	double k1 = derive(x, y);
	double k2 = derive(x + (h / 2), y + (1 / 2) * k1 * h);
	double k3 = derive(x + h, y - k1 * h + 2 * k2 * h);
	return y + h * (k1 + 4 * k2 + k3) / 6;
}

/*********************************
* Function Name:			rk4
* Purpose:					Calculates next y using 4th Order Runge-Kutta
* Function In parameters:	double x, double y, double h
* Function out parameters:	Approximated value of y at the next data point.
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
double rk4(double x, double y, double h) {
	double k1 = derive(x, y);
	double k2 = derive(x + h / 2, y + (k1 * h / 2));
	double k3 = derive(x + h / 2, y + (k2 * h / 2));
	double k4 = derive(x + h, y + k3 * h);
	return y + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}

/*********************************
* Function Name:			euler
* Purpose:					Calculates next y using the euler method.
* Function In parameters:	double x, double y, double h
* Function out parameters:	Approximated value of y at the next data point.
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
double euler(double x, double y, double h) {
	return y + h * derive(x, y);
}

/*********************************
* Function Name:			ODE
* Purpose:					Gathers all the ODE methods into one function to be called on dynamically through a pointer.
* Function In parameters:	double, double, double
* Function out parameters:	Approximated value of y at the next data point.
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
double (*ODE[])(double, double, double) = { euler, rk2, rk3, rk4 };

/*********************************
* Function Name:			error
* Purpose:					Calculates the truncation error of a the ODE
* Function In parameters:	double, double
* Function out parameters:	Truncation error
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
void error(double analytical, double numerical) {
	cout << setprecision(2) << abs(1 - (numerical / analytical)) * 100 << endl;
}

/*********************************
* Function Name:			reset
* Purpose:					Resets the y value to the intiial condition.
* Function In parameters:	double& y
* Function out parameters:	Initial y value
* Version:					1.0
* Author:					Ryan Arreola
**********************************/
void reset(double &y) { y = 3.0; }