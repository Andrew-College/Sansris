//Andrew Tetris clone

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>

//Needed before windows.h, says that the system is win 2k or higher
#define _WIN32_WINNI 0x0500

#include "Windows.h"
#include "Pieces.h"
//Main app
using namespace std;

//<Define methods>
bool border();
void game();
void intro();
void setCursor(int x, int y);
void printCbyC(string input, int wait);

unsigned int scr_width, scr_height;
int mov_x = 0, mov_y = 1, atX = 0, atY = 0, direction = 0;
COORD nextX = {0,0}, lastX = {0,0}, nextY = {0,0},lastY = {0,0};
piece blocks[7];

char cUp = 'w', cDown = 's', cLeft = 'a', cRight = 'd';
//</Define methods>

////The cmd prompt you're in and a rectangle for the place of the sides
//HWND console = GetConsoleWindow();
//RECT sides;

int main(){
	//The L means LPCWSTR stands for "Long Pointer to Constant Wide String". It converts the string into a LPCTST 
	//(theres a file on it all)
	SetConsoleTitle(L"Sansris; A tetris oddessey");
	//Set size of console window
	system("MODE CON COLS=50 LINES=50");
	scr_width= 50;
	scr_height = 49;
	//GetWindowRect(console, &sides);
	//intro();
	border();
	//setup();
	game();
	getch();
	return 1;
}


void intro(){
	for(unsigned int i = 0; i < 2; i++){
		for(unsigned int x = 1; x < scr_width-1; x++){
			setCursor(x,0);
			cout << '#';
			Sleep(10);
			setCursor(x,scr_height);
			cout << '#';
			Sleep(20);
		}
	}
	for(unsigned int i = 0; i < 2; i++){
		for(unsigned int y = 1; y < scr_height; y++){
			setCursor(0,y);
			cout << '#';
			Sleep(10);
			setCursor(scr_width-1,y);
			cout << '#';
			Sleep(20);
		}
	}
	setCursor((scr_width/2)-4, scr_height/4);
	printCbyC("Sansris",100);
	Sleep(3000);
	setCursor((scr_width/2)-11, scr_height*.8);
	printCbyC("A tetris-esque oddessey",100);
	Sleep(3000);
	system("cls");
}

void game(){
	//Refresh screen
	system("cls");
	border();
	//Create pieces
	//int this_works[4][2] ={{0,0},{0,0},{0,0},{0,0}};
	blocks[0] = piece("Square",			{{0,0},{1,0},{0,1},{1,1}}		);
	blocks[1] = piece("Straight",		{{0,0},{0,1},{0,2},{0,3}}		);
	blocks[2] = piece("T-shape",		{{0,0},{-1,0},{1,0},{0,1}}		);
	blocks[3] =	piece("Z-shape",		{{0,0},{1,0},{1,1},{2,1}}		);
	blocks[4] = piece("inv_Z-shape",	{{0,0},{-1,0},{-1,-1},{-2,-1}}	);
	blocks[5] = piece("L-shape",		{{0,0},{0,1},{0,2},{2,1}}		);
	blocks[6] = piece("inv_L-shape",	{{0,0},{0,1},{0,2},{2,-1}}		);
	//

	//
}


bool border(){
	for(unsigned int i = 0; i < 2; i++){
		for(unsigned int x = 1; x < scr_width-1; x++){
			setCursor(x,0);
			cout << '#';
			setCursor(x,scr_height);
			cout << '#';
		}
	}
	for(unsigned int i = 0; i < 2; i++){
		for(unsigned int y = 1; y < scr_height; y++){
			setCursor(0,y);
			cout << '#';
			setCursor(scr_width-1,y);
			cout << '#';
		}
	}
	return true;
}

void setCursor(int x, int y){
	COORD coord = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	atX = x;
	atY = y;
}
void printCbyC(string input, int wait){
	for(unsigned i = 0; i < input.size(); i++){
		cout << input[i];
		Sleep(wait);
	}

}