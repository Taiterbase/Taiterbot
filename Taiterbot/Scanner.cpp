#include "Scanner.h"
/*
Creates a scanner object that initializes the middle points of the verticle and horizontal
of the screen, effectively grabbing the center point of the game window. 
*/
Scanner::Scanner(int sCenterX, int sCenterY, HDC hdc = nullptr) {
	_sCenterX = sCenterX;
	_sCenterY = sCenterY;
	_hdc = hdc;
}

/**
	Simulates a left click down by using mouse events.
*/
void Scanner::LeftClickDown()
{
	input = { 0 };
	// left down 
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &input, sizeof(INPUT));
}

/**
	Simulates left click up using mouse events.
*/
void Scanner::LeftClickUp()
{
	input = { 0 };
	// left up
	::ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &input, sizeof(INPUT));
}


/*Check the color at the middle of the screen, shoot if it's what we want, using
	mouse events and reading the color of rgb values.
*/
void Scanner::ScanReticle() {
	while (true) {

		/* Draw a simple blue rectangle on the desktop */
		//getRGBavg(1255, 690, 1305, 750);
		
		/*
		 Draw a simple blue rectangle on the desktop 
		 This can be used for debugging purposes, or just to see
		 where the calculated mid point of the window is...
		*/
		//HDC hdthing = GetDC(0);
		//RECT rect = { _sCenterX - 10, _sCenterY - 10, _sCenterX + 10, _sCenterY + 10 };
		//HBRUSH blueBrush = CreateSolidBrush(RGB(255, 0, 0));
		//FillRect(hdthing, &rect, blueBrush);
		

		//Performs left click if the reticle's red value is >=250.
		if ((1 << 15) & GetAsyncKeyState(0xA2)) { //left ctrl is the trigger key.
			int r = (int)GetRValue(GetPixel(_hdc, _sCenterX, _sCenterY));
			if(r >= 250){
				LeftClickDown();
				LeftClickUp();	
				Sleep(100);
			}
		} else {
		}
		
		//If the end key has been pressed, exit
		if (GetAsyncKeyState(VK_HOME)) {
			exit(0);
		}
		Sleep(1);
	}
}