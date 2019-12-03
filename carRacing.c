#include "carRacing.h"



void menu(){
	system("cls");
	int option;

	printf("\t\t\t\t\t\t1- Continuar\n");
	printf("\t\t\t\t\t\t2- Novo jogo\n");
	printf("\t\t\t\t\t\t3- High scores\n");
	printf("\t\t\t\t\t\t4- Sair\n");
	scanf("%d",&option);
	switch(option){
		case 1:	break; 
		case 2:	break;
		case 3:printf("\t\t\t\t\t\tNOTHING HERE\n");break;
		case 4:exit(0);break;
		default:printf("\t\t\t\t\t\tERROR ERROR ERROR \n");break;
	}
	
}
void highScores(int HighScores[5],int score, char Names[5][30],char PlayerName[30]){
	FILE *HighScoreFile;
	HighScoreFile = fopen("HighScores.bin","w+b");
	int i,j,aux;
	
	//Sorting dos scores
	for(i=1;i<5;i++){
		for(j=0;j<4;j++){
			if(HighScores[j] > HighScores[j+1]){
					aux = HighScores[j];
					HighScores[j] = HighScores[j+1];
					HighScores[j+1] = aux;
			}
		}
	}
	//----------------------------------------------------
	for(i=0;i<5;i++){
		fprintf(HighScoreFile,"%d\n",HighScores[i]);
	}
	fclose(HighScoreFile);
	if(score>HighScores[0]){
		HighScores[0] = score;
		highScores(HighScores,score,Names,PlayerName);
	}
	
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

void quitGame(Vehicle enemyCars[3]){
	int x;
	FILE *carPosQ;
	carPosQ = fopen("enemyY.bin","w+b");
	for(x=0;x<3;x++){
		fprintf(carPosQ,"%d\n",enemyCars[x].i);
		fprintf(carPosQ,"%d\n",enemyCars[x].j);
	}
	fclose(carPosQ);
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
			matrix[i][1] = EMPTY;
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

Vehicle genEnemyCars(char matrix[ROWS][COLUMNS],Vehicle car,int enemyY[3],int index){
	srand(time(0));
	int randPos;
	int sideRand;
	//Inicializa a posição semi-randomica dos carros inimigos
	sideRand = rand()%100;
	if(sideRand<=50)car.j = CARLEFT;
	if(sideRand>=51)car.j = CARRIGHT;

	return car;	
}	
	

		
	//-------------------------------------------------------
	
	
void drawEnemyCars(char matrix[ROWS][COLUMNS],Vehicle car){

	
	
	//Desenho dos carros inimigos a partir do topo da matriz
	
		if(car.i - 3 >= 0 && car.i - 3 <= ROWS - 1)matrix[car.i-3][car.j] = 178;
		if(car.i - 2 >= 0 && car.i - 2 <= ROWS - 1){
			matrix[car.i-2][car.j] = 178;
			matrix[car.i-2][car.j+1] = 178;
			matrix[car.i-2][car.j+2] = 178;
			matrix[car.i-2][car.j-1] = 178;
			matrix[car.i-2][car.j-2] = 178;
		}
		if(car.i - 1 >= 0 && car.i - 1 <= ROWS - 1)matrix[car.i-1][car.j] = 178;
		if(car.i >= 0 && car.i <= ROWS - 1){
			matrix[car.i][car.j+1] = 178;
			matrix[car.i][car.j+2] = 178;
			matrix[car.i][car.j-1] = 178;
			matrix[car.i][car.j-2] = 178;
		}
	//------------------------------------------------------
	
	
	
	
	
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
	
void eraseEnemyCar(char matrix[ROWS][COLUMNS],Vehicle car){
		if(car.i <= ROWS - 1){	
			matrix[car.i][car.j+1] = EMPTY;
			matrix[car.i][car.j+2] = EMPTY;
			matrix[car.i][car.j-1] = EMPTY;
			matrix[car.i][car.j-2] = EMPTY;
		}
		if(car.i - 1 <=ROWS - 1)matrix[car.i-1][car.j] = EMPTY;

		if(car.i - 2 <=ROWS - 1){

			matrix[car.i-2][car.j] = EMPTY;
			matrix[car.i-2][car.j+1] = EMPTY;
			matrix[car.i-2][car.j+2] = EMPTY;
			matrix[car.i-2][car.j-1] = EMPTY;
			matrix[car.i-2][car.j-2] = EMPTY;
		}
		if(car.i - 3 <= ROWS - 1)matrix[car.i-3][car.j] = EMPTY;
}	



			
