#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#define SIZE1 5
#define SIZE2 3
using namespace std;

char* newarray(char* arr1, char* arr2, int size1, int size2, int& size_len);
void main() {

	char arr1[SIZE1] = { 'a','b','c','d','f'};
	char arr2[SIZE2] = {'b','f','k'};
	int size_len = 0;
	char* newarray1 = newarray(arr1, arr2, SIZE1, SIZE2, size_len);
	cout << "the new array is: " << endl;
	for (int i = 0; i < size_len; i++)
	{
	 cout <<newarray1[i] << ",";
	}
	delete[] newarray1;



}
char* newarray(char* arr1, char* arr2, int size1,int size2,int& size_len) {
 int count = 0;
 int i = 0;
 int j = 0;
 int k = 0;
 while (i<size1 && j<size2) {
  
	 if (arr1[i] == arr2[j]) {

	 count++;
	 i++;
	 j++;
	 }
	 else {

		 if (arr1[i] < arr2[j]) {

		  i++;
		 }
		 else {

		  j++;
		 }

	 }
	 

 }
 char* newarray2 = new char[count];
 for (int p = 0; p <count; p++)
 {
  newarray2[p] = 0;
 }
 i = 0;
 j = 0;
 k = 0;
 while (i < size1 && j < size2) {

	 if (arr1[i] == arr2[j]) {
		 if (k < count) {

		  newarray2[k] = arr2[j];
	     }
	  
	  i++;
	  j++;
	  k++;
	  
	 }
	 else {

		 if (arr1[i] < arr2[j]) {

			 i++;
		 }
		 else {

			 j++;
		 }
	 }
	 

 }
 size_len = count;
 return newarray2;

}
