#include "Scanner.h"
bool isToggled, tFlag = false, fflag = false;

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
		//RECT rect = { 1250, 725, 1251, 726 };
		//HBRUSH blueBrush = CreateSolidBrush(RGB(255, 0, 0));
		//FillRect(hdthing, &rect, blueBrush);
		

		//Performs left click if the reticle's red value is >=245.
		if ((1 << 15) & GetAsyncKeyState(0xA2)) { //left ctrl is the trigger key.
			isToggled = true; //Captured the flag!
			//cout << "button pressed" << endl;
			//bool var = getRGBavg(1252, 1273);
			int r = (int)GetRValue(GetPixel(_hdc, 1250, 725));
			if(r >= 245){
				//cout << "YAY" << endl;
				LeftClickDown();
				LeftClickUp();	
				Sleep(5);
			}
		} else {
			isToggled = false; //Dropped the flag!
		}
		
		//Is the toggle key pressed or not?
		//outToggled();
		//it's ok Mr. CPU... I still love you.
		Sleep(5);
		//If the end key has been pressed, exit
		if (GetAsyncKeyState(VK_HOME)) {
			exit(0);
		}
	}
}
/*
method for finding the average rgb values of the given range.
Not really used for this program, but maybe could be used in
some bitmapping solution. There is a better way to do this, but
I will leave that implementation out of the public repo.
*/
bool Scanner::getRGBavg(int startx, int endx) {
	int r, g;
	for (int i = startx; i <= endx; i+=2) {
		r = GetRValue(GetPixel(_hdc, i, 720));
		g = GetGValue(GetPixel(_hdc, i, 720));
		if (r >250 && g < 10) {
			cout << r << " " << g << endl;
			return true;
		}
	}
	return false;
}

//Let's us know whether or not the toggle key is being pressed or not.
//There is probably some fancier way to do this.
//Here comes an awesome game of capture the flag:
void Scanner::outToggled() {
	if (isToggled && !tFlag) {
		system("cls");
		cout << "Trigger enabled" << endl;
		tFlag = true;
		fflag = false;
	}
	else if (!isToggled && !fflag) {
		system("cls");
		cout << "Trigger disabled" << endl;
		tFlag = false;
		fflag = true;

	}
}