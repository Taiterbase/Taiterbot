#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

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