#pragma once
#include<iostream>
using namespace std;

#include<string>

#define MAX 1000

struct Contact {
	string name;
	string gender;
	int age;
	char number[11];
	string address;
};

void printMenu();

void findContactByName(Contact contacts[], int contactEnd, Contact* &conP);

void printContact(const Contact* con);

void defineContact(Contact* conP);

void deleteContactByPointer(Contact * contacts, int &contactEnd, const Contact* conP);

void emptyContacts(Contact contacts[], int& contactEnd);