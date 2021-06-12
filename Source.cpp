
#include "Flower.h"
#include "Bouquet.h"
int main()
{
	
	


	Flower roza("Roza", "Green", -100, -24, -128, -256);
	Flower Fiolka("Fiolka", "Red", -100, -24, -128, -256);
	Flower Kelca("kelca", "Black", 100, 24, 125, 256);
	try
	{
		Bouquet b1;
		b1.delFlower();
		b1.addFlower(roza);
		b1.addFlower(Kelca);
		cout << b1.listFlowers() << endl;
		cout << b1.getState() << endl;
		cout << b1.getCost() << endl;
		cout << b1.realyCost() << endl;
		b1.inBottle();
		b1.outBottle();
		cout << b1.countFlowers() << endl;
		b1.changeTime(100);
		cout << b1.countWiltedFlowers() << endl;
		_CrtDumpMemoryLeaks();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
	catch (const std::out_of_range&ex)
	{
		b1.delFlower();
		b1.addFlower(Fiolka);
		cout << ex.what();
	}
	catch (const std::invalid_argument&ex)
	{
		cout << ex.what();
	}
	catch (...) {
		cout << "Exception";
	}
	return 0;

}