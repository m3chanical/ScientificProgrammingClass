/****************************************************************************
 * Program 1: Pgm1.c
 *
 * Programmer: Carl Anderson
 *
 * Due Date: Thursday January 22 - before class
 *
 * CSC130 Spring 2015
 *
 * Pledge: I have neither given nor received unauthorized aid on the program.
 *
 * Description: Program that uses printf() function to print a basic "Hello, World" statement
 *	 			to the command line.
 *
 * Inputs: None
 *
 * Output: Print to the console the message “Hello World from <your_name_hear>!” where <your_name_here> is your name. 
 *
 ***************************************************************************/


#include <stdio.h>

int main(int argc, char* argv[]) {
	char *name = "Carl Anderson";
	printf("Hello World from %s!\n", name);
	return 0;
   
}



