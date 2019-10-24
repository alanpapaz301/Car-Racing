#include "display.h"
#include "carRacing.h"


int main(){
	Vehicle car;
	car.i = ROWS - 1;
	car.j =CARMID;
	char dir = ' ';
    char matrix[ROWS][COLUMNS];
	int speedControl,runTime;
	int control = 1;
	speedControl = 90000;
	init(matrix);
	ShowConsoleCursor(0);
	
	for(runTime=0;runTime<=speedControl;runTime++){  
       //if(runTime==speedControl){
			drawCar(matrix,car);
			gotoxy(0,0);
			printMatrix(matrix,control);
			eraseRoad(matrix);
			control++;
			//runTime = 0;
		//}	
		
	
	
	
	
	
	
	
	
	
	
	
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
    if(dir == DOWN |dir == DOWN_C){
        int speedControlBackup = speedControl;
        speedControl = 500;
        dir = ' ';           
        speedControl = speedControlBackup;
		
    }
	}
	



















return 0;
}