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
	
	while(1){ 
		racing.runTime ++;
		
		//reset das posições dos carros ao começão novo jogo
		if(racing.score == 0){
			car.j = CARMID;
			enemyCars[0].i = 0;
			enemyCars[1].i = -10;
			enemyCars[2].i = -20;
		}
		//--------------------------------------------------
		
		//Fase 2, aumento de velocidade
		if(racing.score >= 5000){
			racing.speedControl = 4;
		}
		//------------------------------
		
		//Carro do jogador
		drawCar(racing.matrix,car);
		//------------------------------------------
	
		//Carros oponentes, controle dos intervalos
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
		if(racing.score<5000)printf("\t\t\t\tFASE 1\n");
		if(racing.score>=5000)printf("\t\t\t\tFASE 2!\n");
		printf("\t\t\t\tSCORE: %d\n",racing.score);
		
		//Volta para o menu se o carro bater
		if(racing.gameOver == 1){
			system("cls");
			printf("\t\t\t\t\tGAME OVER!\n");
			highScoreSort(&racing);
			system("\t\t\t\t\tpause");
			racing.gameOver = 0;
			init(racing.matrix,&racing);
			menu(&racing);
		}
		//-----------------------------------
		
	   //Velocidade da animação
	   if(racing.runTime>=racing.speedControl){
			racing.control++;
			racing.runTime = 0;
			
			eraseEnemyCar(racing.matrix,enemyCars[0]);
			enemyCars[0].i++;

			
			eraseEnemyCar(racing.matrix,enemyCars[1]);
			enemyCars[1].i++;

			
			eraseEnemyCar(racing.matrix,enemyCars[2]);
			enemyCars[2].i++;
			
			checkCollision(car,enemyCars,&racing);
			if(racing.score<5000)racing.score+=10;
			if(racing.score>=5000)racing.score+=5;
		}		
		//------------------------------------------------
		//leitura da tecla pressionada
		if(kbhit()) racing.dir=getch();
		
		//TURBO
		if(racing.dir == 32 && racing.score < 5000){
			racing.runTime +=4;
			racing.dir = 0;
		}
		//----------------------
		
		//movimento a esquerda
		if(racing.dir == LEFT | racing.dir == LEFT_C){
			if(car.j != CARLEFT){
				if(racing.matrix[car.i][car.j - 4] != EMPTY |
				racing.matrix[car.i-1][car.j - 4] != EMPTY |
				racing.matrix[car.i-2][car.j - 4] != EMPTY |
				racing.matrix[car.i-3][car.j - 4] != EMPTY)racing.gameOver = 1;
				eraseCar(racing.matrix,car);
				car.j = CARLEFT;
				racing.dir = 0;
			}
		}	
		//movimento a direita     
		if(racing.dir == RIGHT | racing.dir == RIGHT_C){
			if(car.j != CARRIGHT){
				if(racing.matrix[car.i][car.j + 4] != EMPTY |
				racing.matrix[car.i-1][car.j + 4] != EMPTY |
				racing.matrix[car.i-2][car.j + 4] != EMPTY |
				racing.matrix[car.i-3][car.j + 4] != EMPTY)racing.gameOver = 1;
				eraseCar(racing.matrix,car);
				car.j = CARRIGHT;
				racing.dir = 0;
			}   
		}
		
		if(racing.dir == ESC){
			racing.dir = 0;
			menu(&racing);
		}
		

	}
	



return 0;
}