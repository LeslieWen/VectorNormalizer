/*
Source: assign2funcs.h
Author: Leslie Wen

*/


#include<string.h>
#include<float.h>
#include<stdbool.h>
#include<math.h>
#include<ctype.h> 

#define ERROR_CODE 1
#define MIN 1 
#define MAX 9

void getInput(bool hasError,float vectorArr[],float normArr[],float vectorLength); //Read Vector
void displayVector(float vectorArr[],int rightBound); // Prints the vector
void displayNorm(float vectorArr[],float normArr[],int rightBound); // Prints the normalized vector
