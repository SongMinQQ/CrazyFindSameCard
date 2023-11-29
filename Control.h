#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include <iostream> 
#include <Windows.h>
#include <conio.h>
using namespace std;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

class control
{
public:

	void gotoxy(int x, int y);
	int keyControl();
private:

};



#endif