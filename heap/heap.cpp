#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cstdio>
#include <fstream>
#include <stdlib.h> 

using namespace std;

void maxHeap(int*, int);
void create(int*, int, int);
void deleteRoot(int*, int&);
void print(int*, int, int, int);
void insert(int*, int&, int);

int main() {
	char input[100];
	bool checkInput = true;
	while (checkInput == true) {
		cout << "To enter numbers, type: NUM. To enter a file, type: FILE" << endl;
		cin >> input;
		int heap[100];
		int len = 0;
		if (strcmp(input, "NUM") == 0) {
			checkInput = false;
			bool stillPlaying = true;
			cin.ignore();
			while (stillPlaying == true) {
				cout << "Please enter your numbers to input into the heap. Type: DONE when finished with all inputs." << endl;
				char enter[1000];
				cin.getline(enter, 1000);
				if (strcmp(enter, "DONE") == 0) {
					stillPlaying = false;
					//break;
				}
				else {
					insert(heap, len, atoi(enter));
				}
			}
		}
		else if (strcmp(input, "FILE") == 0) {
			cout << "Input file name: " << endl;
			char name[100];
			cin.ignore();
			cin.getline(name, 100);
			//cout << "Your file name is: " << name << endl;
			ifstream nF(name);
			checkInput = false;
			int temp;
			while (nF >> temp) {
				insert(heap, len, temp);
			}
		}
		if (checkInput == false) {
			cout << endl;
			maxHeap(heap, len);
			print(heap, len, 0, 1);
			bool temp2 = true;
			while (temp2 == true) {
				cout << "Choose: DELETELARGE, DELETEALL, PRINT, QUIT." << endl;
				char c[100];
				cin >> c;
				if (strcmp(c, "DELETELARGE") == 0) {
					deleteRoot(heap, len);
				}
				else if (strcmp(c, "QUIT") == 0) {
					temp2 = false;
					break;
				}
				else if (strcmp(c, "DELETEALL") == 0) {
					memset(heap, 0, 400);
					cout << "Deleted!" << endl;
				}
				else if (strcmp(c, "PRINT") == 0) {
					//cout << "the len is" << len << endl;
					print(heap, len, 0, 1);
				}
			}
		}
	}
}

void maxHeap(int* heap, int len) {
	for (int i = (len + 1) / 2; i >= 0; i--) {
		create(heap, i + 1, len);
	}
}

void create(int* heap, int i, int len) {
	int left = 2 * i;
	int right = 2 * i + 1;
	int large = i;
	if (left <= len && heap[left - 1] > heap[i - 1]) {
		large = left;
	}
	if (right <= len && heap[right - 1] > heap[large - 1]) {
		large = right;
	}
	if (large != i) {
		int temp = heap[large - 1];
		heap[large - 1] = heap[i - 1];
		heap[i - 1] = temp;
		create(heap, large, len);
	}
}

void deleteRoot(int* heap, int& len) {
	if (!len) return;
	cout << "Deleting " << heap[0] << endl;
	len--;
	if (!len) return;
	heap[0] = heap[len];
	int curr = 0;
	while (true) {
		int left = curr * 2 + 1;
		if (left >= len) return; // Dont traverse tree
		int right = left + 1;
		//swap with smallest child
		if ((right >= len || heap[left] >= heap[right]) && heap[curr] < heap[left]) {
			std::swap(heap[curr], heap[left]);
			curr = left;
			continue;
		}
		if (heap[curr] < heap[right] && right < len) {
			std::swap(heap[curr], heap[right]); //swap
			curr = right;
			continue;
		}
		break;
	}
	return;
}

void print(int* heap, int len, int count, int i) {
	int left = 2 * i;
	int right = 2 * i + 1;
	if (right <= len) {
		print(heap, len, count + 1, right);
	}
	int temp = count;
	while (count > 0) {
		cout << "    ";
		count--;
	}
	cout << heap[i - 1] << endl;
	if (left <= len) {
		print(heap, len, temp + 1, left);
	}
}

void insert(int* heap, int& len, int num) {
	if (len == 100) return;
	int idx = len++;
	heap[idx] = num;
	while (idx != 0) {
		int parent = (idx - 1) / 2;
		if (heap[parent] < heap[idx]) {
			std::swap(heap[parent], heap[idx]);
			idx = parent;
		}
		else break;
	}
}