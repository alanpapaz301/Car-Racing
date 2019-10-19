#include "display.h"
#include "carRacing.h"


int main(){
	Block bloco;
    char matrix[ROWS][COLUMNS];

	ShowConsoleCursor(0);
	    //leitura da tecla pressionada
        if(kbhit()) dir=getch();
			//Mudança de orientação
		if(dir == 'f'){
				if (bloco.orientacao == 4) bloco.orientacao = 1;
				else bloco.orientacao++;
				aux = bloco.width;
				bloco.width = bloco.height;
				bloco.height = aux;
				dir = ' ';
			}
        //movimento a esquerda
        if(matrix[bloco.i][bloco.j-bloco.width/2]!=symbol && bloco.j-bloco.width/2>1){
                if(dir == LEFT | dir == LEFT_C){
                    bloco.j--;
                    dir = ' ';
                }
            }
        //movimento a direita     
        if(matrix[bloco.i][bloco.j+bloco.width/2] !=symbol && bloco.j+bloco.width/2<COLUMNS-2){
                if(dir == RIGHT | dir== RIGHT_C){
                    bloco.j++;
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



















return 0;
}