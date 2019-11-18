#include "display.h"
#include "carRacing.h"
#include <time.h>

int main(){
	srand(time(0));
	Vehicle car;
	Vehicle enemyCar1;
	enemyCar1.i = 0;
	//enemyCar1.j = rand() % 100;
	car.i = ROWS - 1;
	car.j =CARMID;
	char dir = EMPTY;
    char matrix[ROWS][COLUMNS];
	int speedControl,runTime,turbo;
	int control = 1;
	speedControl = 10;
	init(matrix);
	ShowConsoleCursor(0);
	
	for(runTime=0;runTime<=speedControl;runTime++){ 
		fflush(stdin);
		//Carro do jogador
		drawCar(matrix,car);
		//Carro oponente
		enemyCar1 = drawEnemyCars(matrix,enemyCar1);
		
		gotoxy(0,0);
		printMatrix(matrix,control);
		eraseRoad(matrix);
		
		if(turbo == 1)speedControl = 2;
		//else speedControl = 10;
	   
	   
	   //Velocidade da animação
	   if(runTime==speedControl){
			control++;
			runTime = 0;
			if(enemyCar1.i>=2)eraseCar(matrix,enemyCar1);
			if(enemyCar1.i < ROWS + 1)enemyCar1.i++;
			else enemyCar1.i = 0;
			
			
		}	
		//------------------------

		//leitura da tecla pressionada
		if(kbhit()) dir=getch();
		
		//movimento a esquerda
		if(dir == LEFT | dir == LEFT_C){
			//printf("LEFT!!");
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