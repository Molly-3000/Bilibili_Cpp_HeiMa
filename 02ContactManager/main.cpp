#include"head.h"

int main() {
	Contact contacts[MAX];
	int contactEnd = 0;
	Contact newCon;
	Contact* conP = NULL;
	int instruction = 0;

	while (1) {
		printMenu();
		cin >> instruction;

		switch (instruction){
		case 1:
			defineContact(&newCon);
			contacts[contactEnd] = newCon;
			contactEnd++;
			cout << "Add successfully! "<< endl;
			system("pause");     // 按任意键继续
			system("cls");       // 清屏
			break;

		case 2:
			cout << "There is(are) " << contactEnd << " contacts in total..." << endl;
			for (int i = 0; i < contactEnd; i++) printContact(&contacts[i]);
			system("pause");     // 按任意键继续
			system("cls");       // 清屏
			break;

		case 3:
			findContactByName(contacts, contactEnd, conP);
			deleteContactByPointer(contacts, contactEnd, conP);
			cout << "Delete successfully! " << endl;
			system("pause");     // 按任意键继续
			system("cls");       // 清屏
			break;

		case 4:
			findContactByName(contacts, contactEnd, conP);
			system("pause");     // 按任意键继续
			system("cls");       // 清屏
			break;

		case 5:
			findContactByName(contacts, contactEnd, conP);
			defineContact(conP);
			cout << "Modify successfully! " << endl;
			system("pause");     // 按任意键继续
			system("cls");       // 清屏
			break;

		case 6:
			emptyContacts(contacts, contactEnd);
			cout << "Clear successfully! " << endl;
			cout << "There is(are) " << contactEnd << " contacts in total..." << endl;
			system("pause");     // 按任意键继续
			system("cls");       // 清屏
			break;

		case 0:
			cout << "Good Bye!" << endl;
			system("pause");
			return 0;

		default:
			cout << "Not valid instruction, please reenter!" << endl;
			system("pause");     // 按任意键继续
			system("cls");       // 清屏
			break;
		}

	}
}

void emptyContacts(Contact contacts[],int &contactEnd) {

	//Contact newContacts[1000]; 
	//contacts = newContacts;    // 通过浅拷贝清空原数据

	contactEnd = 0;  // 只做逻辑清空
}

// 删除数组中间的某个数据  == 后面的数据依次前移
void deleteContactByPointer(Contact * contacts, int &contactEnd,const Contact* conP) {
	Contact newContacts[MAX];
	int index = conP-contacts;
	for (int i = index; i < contactEnd; i++) {
		contacts[i] = contacts[i + 1];
	}
	contactEnd--;
}


void printMenu() {
	cout << "==============Contact Manage System==============" << endl;
	cout << "\t 1: \t Add New Contact" << endl;
	cout << "\t 2: \t List Existing Contacts" << endl;
	cout << "\t 3: \t Delete Contact by Name" << endl;
	cout << "\t 4: \t Find Contact by Name" << endl;
	cout << "\t 5: \t Modify Contact by Name" << endl;
	cout << "\t 6: \t Empty Contacts" << endl;
	cout << "\t 0: \t Exit" << endl;
	cout << "Please input instruction ...: " <<endl;
}


void findContactByName(Contact contacts[], int contactEnd, Contact* &conP) {
	string name;
	cout << "Input Name:" << endl;
	cin >> name;

	bool ifFound = false;
	for (int i = 0; i < contactEnd; i++) {
		if (contacts[i].name == name) {
			ifFound = true;
			cout << "Found the Contact ..." << endl;
			conP = &contacts[i];
			printContact(conP);
		}
	}
	if (!ifFound) {
		cout << "This contact doesn't exist! Please check the list." << endl;
		conP = NULL;
	}
}

void printContact(const Contact* con) {
	cout << "Name: " << con->name;
	cout << "\tGender: " << con->gender;
	cout << "\tAge: " << con->age;
	cout << "\tNumber: " << con->number;
	cout << "\tAddress: " << con->address << endl;
}


void defineContact(Contact* conP) {
	cout << "Please Enter the Information..." << endl;
	cout << "Name:";
	cin >> conP->name;
	cout << "Gender:";
	cin >> conP->gender;
	cout << "Age:";
	cin >> conP->age;
	cout << "Number:";
	cin >> conP->number;
	cout << "Address:";
	cin >> conP->address;
}