#include "display.h"
#include "carRacing.h"


int main(){
	//Inicializações
	
	int highScores[5];
	
	Vehicle car;
	Vehicle enemyCars[3];
	car.i = ROWS - 1;
	car.j = CARMID;
	char dir = EMPTY;
    char matrix[ROWS][COLUMNS];
	int speedControl,runTime;
	int control = 1;
	int gameOver = 0;
	int enemyY[3];
	speedControl = 5;
	
	ShowConsoleCursor(0);
	//-------------------------------
	
	
	START:menu(enemyCars);
	init(matrix);
	for(runTime=0;runTime<=speedControl;runTime++){ 

		//Carro do jogador
		drawCar(matrix,car);
		//------------------------------------------
		//CarroS oponenteS
		
		if(enemyCars[0].i == END)enemyCars[0] = genEnemyCars(matrix,enemyCars[0],enemyY,0);
		if(enemyCars[1].i == END)enemyCars[1] = genEnemyCars(matrix,enemyCars[1],enemyY,1);
		if(enemyCars[2].i == END)enemyCars[2] = genEnemyCars(matrix,enemyCars[2],enemyY,2);

		enemyCars[0] = drawEnemyCars(matrix,enemyCars[0],enemyY,0);
		enemyCars[1] = drawEnemyCars(matrix,enemyCars[1],enemyY,1);
		enemyCars[2] = drawEnemyCars(matrix,enemyCars[2],enemyY,2);
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
			if(enemyCars[0].i>=2 && enemyCars[0].i<ROWS+1)eraseCar(matrix,enemyCars[0]);
			if(enemyCars[0].i < ROWS + 2)enemyCars[0].i++;
			
			
			if(enemyCars[1].i>=2 && enemyCars[1].i<ROWS+1)eraseCar(matrix,enemyCars[1]);
			if(enemyCars[1].i < ROWS + 2)enemyCars[1].i++;
			
			if(enemyCars[2].i>=2 && enemyCars[2].i<ROWS+1)eraseCar(matrix,enemyCars[2]);
			if(enemyCars[2].i < ROWS + 2)enemyCars[2].i++;
			
		}	
		//------------------------

		//leitura da tecla pressionada
		if(kbhit()) dir=getch();
		
		
		
		
		if(dir == 27) {
			quitGame(enemyCars);
			dir = EMPTY;
			goto START;
		}
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