#include "Scanner.h"
#include <random>

int main(int args, int argv[]) {
//	system("cls");

	string gname = "NAME OF YOUR GAME"; //Name of the game we're getting a hold of.
	HWND ghandle = NULL;
	RECT gwindow;
	cout << "Waiting for game: " << gname; //Are we really, though
	int i = 0;
	while (!ghandle) {
		if (i == 3) {
			i = 0;
			system("cls");
			cout << "Waiting for game: " << gname;
			continue;
		}
		ghandle = FindWindowA(NULL, gname.c_str()); //Looks for the game window specified
		cout << ". ";
		Sleep(450);
		i++;
	}
//	char yorn = 'n'; //change this to cin, if you'd like the option to change between borderless/windowed.

	GetWindowRect(ghandle, &gwindow); // grabs the window given the process handle.
	HDC parentCurrWindow = GetDC(HWND_DESKTOP); //Gets the parent window, which is the desktop.

	int rectCenterX = gwindow.left + ((gwindow.right - gwindow.left) / 2); //gets the center of the process handle's window
	int rectCenterY = gwindow.top + ((gwindow.bottom - gwindow.top) / 2);
	cout << "x: " << rectCenterX << " y: " << rectCenterY << endl;

	//adjusts for windowless border / windowed
//	if (yorn == 'N' || yorn == 'n') {
//		rectCenterX += 1;
//		rectCenterY += 11;
//	}

	/*
		This line of code hides the console window after successfully grabbing
		our game's window. This makes it a little more stealthy if you're into
		streaming or playing with people near you.
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
	*/

	Scanner reticle(rectCenterX, rectCenterY, parentCurrWindow);
	reticle.ScanReticle();
	::ReleaseDC(0, parentCurrWindow); // 99.9998% chance that this line will never be run.
	

	return 0;

}


