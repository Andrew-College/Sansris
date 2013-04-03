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
void intro();
bool border();
//</Define methods>

//The cmd prompt you're in and a rectangle for the place of the sides
HWND console = GetConsoleWindow();
RECT sides;

int main(){
	//The L means LPCWSTR stands for "Long Pointer to Constant Wide String". It converts the string into a LPCTST 
	//(theres a file on it all)
	SetConsoleTitle(L"Sansris; A tetris oddessey");
	GetWindowRect(console, &sides);
	intro();
	
	return 1;
}
	
void intro(){

	if(border()){
	}

}

bool border(){
	return true;
}
