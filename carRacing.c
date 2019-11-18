#include "carRacing.h"

void runTime(char matrix[ROWS][COLUMNS],int speedControl){
	
	
	
	
}

void init(char matrix[ROWS][COLUMNS]){
	int i,j;
	int x = 2;
	for(i = 0; i<ROWS;i++){
		for(j=0; j<=COLUMNS-1; j++){
			matrix[i][j] = ' ';
			matrix[i][COLUMNS-1] = '*';
			matrix[i][0] = '*';
		}
	}
}
void printMatrix(char matrix[ROWS][COLUMNS],int aux){
    int i,j;

    for(i=0; i<ROWS; i++){
		
		printf("\t\t\t\t\t\t");
        for(j=0; j<COLUMNS; j++){
			//Desenho que cria a animação
			if(aux%2 > 0 ){
				if(i%2 != 0 ){
					matrix[i][1] = 178;
					matrix[i][COLUMNS - 2] = 178;
				}
			}
			if(aux%2 == 0 ){
				if(i%2 == 0 ){
					matrix[i][1] = 178;
					matrix[i][COLUMNS - 2] = 178;
				}
			}
			//-----------------------------------
            printf("%c", matrix[i][j]);
        }

        printf("\n");
		
		}
}	
void eraseRoad(char matrix[ROWS][COLUMNS]){
	int i,j;
	for(i = 0; i<ROWS;i++){
		for(j=0; j<=COLUMNS-1; j++){
			matrix[i][1] = ' ';
			matrix[i][COLUMNS-2] = EMPTY;
		}
	}
}
void drawCar(char matrix[ROWS][COLUMNS],Vehicle car){
		matrix[car.i][car.j+1] = 178;
		matrix[car.i][car.j+2] = 178;
		matrix[car.i][car.j-1] = 178;
		matrix[car.i][car.j-2] = 178;
		matrix[car.i-1][car.j] = 178;
		matrix[car.i-2][car.j] = 178;
		matrix[car.i-2][car.j+1] = 178;
		matrix[car.i-2][car.j+2] = 178;
		matrix[car.i-2][car.j-1] = 178;
		matrix[car.i-2][car.j-2] = 178;
		matrix[car.i-3][car.j] = 178;	
}
Vehicle drawEnemyCars(char matrix[ROWS][COLUMNS],Vehicle car){

	//if(car.j <=50)car.j = CARLEFT;
	//if(car.j >=51)car.j = CARRIGHT;
	car.j = CARLEFT;

	if(car.i - 3 >= 1)matrix[car.i-3][car.j] = 178;
	if(car.i - 2 >= 1){
		matrix[car.i-2][car.j] = 178;
		matrix[car.i-2][car.j+1] = 178;
		matrix[car.i-2][car.j+2] = 178;
		matrix[car.i-2][car.j-1] = 178;
		matrix[car.i-2][car.j-2] = 178;
	}
	if(car.i - 1 >= 1)matrix[car.i-1][car.j] = 178;
	matrix[car.i][car.j+1] = 178;
	matrix[car.i][car.j+2] = 178;
	matrix[car.i][car.j-1] = 178;
	matrix[car.i][car.j-2] = 178;
	
	
	
	
	
	if(car.i - 3 == ROWS)matrix[car.i-3][car.j] = EMPTY;
	if(car.i - 2 ==ROWS){
		matrix[car.i-2][car.j] = EMPTY;
		matrix[car.i-2][car.j+1] = EMPTY;
		matrix[car.i-2][car.j+2] = EMPTY;
		matrix[car.i-2][car.j-1] = EMPTY;
		matrix[car.i-2][car.j-2] = EMPTY;
	}
	if(car.i - 1 == ROWS)matrix[car.i-1][car.j] = EMPTY;
	if(car.i == ROWS){
		matrix[car.i][car.j+1] = EMPTY;
		matrix[car.i][car.j+2] = EMPTY;
		matrix[car.i][car.j-1] = EMPTY;
		matrix[car.i][car.j-2] = EMPTY;
	}
	
	
	
	return car;
	
}

void eraseCar(char matrix[ROWS][COLUMNS],Vehicle car){
		matrix[car.i][car.j+1] = EMPTY;
		matrix[car.i][car.j+2] = EMPTY;
		matrix[car.i][car.j-1] = EMPTY;
		matrix[car.i][car.j-2] = EMPTY;
		matrix[car.i-1][car.j] = EMPTY;
		matrix[car.i-2][car.j] = EMPTY;
		matrix[car.i-2][car.j+1] = EMPTY;
		matrix[car.i-2][car.j+2] = EMPTY;
		matrix[car.i-2][car.j-1] = EMPTY;
		matrix[car.i-2][car.j-2] = EMPTY;
		matrix[car.i-3][car.j] = EMPTY;
}
	
	



			
