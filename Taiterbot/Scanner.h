#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Scanner {
public:
	INPUT input = { 0 };
	int _sCenterX;
	int _sCenterY;
	HDC _hdc;
	Scanner(int sCenterX, int sCenterY, HDC hdc);
	void ScanReticle();
	void LeftClickDown();
	void LeftClickUp();
};
