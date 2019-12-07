#include "carRacing.h"


void init(char matrix[ROWS][COLUMNS],Game *racing){
	int i,j;
	int x = 2;
	for(i = 0; i<ROWS;i++){
		for(j=0; j<=COLUMNS-1; j++){
			matrix[i][j] = ' ';
			matrix[i][COLUMNS-1] = '*';
			matrix[i][0] = '*';
		}
	}
	racing->dir = EMPTY;
	racing->speedControl = 7;
	racing->runTime;
	racing->control = 1;
	racing->gameOver = 0;
	racing->score = 0;
	


}
void menu(Game *racing){
	system("cls");
	int option;
	if(racing->score == 0){
		printf("\t\t\t\t\t\t1- Novo jogo\n");
		printf("\t\t\t\t\t\t2- High scores\n");
		printf("\t\t\t\t\t\t3- Sair\n");
		scanf("%d",&option);
		
			
		switch(option){
			case 1:init(racing->matrix,racing);
			printf("\t\t\t\t\t\tDigite seu nome\n");
			scanf("%s",&racing->PlayerName);
			break; 
			case 2:	printScores(racing->HighScores,racing->Names);
			system("pause");
			menu(racing);
			break;
			case 3:exit(0);break;
			default:printf("\t\t\t\t\t\tERROR ERROR ERROR \n");break;
		
		}
	}
	if(racing->score > 0){
		printf("\t\t\t\t\t\t1- Continuar\n");
		printf("\t\t\t\t\t\t2- Novo jogo\n");
		printf("\t\t\t\t\t\t3- High scores\n");
		printf("\t\t\t\t\t\t4- Sair\n");
		scanf("%d",&option);
	
		
		switch(option){
			case 1:break;; 
			case 2:	init(racing->matrix,racing);	
			printf("\t\t\t\t\t\tDigite seu nome\n");
			scanf("%s",&racing->PlayerName);
			break; 

			case 3:printScores(racing->HighScores,racing->Names);
			system("pause");
			menu(racing);
			break;
			case 4: exit(0);break;
			default:printf("\t\t\t\t\t\tERROR ERROR ERROR \n");break;
	
		}
	}
	
	
	
	
}
void readScores(char Names[5][30],int HighScores[5]){
	int i;
	FILE *HighScoreFile;
	HighScoreFile = fopen("HighScores.txt","r");
	for(i=0;i<5;i++){
		fscanf(HighScoreFile,"%s",&Names[i]);
		fscanf(HighScoreFile,"%d",&HighScores[i]);
	}
	fclose(HighScoreFile);
}
void highScoreSort(Game *racing){
	FILE *HighScoreFile;
	HighScoreFile = fopen("HighScores.txt","w+");
	int i,j,aux;
	char auxName[30];
	
	//Sorting dos scores
	for(i=1;i<5;i++){
		for(j=0;j<4;j++){
			if(racing->HighScores[j] > racing->HighScores[j+1]){
					aux = racing->HighScores[j];
					strcpy(auxName,racing->Names[j]);
					strcpy(racing->Names[j],racing->Names[j+1]);
					strcpy(racing->Names[j+1],auxName);
					racing->HighScores[j] = racing->HighScores[j+1];
					racing->HighScores[j+1] = aux;
			}
		}
	}
	//----------------------------------------------------

	
	if(racing->score>racing->HighScores[0]){
		racing->HighScores[0] = racing->score;
		strcpy(racing->Names[0],racing->PlayerName);
		printf("Novo High Score!\n");
		
		//Sorting dos scores após inserção de novo score
		for(i=1;i<5;i++){
			for(j=0;j<4;j++){
				if(racing->HighScores[j] > racing->HighScores[j+1]){
						aux = racing->HighScores[j];
						strcpy(auxName,racing->Names[j]);
						strcpy(racing->Names[j],racing->Names[j+1]);
						strcpy(racing->Names[j+1],auxName);
						racing->HighScores[j] = racing->HighScores[j+1];
						racing->HighScores[j+1] = aux;
				}
			}
		}
		//----------------------------------------------------
	}
	for(i=0;i<5;i++){
		fprintf(HighScoreFile,"%s\n",racing->Names[i]);
		fprintf(HighScoreFile,"%d\n",racing->HighScores[i]);
	}
	fclose(HighScoreFile);
}
void printScores(int HighScores[5],char Names[5][30]){
	int i;
	system("cls");
	for(i = 0; i < 5; i++){
		
		printf("\t\t\t\t\tNome: %s  Pontos: %d\n",Names[4 - i],HighScores[4 - i]);
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


int genEnemyCars(int sideRand){
	int carJ;
	//Inicializa a posição semi-randomica dos carros inimigos
	if(sideRand<=50)carJ = CARLEFT;
	if(sideRand>=51)carJ = CARRIGHT;

	return carJ;	
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
		if(car.i <= ROWS - 1 &&car.i >= 0){	
			matrix[car.i][car.j+1] = EMPTY;
			matrix[car.i][car.j+2] = EMPTY;
			matrix[car.i][car.j-1] = EMPTY;
			matrix[car.i][car.j-2] = EMPTY;
		}
		if(car.i - 1 <= ROWS - 1 && car.i - 1 >= 0)matrix[car.i-1][car.j] = EMPTY;

		if(car.i - 2 <=ROWS - 1 && car.i - 2 >= 0){

			matrix[car.i-2][car.j] = EMPTY;
			matrix[car.i-2][car.j+1] = EMPTY;
			matrix[car.i-2][car.j+2] = EMPTY;
			matrix[car.i-2][car.j-1] = EMPTY;
			matrix[car.i-2][car.j-2] = EMPTY;
		}
		if(car.i - 3 <= ROWS - 1 && car.i - 3 >= 0)matrix[car.i-3][car.j] = EMPTY;
}	



			
