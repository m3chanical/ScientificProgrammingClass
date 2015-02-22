/****************************************************************************
* Program 2: pgm2.c
*
* Programmer: Carl J Anderson
*
* Due Date: February 5, 2015 0300
*
* CSC130 Spring 2015
*
* I pledge I neither gave nor received unauthorized aid on this program.
*
* Description: This program prompts the user for two ordered pair coordinate points and then
*				calculates the Slope, Y-intercept, and Line Equation based on the coordinates entered.
*
* Inputs: scanf() for TWO coordinate points, totalling FOUR inputs. And request a 3rd x value
*           which the program will use to calculate the corresponding Y. 
*
* Output: Slope, Y-intercept, Line Equation based on the coordinate points entered.
*			Additionally, it will display error information. 
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
 
// Function Prototypes declared here:
float calculateSlope(float* op1, float* op2);
float yIntercept(float* op1, float* slope);
float yGivenX(float *X, float *slope, float *intercept);
float coordinateInput();

void main(){     
	float thirdY, thirdX;
	float slope, intercept; 
	float op1[2], op2[2];
	int i;

	// First Ordered Pair (X,Y):      
	printf("\n\nEnter the first X coordinate: ");
	op1[0] = coordinateInput();
	printf("Enter the first Y coordinate: ");
	op1[1] = coordinateInput();
	
	// Second Ordered Pair (X, Y):
	printf("Enter the second X coordinate: ");
	op2[0] = coordinateInput();
	printf("Enter the second Y coordinate: ");
	op2[1] = coordinateInput();
	
           
	if (op1[0] == op2[0]){
		printf("\n\nBecause the X values are the same, the slope is Infinity. Therefore there can be no line equation\n\n");
		exit(0);
	}
    
	slope = calculateSlope(op1, op2);
	intercept = yIntercept(op1, &slope);
    
	printf("\nslope is: %+1.6f\n", slope);
	printf("\ny-intercept is: %+1.6f\n", intercept);
     
	printf("\nLine Equation is:\n\t Y = %+1.6f * X + %+1.6f\n\n", slope, intercept);

	// Here we prompt for another X coordinate so we may calculate 
	// 			  it's corresponding Y based on the equation above	
	printf("Now please enter a third X coordinate: ");
	thirdX = coordinateInput();
	thirdY = yGivenX(&thirdX, &slope, &intercept);
	printf("\nIts corresponding Y value is: %+1.6f\n\n", thirdY);	
}
     
float calculateSlope(float* op1, float* op2){
	// To calculate the slope given two ordered pair we
	// do the following:
	//      slope = rise / run;
	//      slope = (y2 - y1) / (x2 - x1)  
	return (op2[1] - op1[1]) / (op2[0] - op1[0]);
}
     
float yIntercept(float* op1, float* slope){
	// To calculate the Y-intercept given two ordered pair
	// we first find the slope, then solve for B using a given ordered pair 	
	// and basic algebra with the slope-intercept equation.
	// Also, the point/slope form can be used when given the slope and one point.  
	//
	// Slope Intercept form: Y = mX + B    
	//      Solving for B we get:
	//              B = Y - mX
	// Point/Slope Form:     Y1 - Y = m(X1 - X)
     
	// We only need one ordered pair to calculate the line equation, so let's take ordered pair 1:
	return (op1[1] - (*slope * op1[0]));
}
     
float coordinateInput(){
	// Moved user input to a function to keep Main a little cleaner.
	float coordinate;
	if (scanf(" %f", &coordinate) == 1){
		return coordinate;
	} else {
		printf("\n\nYou did not enter a valid coordinate\n\n");
		exit(0);		
	}
}

float yGivenX(float* X, float* slope, float* intercept) {
	// This calculates a Y value based on the line equation determined from the first two coordinates
	// and a given X value. 
	return (*slope * *X + *intercept); // Have to derefence the pointers otherwise 
                                      // math will be done on memory address values
}
