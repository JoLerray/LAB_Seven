#pragma once
#include "Flower.h"

#define N 15

array<string, 10> COLORS = { "Blue", "Green", "Yellow", "Red", "White", "Orange","Purple","Pink","Black","Gray" };

Flower::Flower(string name, string color, float cost, int timeCut, int timeFade, int timeFadeWater) {

	this->name = name;

	for (int i = 0; i < 10; i++) {

		this->color = "unknow";

		if (color == COLORS[i]) {
			this->color = color;
			break;
		}

	}


	this->cost = abs(cost);
	this->timeCut = abs(timeCut);
	this->timeFade = abs(timeFade);
	this->timeFadeWater = abs(timeFadeWater);
	timeFlower = abs(timeCut);
	wiltRateWater = abs(rand() % timeFadeWater) / 100.0;
	wiltRate = wiltRateWater * 2;
	inWater = false;
	state = 1 - timeFlower / abs(timeFade);
}

string Flower::getName() {
	return name;
}

string Flower::getColor() {
	return color;
}

float Flower::getState() {
	return state;
}

float Flower::getWiltRate() {
	return wiltRate;
}

float Flower::getWiltRateWater() {
	return wiltRateWater;
}

bool Flower::getInWater() {
	return inWater;
}

float Flower::getCost() {
	return cost;
}

bool Flower::flowerIsLive() {
	if (state > 0)
		return true;
	else
		return false;
}

void  Flower::inBottle() {
	inWater = true;
}


void Flower::outBottle() {
	inWater = false;
}

int Flower::realyCost() {
	int realcost;
	
	if (inWater)
		realcost = cost * (timeFadeWater - timeFlower) / timeFadeWater;
	else 
		realcost = cost * (timeFade - timeFlower) / timeFade;
	if (realcost < 0) realcost = 0;
	return realcost;
	
}

void Flower::changeTime(int time) {

	if (inWater)
		timeFlower += abs(time * wiltRateWater);
	else
		timeFlower += abs(time * wiltRate);

	if (inWater)
		state = 1 - timeFlower / timeFadeWater;
	else
		state = 1 - timeFlower / timeFade;
	if (state < 0)
		state = 0;
}
Flower :: ~Flower() {
	
}