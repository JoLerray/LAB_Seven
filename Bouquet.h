#pragma once
#include "Flower.h"
#include "vectorFlower.h"
#include <vector>
class Bouquet {
private:
	vectorFlower <Flower> flowers;
public:
	Bouquet(Flower F = Flower());
	void addFlower(Flower);
	void addFlower(vectorFlower <Flower>);
	void addFlower(int,Flower,...);
	void delFlower(int);
	void delFlower();
	string listFlowers();
	float getState();
	//bool getInWater();
	float getCost();
	void inBottle();
	void outBottle();
	int realyCost();
	int countFlowers();
	int countWiltedFlowers();
	void changeTime(int);
	~Bouquet();
	
};