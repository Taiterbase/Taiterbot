#include "Scanner.h"

Scanner::Scanner(int sCenterX, int sCenterY, HDC hdc = nullptr) {
	_sCenterX = sCenterX;
	_sCenterY = sCenterY;
	_hdc = hdc;
}


void Scanner::LeftClickDown()
{
	input = { 0 };
	// left down 
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &input, sizeof(INPUT));
}


void Scanner::LeftClickUp()
{
	input = { 0 };
	// left up
	::ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &input, sizeof(INPUT));
}


void Scanner::ScanReticle() {
	while (true) {
		//HDC hdthing = GetDC(0);
		//RECT rect = { _sCenterX - 10, _sCenterY - 10, _sCenterX + 10, _sCenterY + 10 };
		//HBRUSH blueBrush = CreateSolidBrush(RGB(255, 0, 0));
		//FillRect(hdthing, &rect, blueBrush);
		
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
