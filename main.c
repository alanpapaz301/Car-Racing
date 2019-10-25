#include "display.h"
#include "carRacing.h"


int main(){
	Vehicle car;
	Vehicle enemyCar1;
	enemyCar1.i = rand() % 15;
	enemyCar1.j = rand() % 2;
	car.i = ROWS - 1;
	car.j =CARMID;
	char dir = ' ';
    char matrix[ROWS][COLUMNS];
	int speedControl,runTime;
	int control = 1;
	int speedControlBackup;
	speedControl = 5;
	init(matrix);
	ShowConsoleCursor(0);
	srand(time(0));
	for(runTime=0;runTime<=speedControl;runTime++){ 
		drawCar(matrix,car);
		enemyCar1 = drawEnemyCars(matrix,enemyCar1);
		gotoxy(0,0);
		printMatrix(matrix,control);
		eraseRoad(matrix);
       //Velocidade da animação
	   if(runTime==speedControl){
			control++;
			runTime = 0;
			eraseEnemyCar(matrix,enemyCar1);
			if(enemyCar1.i < ROWS - 1)enemyCar1.i++;
			
			
		}	
		//------------------------

		//leitura da tecla pressionada
		if(kbhit()) dir=getch();
		//movimento a esquerda
		if(dir == LEFT | dir == LEFT_C){
			printf("LEFT!!");
			eraseCar(matrix,car);
				car.j = CARLEFT;
				dir = ' ';
		}
		//movimento a direita     
		if(dir == RIGHT | dir== RIGHT_C){
				printf("RIGHT!!");
				eraseCar(matrix,car);
				car.j = CARRIGHT;
				dir = ' ';
			   
		}
		//aumenta a velocidade da desçida da peça   
		if(dir == 's' |dir == 'S'){
			printf("turbo");
			speedControlBackup = speedControl;
			speedControl = 1;
			dir = ' ';           
			speedControl = speedControlBackup;
			
		}
	}
	



















return 0;
}