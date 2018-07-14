#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

/*
	Header class that defines methods for Scanner.cpp. Not used to its full potential, 
	but this is where you will find all of the methods that are defined inside of Scanner.cpp. 
	If you want to add another method to Scanner.cpp, I'd recommend listing it in the header class
	first and then defining its method in the cpp class.
*/
class Scanner {
public:
	INPUT input;
	int _sCenterX;
	int _sCenterY;
	HDC _hdc;
	HDC _drawHDC;
	COLORREF _pix;
	Scanner(int sCenterX, int sCenterY, HDC hdc);
	bool getRGBavg(int x, int y);
	void ScanReticle();
	void shoot();
	void outToggled();
	void LeftClickDown();
	void LeftClickUp();
	void RightClickUp();
	void RightClickDown();
};