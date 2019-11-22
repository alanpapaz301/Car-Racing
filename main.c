#include "display.h"
#include "carRacing.h"
#include <time.h>

int main(){
	//Inicializações
	srand(time(0));
	Vehicle car;
	Vehicle enemyCar1;
	Vehicle enemyCar2;
	Vehicle enemyCar3;
	enemyCar1.i = ROWS + 1;
	enemyCar2.i = ROWS + 1;
	enemyCar3.i = ROWS + 1;
	car.i = ROWS - 1;
	car.j = CARMID;
	char dir = EMPTY;
    char matrix[ROWS][COLUMNS];
	int speedControl,runTime,turbo;
	int control = 1;
	int gameOver = 0;
	int enemyY[3];
	speedControl = 5;
	init(matrix);
	ShowConsoleCursor(0);
	//-------------------------------
	
	menu();
	for(runTime=0;runTime<=speedControl;runTime++){ 

		//Carro do jogador
		drawCar(matrix,car);
		//------------------------------------------
		//CarroS oponenteS
		enemyCar1 = drawEnemyCars(matrix,enemyCar1,enemyY,0);
		enemyCar2 = drawEnemyCars(matrix,enemyCar2,enemyY,1);
		enemyCar3 = drawEnemyCars(matrix,enemyCar3,enemyY,2);
		//------------------------------------------
		
		
		gotoxy(0,0);
		printMatrix(matrix,control);
		eraseRoad(matrix);
		if(gameOver == 1){
			printf("PERDEU!");
			//exit(0);
		}

	   //Velocidade da animação
	   if(runTime==speedControl){
			control++;
			runTime = 0;
			if(enemyCar1.i>=2)eraseCar(matrix,enemyCar1);
			if(enemyCar1.i < ROWS + 2)enemyCar1.i++;
			
			
			if(enemyCar2.i>=2 && enemyCar2.i<ROWS+2)eraseCar(matrix,enemyCar2);
			if(enemyCar2.i < ROWS + 2)enemyCar2.i++;
			
			if(enemyCar3.i>=2 && enemyCar3.i<ROWS+2)eraseCar(matrix,enemyCar3);
			if(enemyCar3.i < ROWS + 2)enemyCar3.i++;
			
		}	
		//------------------------

		//leitura da tecla pressionada
		if(kbhit()) dir=getch();
		
		//movimento a esquerda
		if(dir == LEFT | dir == LEFT_C){
			//printf("LEFT!!");
			if(matrix[car.i][car.j - 4] != EMPTY)gameOver = 1;
			if(matrix[car.i-1][car.j - 4] != EMPTY)gameOver = 1;
			if(matrix[car.i-2][car.j - 4] != EMPTY)gameOver = 1;
			if(matrix[car.i-3][car.j - 4] != EMPTY)gameOver = 1;
			eraseCar(matrix,car);
			car.j = CARLEFT;
			dir = EMPTY;
			
		}	
		//movimento a direita     
		if(dir == RIGHT | dir == RIGHT_C){
				//printf("RIGHT!!");
				eraseCar(matrix,car);
				car.j = CARRIGHT;
				dir = EMPTY;
			   
		}
		
		/*
		if(dir == 's' | dir == 'S'){
			turbo = 1;
			//dir = EMPTY;
		}
		*/
	}
	



return 0;
}