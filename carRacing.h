#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
//Configuração das dimensões da matriz principal do jogo
#define COLUMNS 15
#define ROWS 25
#define EMPTY 32
#define ESC 27

#define LEFT 97
#define RIGHT 100
#define LEFT_C 65
#define RIGHT_C 68
#define DOWN 73
#define DOWN_C 53

#define END ROWS + 2
#define CARLEFT 4
#define CARRIGHT 10
#define CARMID COLUMNS/2
typedef struct{
	int i;
	int j;
	int random;
}Vehicle;


typedef struct{
	char dir;
	int runTime;
	int control;
	int gameOver;
	int speedControl;
	int randJ;
	char matrix[ROWS][COLUMNS];
	int score;
	int HighScores[5];
	char Names[5][30];
	char PlayerName[30];
}Game;

void menu(Game *racing);
void init(char matrix[ROWS][COLUMNS], Game *racing);
void quitGame(Vehicle enemyCars[3]);
void printMatrix(char matrix[ROWS][COLUMNS],int aux);
void drawCar(char matrix[ROWS][COLUMNS],Vehicle car);
int genEnemyCars(int sideRand);
void drawEnemyCars(char matrix[ROWS][COLUMNS],Vehicle car);
void eraseCar(char matrix[ROWS][COLUMNS],Vehicle car);
void eraseEnemyCar(char matrix[ROWS][COLUMNS],Vehicle car);
void eraseRoad(char matrix[ROWS][COLUMNS]);
void readScores(char Names[5][30],int HighScores[5]);
void highScoreSort(Game *racing);
void printScores(int HighScores[5],char Names[5][30]);