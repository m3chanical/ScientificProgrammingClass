/****************************************************************************
* Program 2: pgm3.c
*
* Programmer: Carl J Anderson
*
* Due Date: February 19, 2015
*
* CSC130 Spring 2015
*
* I pledge I neither gave nor received unauthorized aid on this program.
*
* Description: 
*				
*
* Inputs: Initial height of the object in ft. 
*           
*
* Output: Falling time, impact speed in ft/sec and mph.
*			
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define G 32.2
#define DT 0.000171
double v = 0; // Velocity, so we can use it in all functions.
// Function Prototype: 
double  calculateFallingTime(double  gravity, double  startingHeight, double  dt);

int main(){
		double dt = DT; 
		double startingHeight, vMph;
		double gravity = G;
		
		printf("\nProgram to calculate fall time and impact speed of\n");
		printf("a falling object dropped from a specific height.\n\n");      
		
		printf("Enter initial height in Feet: ");
		scanf("%lf", &startingHeight);
      
      // Position function is y = -16.1t^2 + startingHeight
      // Velocity function is y' = -32.2t
      // Acceleration function is y'' = -32.2
      // Y axis is height, X axis is time
      
      printf("dt is: %lf\n", dt);
      printf("gravity is: %lf\n", gravity);
      printf("startingHeight is: %lf\n", startingHeight);
		
		printf("\nFalling Time = %lf\n", calculateFallingTime(gravity, startingHeight, dt));
		
		// To calculate MPH from ft/sec, we will utilize dimensional analysis.
		// ft to miles, and seconds to hours: x ft/sec * 1mi/5280ft * 60sec/min * 60min/1hr
		printf("Impact Speed = %f feet/sec\n", v);
		vMph = (v / 5280) * 3600;
		printf("Impact speed = %f MPH\n", vMph);
		
		return 0;
}

double  calculateFallingTime(double gravity, double startingHeight, double dt) {
	double t = 0.0;
   double p = startingHeight;
	// initial velocity is zero. 	
	while (p >= 0){
		//v = v + gravity * dt;
		p = ((-(gravity/2)) * (t * t)) + startingHeight;
		t += dt;
	}	
   v = -gravity * t;
	return t;
}