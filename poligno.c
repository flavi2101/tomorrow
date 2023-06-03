/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main(void) {
    
       //! showMemory(start=65520)
        int numberOfPoly ;
        struct point * arrayOfCoordenates;
        printf("inset number of sides \n");
        scanf("%d", &numberOfPoly);
        arrayOfCoordenates =  (struct point *) malloc(numberOfPoly * sizeof(struct point)); 
        initializePoly(arrayOfCoordenates, numberOfPoly);
        printPoly(arrayOfCoordenates,numberOfPoly);
        free(arrayOfCoordenates);
}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}

void printPoly(struct point *ptr, int N) {
    int i;
    for (i=0; i<N; i++) {
        printPoint(ptr[i]);
    }
}

void initializePoly(struct point * localArray, int arraySize){
    int i;
    for (i=0; i<arraySize; i++) {
          *(&(localArray +i)->x) = -i; 
          *(&(localArray +i)->y) = -i * -i;
        //localArray[i].x = -i;
        //localArray[i].y = -i*-i;
    }
}