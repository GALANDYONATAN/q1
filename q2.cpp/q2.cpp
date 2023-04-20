#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#define SIZE 4
using namespace std;
void initData(char* names[], char* ids[], int size);
char* findById(char* ids[], char* names[], int arraySize, const char* idToFind);
bool uniqueArrays(char* ids[], char* names[]);
void freearray(char* names[], char* ids[], int size);

void main() {
	char** Names=new char*[SIZE];
	char** Ids=new char*[SIZE];

	
	initData(Names, Ids, SIZE);
	cout << endl;
	cout<< "the name according to the id 111111111 is: "<<findById(Ids, Names, SIZE, "111111111");
	cout << endl;
	cout << "the name according to the id 222222222 is: " << findById(Ids, Names, SIZE, "222222222");
	cout << endl;
	cout << "the name according to the id 333333333 is: " << findById(Ids, Names, SIZE, "333333333");
	cout << endl;
	cout << "the name according to the id 444444444 is: " << findById(Ids, Names, SIZE, "444444444");
	cout << endl;
	
	initData(Names, Ids, SIZE);
	if (uniqueArrays(Ids, Names) == true) {

		cout << "the array is unique";
	}
	else {
		cout << "the array is not unique";
	}

	freearray( Names, Ids,SIZE);
   


}

void initData(char* names[], char* ids[], int size) {
	char n[100];
	char id[100];
	for (int i = 0; i < size; i++)
	{
		cout << "Please enter a name:" << endl;
		cin.getline(n, 100);
		cout << "Please enter an id:" << endl;
		cin.getline(id, 100);
		names[i] = new char[strlen(n)+1];
		strcpy(names[i], n);
		ids[i] = new char[strlen(id)+1];
		strcpy(ids[i],id);
	}




}

char* findById(char* ids[], char* names[], int arraySize, const char* idToFind) {
	int counter = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (strcmp(ids[i],idToFind)==0) {

		 return names[i];
	    }
		else {
		 counter++;
		}
	}

	if (counter == arraySize) {
	 cout << "id not found";
	 return nullptr;
	}
	
}
bool uniqueArrays(char* ids[], char* names[]) {
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i+1; j <SIZE; j++)
		{
			if (strcmp(names[i] , names[j])==0) {

				if (strcmp(ids[i],ids[j])==0) {

				 return true;
			    }
				else {

				 return false;
				}
		    }
			else {
			count++;
			}
		}
	}

	if (count == SIZE) {

	 return false;

	}


}
void freearray(char* names[], char* ids[], int size) {

	for (int i = 0; i < size; i++)
	{
		delete[] names[i];
		delete[] ids[i];
	}
	delete[] names;
	delete[] ids;
}



