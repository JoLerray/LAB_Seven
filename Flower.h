#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <array>
#include <math.h>
#include <time.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdexcept>
using namespace std;
class Flower {

private:
	string name;
	string color;
	float cost;
	float timeCut;
	float timeFade;
	float timeFadeWater;
	float wiltRateWater;
	float wiltRate;
	float state;
	bool inWater;
	float timeFlower;
public:
	Flower(string name = "noname", string color = "unknow", float cost = 0, int timeCut = 0, int timeFade = 1, int timeFadeWater = 1);
	string getName();
	string getColor();
	float getState();
	float getWiltRate();
	float getWiltRateWater();
	bool getInWater();
	float getCost();
	bool flowerIsLive();
	void inBottle();
	void outBottle();
	int realyCost();
	void changeTime(int time);
	~Flower();
};