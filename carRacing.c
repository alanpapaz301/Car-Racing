#include "carRacing.h"



void init(char matrix[ROWS][COLUMNS]){
	int i,j;
	for(i = 0; i<ROWS;i++){
		for(j=0; j<=COLUMNS-1; j++){
		matrix[i][j] = ' ';
			if(i%2 != 0){
				matrix[i][COLUMNS-1] = '*';
				matrix[i][0] = '*';
			}
			if(i%2 == 0){
				matrix[i][1] = 178;
				matrix[i][COLUMNS - 2] = 178;
			}	
		}
	}
}
	
	
	
	
	
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }

        printf("\n");
		
		}
}