//Andrew Tetris clone

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

//Needed before windows.h, says that the system is win 2k or higher
#define _WIN32_WINNI 0x0500

#include "Windows.h"
//Main app
using namespace std;

//<Define methods>
bool border();
void intro();
void setCursor(int x, int y);
void printCbyC(string input, int wait);
void setup();

unsigned int scr_width, scr_height;
int mov_x = 0, mov_y = 1, atX = 0, atY = 0;
COORD nextX = {0,0}, lastX = {0,0}, nextY = {0,0},lastY = {0,0};

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
	intro();
	border();
	setup();
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

void setup(){
	system("cls");
	border();
	setCursor((scr_width/2)-4,(scr_height/2)-5);
	cout << "Direction";
	setCursor((scr_width/2),(scr_height/2)-4);
	if(mov_x ==0 && mov_y == 1){
		cout << "\\/";
	}
	else if(mov_x ==0 && mov_y == -1){
		cout << "/\\";
	}
	else if(mov_x ==1 && mov_y == 0){
		cout << "> ";
	}
	else if(mov_x ==0 && mov_y == 1){
		cout << "< ";
	}
	setCursor((scr_width/2)-5,(scr_height/2)-1);
	cout << "Screen sizes";
	setCursor((scr_width/2)-10,(scr_height/2)-1);
	cout << "length; " << scr_width;
	setCursor((scr_width/2)+2,(scr_height/2)-1);
	cout << "height; " << scr_height;
	setCursor((scr_width/2)-12,(scr_height/2)+4);
	cout << "<Ok>   <Apply>   <Cancel>";

	//moving the cursor, changing the values
	setCursor((scr_width/2),(scr_height/2)-4);
	
	while(true){

		//Update what cursor can move to
		if(atX == (scr_width/2) && atY == (scr_height/2)-4){//At direction
			nextX.X = atX;
			nextX.Y = atY;
			lastX.X = atX;
			lastX.Y = atY;
			/////
			nextY.X = (scr_width/2)-1;
			nextY.Y = (scr_height/2)-1;
			lastY.X = (scr_width/2)+11;
			lastY.Y = (scr_height/2)+4;
		}
		else if(atX == (scr_width/2)-1 && atY == (scr_height/2)-1){//At size (length)
			nextX.X = (scr_width/2)+11;
			nextX.Y = (scr_height/2)-1;
			lastX.X = (scr_width/2)+11;
			lastX.Y = (scr_height/2)-1;
			/////
			nextY.X = (scr_width/2)-10;
			nextY.Y = (scr_height/2)+4;
			lastY.X = (scr_width/2);
			lastY.Y = (scr_height/2)-4;
		}
		else if(atX == (scr_width/2)+11 && atY == (scr_height/2)-1){//At size (height)
			nextX.X = (scr_width/2)-1;
			nextX.Y = (scr_height/2)-1;
			lastX.X = (scr_width/2)-1;
			lastX.Y = (scr_height/2)-1;
			/////
			nextY.X = (scr_width/2)-10;
			nextY.Y = (scr_height/2)+4;
			lastY.X = (scr_width/2);
			lastY.Y = (scr_height/2)-4;
		}
		else if(atX == (scr_width/2)-10 && atY == (scr_height/2)+4){//At <Ok>
			nextX.X = (scr_width/2);
			nextX.Y = (scr_height/2)+4;
			lastX.X = (scr_width/2)+11;
			lastX.Y = (scr_height/2)+4;
			/////
			nextY.X = (scr_width/2);
			nextY.Y = (scr_height/2)-4;
			lastY.X = (scr_width/2)+11;
			lastY.Y = (scr_height/2)-1;
		}
		else if(atX == (scr_width/2) && atY == (scr_height/2)+4){//At <Apply>
			nextX.X = (scr_width/2)+11;
			nextX.Y = (scr_height/2)+4;
			lastX.X = (scr_width/2)-10;
			lastX.Y = (scr_height/2)+4;
			/////
			nextY.X = (scr_width/2);
			nextY.Y = (scr_height/2)-4;
			lastY.X = (scr_width/2)+11;
			lastY.Y = (scr_height/2)-1;
		}
		else if(atX == (scr_width/2)+11 && atY == (scr_height/2)+4){//At <Cancel>
			nextX.X = (scr_width/2)-10;
			nextX.Y = (scr_height/2)+4;
			lastX.X = (scr_width/2);
			lastX.Y = (scr_height/2)+4;
			/////
			nextY.X = (scr_width/2);
			nextY.Y = (scr_height/2)-4;
			lastY.X = (scr_width/2)+11;
			lastY.Y = (scr_height/2)-1;
		}
		//Get user input
		char input = getch();
		//make if elses, switches dont work unless enums, etc. are used
		if(input == cUp){
			setCursor(lastY.X, lastY.Y);
		}
		else if(input == cDown){
			setCursor(nextY.X, nextY.Y);
		}
		else if(input == cLeft){
			setCursor(lastX.X, lastX.Y);
		}
		else if(input == cRight){
			setCursor(nextX.X, nextY.Y);
		}
		else if(input == '\n'){//They want an action done
			if(atX == (scr_width/2) && atY == (scr_height/2)-4){//Direction changing

			}

		}
		else{
			//Nothin here but us potatoes
		}

		//Now for the interaction

	}
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