#include"head.h"

/*
* 多态案例 制作饮品
* 
* 泡咖啡、泡茶
*/

class AbstractDrink {
public:
	virtual void boilWater(){
		cout << " boiling a pot of water..." << endl;
	}
	virtual void brewIngredients() = 0;
	virtual void pourInCup() = 0;
	virtual void putIngredients() = 0;

	virtual void makeDrink() {
		boilWater();
		brewIngredients();
		pourInCup();
		putIngredients();
	}

	void serveDrink() {
		cout << " please enjoy your dinking...\n" << endl;
	}

};

class Tea :public AbstractDrink {

	virtual void brewIngredients() {
		cout << " brewing some tea..." << endl;
	}
	virtual void pourInCup() {
		cout << " pouring tea into a cup..." << endl;
	}
	virtual void putIngredients() {}

};


class Coffee :public AbstractDrink {

	virtual void brewIngredients() {
		cout << " brewing some coffee..." << endl;
	}
	virtual void pourInCup() {
		cout << " pouring coffee into a cup..." << endl;
	}
	virtual void putIngredients() {
		cout << " putting somr milk and sugar into the coffee..." << endl;
	}

};

static void doWork(AbstractDrink * drink) {
	drink->makeDrink();		// 多态
	drink->serveDrink();
	delete drink;
}

static void test01() {
	//Tea * tea = new Tea;
	//Coffee * coffee = new Coffee;
	//doWork(tea);
	//doWork(coffee);
	//delete tea;
	//delete coffee;

	doWork(new Tea);
	doWork(new Coffee);
}

int main41() {
	
	test01();
	system("pause");
	return 0;
}