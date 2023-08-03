#include"head.h"

/*
* 多态案例 电脑组装
* 
* 需求：
*		在本案例中，电脑主板包括CPU，GPU和Memory，
*		每个零件都封装出抽象基类，不同厂商（Intel和Appel）将生产不同的零件
*		创建电脑类，并提供让电脑工作的函数，可以调用每个零件工作的接口
*		测试时组装三台不同的电脑进行工作
*/

// 抽象零件类
class AbstractCPU {
public:
	virtual void work() = 0;
};

class AbstractGPU {
public:
	virtual void work() = 0;
};

class AbstractMemory {
public:
	virtual void work() = 0;
};

// 厂商零件类
class IntelCPU :public AbstractCPU {
	void work() {
		cout << " Intel CPU is working..." << endl;
	}
};
class IntelGPU :public AbstractGPU {
	void work() {
		cout << " Intel GPU is working..." << endl;
	}
};
class IntelMemory :public AbstractMemory {
	void work() {
		cout << " Intel Memory is working..." << endl;
	}
};


// 厂商零件类
class AppleCPU :public AbstractCPU{
	void work() {
		cout << " Apple CPU is working..." << endl;
	}
};
class AppleGPU :public AbstractGPU{
	void work() {
		cout << " Apple GPU is working..." << endl;
	}
};
class AppleMemory :public AbstractMemory{
	void work() {
		cout << " Apple Memory is working..." << endl;
	}
};

// 电脑类
class Computer {
public:

	Computer(AbstractCPU* c, AbstractGPU* g, AbstractMemory* m) :cpu(c), gpu(g), memory(m) {}

	void work() {	
		cpu->work();	// 多态
		gpu->work();	// 多态
		memory->work();	// 多态
	}

	~Computer() {
		delete cpu, gpu, memory;
	}

private:
	AbstractCPU * cpu;
	AbstractGPU * gpu;
	AbstractMemory * memory;

};

static void test01() {

	AbstractCPU* cpu1 = new IntelCPU;
	AbstractCPU* cpu2 = new AppleCPU;
	AbstractGPU* gpu1 = new IntelGPU;
	AbstractGPU* gpu2 = new AppleGPU;
	AbstractMemory* memory1 = new IntelMemory;
	AbstractMemory* memory2 = new AppleMemory;

	Computer cpt1(cpu1, gpu1, memory1);
	Computer cpt2 = Computer(cpu2, gpu2, memory2);
	Computer cpt3(new IntelCPU, new AppleGPU, new IntelMemory);
	
	cout << " Computer A is working..." << endl;
	cpt1.work();
	cout << endl << " Computer B is working..." << endl;
	cpt2.work();
	cout << endl << " Computer C is working..." << endl;
	cpt3.work();

}

int main43() {

	test01();
	system("pause");
	return 0;
}