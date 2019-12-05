#include "display.h"
#include "carRacing.h"


int main(){
	//Inicializações
	srand(time(0));
	int highScoresVet[5] = {0,0,0,0,0};
	char Names[5][30] = {
		"FULANO",
		"FULANO",
		"FULANO",
		"FULANO",
		"FULANO",
	};
	
	
	int score = 0;
	char PlayerName[30];
	
	Vehicle car;
	Vehicle enemyCars[3];
	enemyCars[0].i = 0;
	enemyCars[1].i = -10;
	enemyCars[2].i = -20;
	car.i = ROWS - 1;
	car.j = CARMID;
	char dir = EMPTY;
    char matrix[ROWS][COLUMNS];
	int speedControl,runTime;
	int control = 1;
	int gameOver = 0;
	speedControl = 7;
	int randJ;
	ShowConsoleCursor(0);
	//-------------------------------
	
	randJ = rand()%100;
	enemyCars[0].j = genEnemyCars(randJ);
	randJ = rand()%100;
	enemyCars[1].j = genEnemyCars(randJ);
	randJ = rand()%100;
	enemyCars[2].j = genEnemyCars(randJ);
	
	START:menu(PlayerName);
	init(matrix);
	for(runTime=0;runTime<=speedControl;runTime++){ 
		
		if(score > 8000)speedControl = 4;
		//Carro do jogador
		drawCar(matrix,car);
		//------------------------------------------
	
		//CarroS oponenteS
		if(enemyCars[0].i >= END && enemyCars[2].i > 10){
			enemyCars[0].i = -1;
		}
		if(enemyCars[0].i == -1){
			randJ = rand()%100;
			enemyCars[0].j = genEnemyCars(randJ);
		}
		
		
		if(enemyCars[1].i >= END && enemyCars[0].i > 10){
			enemyCars[1].i = -1;
		}
		if(enemyCars[1].i == -1){
			randJ = rand()%100;
			enemyCars[1].j = genEnemyCars(randJ);
		}
		
		
		if(enemyCars[2].i >= END && enemyCars[1].i > 10){
			enemyCars[2].i = -1;
		}
		if(enemyCars[2].i == -1){
			randJ = rand()%100;
			enemyCars[2].j = genEnemyCars(randJ);
		}
		
		
		 drawEnemyCars(matrix,enemyCars[0]);
		 drawEnemyCars(matrix,enemyCars[1]);
		 drawEnemyCars(matrix,enemyCars[2]);
		//------------------------------------------
		
		
		gotoxy(0,0);
		printMatrix(matrix,control);
		eraseRoad(matrix);
		printf("\t\t\t\t\tSCORE: %d\n",score);
		if(gameOver == 1){
			system("cls");
			printf("\t\t\t\t\tGAME OVER!\n");
			highScores(highScoresVet,score,Names,PlayerName);
			system("pause");
			goto START;
			//printf("Crashed!");
		}

	   //Velocidade da animação
	   if(runTime==speedControl){
			control++;
			runTime = 0;
			eraseEnemyCar(matrix,enemyCars[0]);
			enemyCars[0].i++;
			
			
			eraseEnemyCar(matrix,enemyCars[1]);
			enemyCars[1].i++;
			
			eraseEnemyCar(matrix,enemyCars[2]);
			enemyCars[2].i++;
			score+=100;
		}	
		//------------------------

		//leitura da tecla pressionada
		if(kbhit()) dir=getch();
		
		//movimento a esquerda
		if(dir == LEFT | dir == LEFT_C){
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
			if(matrix[car.i][car.j + 4] != EMPTY)gameOver = 1;
			if(matrix[car.i-1][car.j + 4] != EMPTY)gameOver = 1;
			if(matrix[car.i-2][car.j + 4] != EMPTY)gameOver = 1;
			if(matrix[car.i-3][car.j + 4] != EMPTY)gameOver = 1;
			eraseCar(matrix,car);
			car.j = CARRIGHT;
			dir = EMPTY;
			   
		}
		
	}
	



return 0;
}