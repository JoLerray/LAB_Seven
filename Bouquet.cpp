#include "Bouquet.h"

Bouquet::Bouquet(Flower F) 
{
	flowers.push_back(F);

};
void Bouquet::addFlower(Flower F) {
	flowers.push_back(F);
}
void Bouquet::addFlower(int n,Flower F,...) {
	for (int* ptr = &n; n > 0; n--) {
		flowers.push_back(F);
	}
}
void Bouquet::addFlower(vectorFlower<Flower> F) {
	for (int i = 0; i < F.len(); i++)
		flowers.push_back(F[i]);
}
void Bouquet::delFlower() {
	flowers.pop_back();
}
void Bouquet::delFlower(int index) {
	if (index < 0 || index>flowers.len()) throw out_of_range("Index is out of range array");
	flowers[index] = flowers.back();
	flowers.pop_back();
}
string Bouquet::listFlowers() {
	string list;
	for (int i = 0; i < flowers.len(); i++)
		list += flowers[i].getName() + ' ';
	return list;
}

float Bouquet::getState() {
	float state = 0;
	for (int i = 0; i < flowers.len(); i++)
		state += flowers[i].getState();

	return state / flowers.len();
}
float Bouquet::getCost() {
	float cost = 0.00;
	for (int i = 0; i < flowers.len(); i++)
		cost += flowers[i].getCost();

	return cost;
}
int Bouquet::realyCost() {
	int cost = 0;
	for (int i = 0; i < flowers.len(); i++)
		cost += flowers[i].realyCost();

	return cost;
}
void Bouquet::inBottle() {
	for (int i = 0; i < flowers.len(); i++)
		flowers[i].inBottle();

}
void Bouquet::outBottle() {
	for (int i = 0; i < flowers.len(); i++)
		flowers[i].outBottle();

}
int Bouquet::countFlowers() {
	return flowers.len();
}
int Bouquet::countWiltedFlowers() {
	int count = 0;
	for (int i = 0; i < flowers.len(); i++)
		if (flowers[i].getState() == 0)
			count++;

	return count;
}
void Bouquet::changeTime(int time) {
	if (time < 0) throw invalid_argument("Invalid value");
	for (int i = 0; i < flowers.len(); i++)
		flowers[i].changeTime(time);
}


Bouquet :: ~Bouquet() {
}

