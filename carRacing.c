#include "carRacing.h"



void menu(Vehicle enemyCars[3]){
	system("cls");
	int option;
	FILE *carPos;
	
	printf("1- Continuar\n");
	printf("2- Novo jogo\n");
	printf("3- High scores\n");
	printf("4- Sair\n");
	scanf("%d",&option);
	switch(option){
		case 1:	loadGame(enemyCars); break;
		case 2:	carPos = fopen("enemyY.bin","w");
				fclose(carPos);
				loadGame(enemyCars);
				break;
		case 3:printf("NOTHING HERE\n");break;
		case 4:exit(0);break;
		default:printf("ERROR ERROR ERROR \n");break;
	}
	
}
void highScores(){
	printf("NOTHING TO SEE HERE\n");
	
	
	
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
void loadGame(Vehicle enemyCars[3]){
	int x;
	FILE *carPosR;
	carPosR = fopen("enemyY.bin","r+b");
	int c = fgetc(carPosR);
	if (c == EOF) {
		enemyCars[0].i = END;
		enemyCars[1].i = END;
		enemyCars[2].i = END;
	} 
	else {
		//ungetc(c, carPos);
		for(x=0;x<3;x++){
			fscanf(carPosR,"%d\n",&enemyCars[x].i);
			fscanf(carPosR,"%d\n",&enemyCars[x].j);
		}
	}
	fclose(carPosR);
	
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
			if(index == 0){
				//randPos = rand()%5;
				car.i = - 10;
				enemyY[index] = car.i;
			}
			if (index > 0){ 
				car.i = enemyY[index - 1] - 12;
				enemyY[index] = car.i;
			}
			printf("vetorY: %d\n",enemyY[index]);
			printf(" ");
	return car;	
}	
			

		
	//-------------------------------------------------------
	
	
Vehicle drawEnemyCars(char matrix[ROWS][COLUMNS],Vehicle car,int enemyY[3],int index){

	
	
	//Desenho dos carros inimigos a partir do topo da matriz
	if(car.i < ROWS + 1){
		if(car.i - 3 >= 0)matrix[car.i-3][car.j] = 178;
		if(car.i - 2 >= 0){
			matrix[car.i-2][car.j] = 178;
			matrix[car.i-2][car.j+1] = 178;
			matrix[car.i-2][car.j+2] = 178;
			matrix[car.i-2][car.j-1] = 178;
			matrix[car.i-2][car.j-2] = 178;
		}
		if(car.i - 1 >= 0)matrix[car.i-1][car.j] = 178;
		if(car.i - 1 >= 0){
			matrix[car.i][car.j+1] = 178;
			matrix[car.i][car.j+2] = 178;
			matrix[car.i][car.j-1] = 178;
			matrix[car.i][car.j-2] = 178;
		}
	}
	//------------------------------------------------------
	
	
	//Apaga os carros inimigos durante a animação de movimento
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
	//---------------------------------------------------------
	
	
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
	
	



			
