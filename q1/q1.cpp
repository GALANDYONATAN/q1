#include <iostream>
#include <cstring>
#define SIZE 18
using namespace std;
int find_min_len_sequence(int* arr, int size, int& min_len, int num = 0);
void main() {
	int arr[SIZE]={4,4,3,3,3,1,45,3,3,25,3,3,3,3,4,4,4,3};
	int min_len = 0;
	int index = 0;
	cout << "In the array:";
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << ",";
	}
	cout << endl;
	index=find_min_len_sequence(arr, SIZE, min_len, 3);
	 cout << "The minimal sequence of the number " <<3;
	 cout << " is of the size: " << min_len << " starting at index: " << index;
	 cout << endl;

	 index = find_min_len_sequence(arr, SIZE, min_len, 4);
	 cout << "The minimal sequence of the number " <<4;
     cout << " is of the size: " << min_len << " starting at index: " << index;
	 cout << endl;

	 index = find_min_len_sequence(arr, SIZE, min_len, 17);
	 cout << "The minimal sequence of the number " << 17;
     cout << " is of the size: " << min_len << " starting at index: " << index;
	 cout << endl;

	 index = find_min_len_sequence(arr, SIZE, min_len);
	 cout << "The minimal sequence of the number " << 0;
	 cout << " is of the size: " << min_len << " starting at index: " << index;

}
int find_min_len_sequence(int* arr, int size, int& min_len, int num) {
	int count = 0;
	int current = 0;
	int index = 0;
	min_len = 0;
	for (int j = 0; j < size; j++)
	{
		if (arr[j]!=num) {

		 count++;
	    }
	}
	if (count == size) {
	 min_len = 0;
	 return -1;
	}
	count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num) {

		  count++;
		  if (i < size - 1) {
			  continue;
		  }
		  
		}
		current = count;
		count = 0;
		if (min_len > current ||min_len==0) {
			if (current == 0) {

			 continue;
			}
			min_len = current;
			index = i;
	 	}
	}

	if (index == size - 1) {

	 return index;
	}

	return index - min_len;


}












