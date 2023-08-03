#include"head.h"

/*
* ��̬���� ������װ
* 
* ����
*		�ڱ������У������������CPU��GPU��Memory��
*		ÿ���������װ��������࣬��ͬ���̣�Intel��Appel����������ͬ�����
*		���������࣬���ṩ�õ��Թ����ĺ��������Ե���ÿ����������Ľӿ�
*		����ʱ��װ��̨��ͬ�ĵ��Խ��й���
*/

// ���������
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

// ���������
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


// ���������
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

// ������
class Computer {
public:

	Computer(AbstractCPU* c, AbstractGPU* g, AbstractMemory* m) :cpu(c), gpu(g), memory(m) {}

	void work() {	
		cpu->work();	// ��̬
		gpu->work();	// ��̬
		memory->work();	// ��̬
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