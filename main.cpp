#include "Scanner.h"
#include <random>
/**
	This program's purpose is to provide a skeleton, and some source code
	for developers who would like to get into making simple cheats that cleverly
	bypass popular gaming anticheat systems. This program bypasses EasyAntiCheat's 
	cheat detection methods, as it is completely external, doesn't read the process'
	memory, and simulates mouse clicks....
	
	If simulating mouse clicks ever become an issue with this anticheat software, 
	I'll publish a mouse dll patch. Bypassing this kind of detection is pretty simple.
	
	This application leverages the logic that the reticle in the center of the screen
	changes color according to whether or not the user is hovering over an enemy. If the user
	hovers over an enemy, the reticle changes color, and we can detect this change externally, allowing 
	us to externally shoot instantaneously.
*/
int main(int args, int argv[]) {

	//Name of the game we're getting a hold of. This is 
	//usually the string at the top of the application... i.e. if you're using Windows Powershell,
	//at the top left corner of the application bar, it says "Windows Powershell". This is that string.
	string gname = "NAME OF YOUR GAME";
	HWND ghandle = NULL; // Game handle window... Let's us read the state of this window.
	RECT gwindow; //Let's us calculate the midpoint of the screen.
	cout << "Waiting for game: " << gname; //This is kind of useless gui code. You can play around with it.
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

	//Here we calculate the midpoint of the window. This is usually where the reticle sits in the game.
	int rectCenterX = gwindow.left + ((gwindow.right - gwindow.left) / 2); 
	int rectCenterY = gwindow.top + ((gwindow.bottom - gwindow.top) / 2); 
	//Print out what the midpoint is.
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
	*/
	//ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);

	Scanner reticle(rectCenterX, rectCenterY, parentCurrWindow);
	reticle.ScanReticle(); //Begins the while loop in which we scan continually at the midpoint for color changes in the reticle.
	::ReleaseDC(0, parentCurrWindow); // 99.9998% chance that this line will never be run.
	

	return 0;

}


