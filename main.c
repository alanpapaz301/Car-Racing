#include "display.h"
#include "carRacing.h"


int main(){
	Vehicle car;
    char matrix[ROWS][COLUMNS];
	int speedControl,runTime;
	speedControl = 6000;
	init(matrix);
	ShowConsoleCursor(0);
	for(runTime=0;runTime<100;runTime++){  
       // if(runTime==speedControl){

			gotoxy(0,0);
			printMatrix(matrix);
			
		//}	
		runTime = 0;
	}
	
	
	
	
	
	
	
	
	
	/*
	//leitura da tecla pressionada
    if(kbhit()) dir=getch();
    //movimento a esquerda
    if(matrix[car.i][car.j-car.width/2]!=symbol && car.j-car.width/2>1){
        if(dir == LEFT | dir == LEFT_C){
            car.j--;
            dir = ' ';
        }
    }
    //movimento a direita     
    if(matrix[car.i][car.j+car.width/2] !=symbol && car.j+car.width/2<COLUMNS-2){
        if(dir == RIGHT | dir== RIGHT_C){
            car.j++;
            dir = ' ';
		}   
	}
    //aumenta a velocidade da desçida da peça   
    if(dir == DOWN |dir == DOWN_C){
        int speedControlBackup = speedControl;
        speedControl = 500;
        dir = ' ';           
        speedControl = speedControlBackup;
		
    }
	*/



















return 0;
}