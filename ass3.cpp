/*
* Filename: ass3.cpp
* Version: 1.0
* Author: Ryan Arreola
* Assignment name: Transient-Response Analysis of 1st Order Systems
* Purpose: Demonstration of well known methods for 1st order ODE's such as: Euler's, Runge-Kutta 1,2,3, and 4th Order Methods.
*/

#include "differentiation.h"
#include "menu.h"

using namespace std;

/*********************************
* Function Name: main
* Purpose: Main function for choosing a numerical ODE method and displaying the results.
* Function In parameters: none
* Function out parameters: none
* Version: 1.1
* Author: Ryan Arreola
**********************************/
void main() {
    int opt = 0;		//Input option
    double x = 0.0f;	//Initial coniditon of x
    double y = 3;		//Initial condiiton of y
    double h = 0.0;		//Step size

    do {
        menuOptions();
        validateMenuInput(opt);
        validateStepInput(h);

        tableHeader();
        reset(y);
        for (x = 0; x < 2 - h; x += h) {
            //Display row for current data point
            cout << fixed << setprecision(2) << x + h << "\t\t";
            cout << fixed << setprecision(3) << exact(x + h) << "\t\t";
            cout << ODE[opt](x, y, h) << "\t\t";
            error(exact(x + h), ODE[opt](x, y, h));

            //Get next y value
            y = ODE[opt](x, y, h);
        }
    } while (true);
}
