/*
Source: assign2funcs.c
Author: Leslie Wen

*/
#include "assign2funcs.h"

void getInput(bool hasError,float vectorArr[],float normArr[],float vectorLength){
    char arr[50];   
    int *x=fgets(arr,50,stdin);
    char delim[]=" ";
    char *ptr =strtok(arr,delim);
    int counter=0;
    
    if(x==NULL){
        if(hasError==true){
            exit(ERROR_CODE);
        }
        exit(0);
    }
    while(ptr != NULL){
        vectorArr[counter]=atof(ptr);
        vectorLength=vectorArr[0]; 
        for(int i=0;i<strlen(ptr);i++){
            if(isalpha(ptr[i])!=0){
                hasError=true;
                fprintf( stderr, "BAD INPUT\n");
                getInput(hasError,vectorArr,normArr,vectorLength);
            }
        }
        if(vectorLength==0){ // Exit if start of input str is 0
            if(hasError==true){
                exit(ERROR_CODE);
            }
            exit(0);
        }
        counter++;
        ptr=strtok(NULL,delim);
    }
    if(vectorArr[0]>MAX||vectorArr[0]<MIN){
        fprintf( stderr, "BAD INPUT\n");
        hasError=true;
        vectorLength=0;
        getInput(hasError,vectorArr,normArr,vectorLength);
    }
    while(counter<=vectorLength){ //Check if there's still some elements in next lines
        fgets(arr,50,stdin);
        char delim[]=" ";
        char *ptr =strtok(arr,delim);
        while(ptr != NULL){
            vectorArr[counter]=atof(ptr);
            for(int i=0;i<strlen(ptr);i++){
                if(isalpha(ptr[i])!=0){
                    hasError=true;
                    fprintf( stderr, "BAD INPUT\n");
                    getInput(hasError,vectorArr,normArr,vectorLength);
                }
            }
            counter++;
            ptr=strtok(NULL,delim);
        }
    }    
    displayVector(vectorArr,vectorLength);
    displayNorm(vectorArr,normArr,vectorLength);
    
    getInput(hasError,vectorArr,normArr,vectorLength);
}
void displayVector(float arr[],int rightBound){
    printf("VECTOR: [ ");
    for(int i=1;i<=rightBound;i++){
        printf("%0.3f",arr[i]); 
        if(i!=rightBound){
            printf(", ");
        }else{
            printf(" ");
        }
    }
    printf("] ");
}
void displayNorm(float vectorArr[],float normArr[],int rightBound){
    float N = 0;
   
    for(int i=1;i<=rightBound;i++){
        N=N+vectorArr[i]*vectorArr[i];
    }  
    N=sqrt(N);
    printf("NORMALIZED: [ ");
    for(int i=1;i<=rightBound;i++){
        normArr[i]=vectorArr[i]/N;
        printf("%0.3f",normArr[i]);
        if(i!=rightBound){
            printf(", ");
        }else{
            printf(" ");
        }
    }
    printf("]\n");
}
