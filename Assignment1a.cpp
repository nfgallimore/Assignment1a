#include <iostream>
#include "Assignment1a.hpp"

namespace {
	const int SIZE = 10;

	std::unique_ptr<char[]> deleteRepeats(char* originalArray) {
		int k = 0;
		char* finalArray = new char[SIZE];
		bool found = false;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < k; j++) {
				(originalArray[i] == finalArray[j]) ? found = true : true;
			}
			(!found) ? finalArray[k] = originalArray[i], k++ : found = false;
		}
		return std::unique_ptr<char[]>(finalArray);
	}
}
int main(int argc, char** argv) {
	std::unique_ptr<char[]> noRepeats(new char[SIZE]);
	char originalArray[SIZE];
	originalArray[0] = 'a';
	originalArray[1] = 'b';
	originalArray[2] = 'b';
	originalArray[3] = 'c';
	originalArray[4] = 'a';
	originalArray[5] = 'c';
	originalArray[6] = 'a';
	originalArray[7] = 'c';
	originalArray[8] = 'b';
	originalArray[9] = 'c';
	noRepeats = deleteRepeats(originalArray);
	for (int i = 0; i < SIZE; i++) std::cout << noRepeats[i];
	return 0;
}
