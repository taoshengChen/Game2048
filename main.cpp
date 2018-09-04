#include <iostream>
#include <windows.h>
#include <cstdio> 
#include "s2048.h"
using std::endl;
using std::cout;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	DIR r;
	cout << " ____   ___  _  _    ___  " << endl;
	cout << "|___ \\ / _ \\| || |  ( _ ) " << endl;
	cout << "  __) | | | | || |_ / _ \\ " << endl;
	cout << " / __/| |_| |__   _| (_) |" << endl;
	cout << "|_____|\\___/   |_|  \\___/ " << endl;//2048 logo

	Sleep(2000); 
	initMatrix();
	while(1){
		system("cls");
		outputMatrix();
		r = getDir();
		if(move(r))
			addInEmpty();
		if(isGameOver())
			break;
	}

	system("cls");
	outputMatrix();
	cout << "game over!" << endl;
	getchar();
	return 0;
}


