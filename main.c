#include "display.h"
#include "carRacing.h"


int main(){
	//Inicializações
	srand(time(0));
	Game racing;
	int i;
	for (i = 0; i< 5; i++){
		racing.HighScores[i] = 0;
		strcpy(racing.Names[i],"FULANO");
	}
	
	
	Vehicle car;
	Vehicle enemyCars[3];
	enemyCars[0].i = 0;
	enemyCars[1].i = -10;
	enemyCars[2].i = -20;
	car.i = ROWS - 1;
	car.j = CARMID;
	ShowConsoleCursor(0);
	racing.score = 0;
	//-------------------------------
	
	//Lado inicial dos carros oponentes
	racing.randJ = rand()%100;
	enemyCars[0].j = genEnemyCars(racing.randJ);
	racing.randJ = rand()%100;
	enemyCars[1].j = genEnemyCars(racing.randJ);
	racing.randJ = rand()%100;
	enemyCars[2].j = genEnemyCars(racing.randJ);
	//-------------------------------------------
	
	//leitura do arqivo de pontuação e inicializa o menu
	readScores(racing.Names,racing.HighScores);
	menu(&racing);
	//--------------------------------------------------------
	
	for(racing.runTime=0;racing.runTime<=racing.speedControl;racing.runTime++){ 
		
		if(racing.score == 8000){
			system("cls");
			printf("\t\t\t\t\tFase 2!\n");
			racing.speedControl = 4;
		}	
		//Carro do jogador
		drawCar(racing.matrix,car);
		//------------------------------------------
	
		//Carros oponentes
		if(enemyCars[0].i >= END && enemyCars[2].i > 10){
			enemyCars[0].i = -1;
		}
		if(enemyCars[0].i == -1){
			racing.randJ = rand()%100;
			enemyCars[0].j = genEnemyCars(racing.randJ);
		}
		
		
		if(enemyCars[1].i >= END && enemyCars[0].i > 10){
			enemyCars[1].i = -1;
		}
		if(enemyCars[1].i == -1){
			racing.randJ = rand()%100;
			enemyCars[1].j = genEnemyCars(racing.randJ);
		}
		
		
		if(enemyCars[2].i >= END && enemyCars[1].i > 10){
			enemyCars[2].i = -1;
		}
		if(enemyCars[2].i == -1){
			racing.randJ = rand()%100;
			enemyCars[2].j = genEnemyCars(racing.randJ);
		}
		
		
		 drawEnemyCars(racing.matrix,enemyCars[0]);
		 drawEnemyCars(racing.matrix,enemyCars[1]);
		 drawEnemyCars(racing.matrix,enemyCars[2]);
		//------------------------------------------
		
		
		gotoxy(0,0);
		printMatrix(racing.matrix,racing.control);
		eraseRoad(racing.matrix);
		printf("\t\t\t\t\tSCORE: %d\n",racing.score);
		if(racing.gameOver == 1){
			system("cls");
			printf("\t\t\t\t\tGAME OVER!\n");
			highScoreSort(&racing);
			system("pause");
			racing.gameOver = 0;
			init(racing.matrix,&racing);
			menu(&racing);
			//printf("Crashed!");
		}

	   //Velocidade da animação
	   if(racing.runTime==racing.speedControl){
			racing.control++;
			racing.runTime = 0;
			eraseEnemyCar(racing.matrix,enemyCars[0]);
			enemyCars[0].i++;
			
			
			eraseEnemyCar(racing.matrix,enemyCars[1]);
			enemyCars[1].i++;
			
			eraseEnemyCar(racing.matrix,enemyCars[2]);
			enemyCars[2].i++;
			racing.score+=100;
		}	
		//------------------------
		racing.speedControl = 7;
		//leitura da tecla pressionada
		if(kbhit()) racing.dir=getch();
		
		//movimento a esquerda
		if(racing.dir == LEFT | racing.dir == LEFT_C){
			if(racing.matrix[car.i][car.j - 4] != EMPTY)racing.gameOver = 1;
			if(racing.matrix[car.i-1][car.j - 4] != EMPTY)racing.gameOver = 1;
			if(racing.matrix[car.i-2][car.j - 4] != EMPTY)racing.gameOver = 1;
			if(racing.matrix[car.i-3][car.j - 4] != EMPTY)racing.gameOver = 1;
			eraseCar(racing.matrix,car);
			car.j = CARLEFT;
			racing.dir = EMPTY;
			
		}	
		//movimento a direita     
		if(racing.dir == RIGHT | racing.dir == RIGHT_C){
			if(racing.matrix[car.i][car.j + 4] != EMPTY)racing.gameOver = 1;
			if(racing.matrix[car.i-1][car.j + 4] != EMPTY)racing.gameOver = 1;
			if(racing.matrix[car.i-2][car.j + 4] != EMPTY)racing.gameOver = 1;
			if(racing.matrix[car.i-3][car.j + 4] != EMPTY)racing.gameOver = 1;
			eraseCar(racing.matrix,car);
			car.j = CARRIGHT;
			racing.dir = EMPTY;
			   
		}
		
		if(racing.dir == ESC){
			racing.dir = EMPTY;
			menu(&racing);
		}
		
		if(racing.dir == 'h'){
			racing.speedControl = 4;
			racing.dir = EMPTY;
		}
	}
	



return 0;
}