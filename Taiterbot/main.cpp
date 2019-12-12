#include "Scanner.h"
#include <random>

int main(int args, int argv[]) {
	string gname = "GAME NAME HERE";
	HWND ghandle = NULL; 
	RECT gwindow; 
	cout << "Waiting for game: " << gname; 
	while (!ghandle) {
		ghandle = FindWindowA(NULL, gname.c_str());
		Sleep(250);
	}
	system("cls");
	GetWindowRect(ghandle, &gwindow);
	HDC parentCurrWindow = GetDC(HWND_DESKTOP);

	int rectCenterX = gwindow.left + ((gwindow.right - gwindow.left) / 2); 
	int rectCenterY = gwindow.top + ((gwindow.bottom - gwindow.top) / 2); 

	cout << "x: " << rectCenterX << " y: " << rectCenterY << endl;

	//ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);

	Scanner reticle(rectCenterX+1, rectCenterY+11, parentCurrWindow);
	reticle.ScanReticle(); 
	::ReleaseDC(0, parentCurrWindow);
	

	return 0;

}


