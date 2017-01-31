/* Nicholas Gallimore */
/* Removes repeat characters from a test array of characters */
/* main.cpp */

#include <iostream>

#include "main.hpp"

int main(int argc, char** argv)
{
	// init of final array removed of repeat letters
	std::unique_ptr<char[]> noRepeats(new char[SIZE]); 

	// test array
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

	int repeats = 0; // indicates number of repeats

	// prints the array
	for (int i = 0; i < SIZE; i++)
    {
    	(!isalpha(noRepeats[i])) ? repeats++ : std::cout << noRepeats[i];
    }

    // prints number of repeats
    std::cout << "\nNumber of repeats: " << repeats << std::endl;

	return 0; // successful execution
}

// takes an array of chars and returns a unique_ptr to a version of the inputed array that contains no duplicate characters
std::unique_ptr<char[]> deleteRepeats(char* originalArray)
{
	// dynamically allocated array that will be attached to the returned unique_ptr containing final version of array
	char* finalArray = new char[SIZE];
	
	// tracks current index of finalArray
	int counter = 0;

	// true if character is already in finalArray
	bool found = false; 

	// iterates through array to find an element that we will be checked against all other elements in the array
	for (int i = 0; i < SIZE; i++)
    {
    	// checking all other elements to see if our i'th index element is equal to any of them
		for (int j = 0; j < counter; j++)
        {
        	// if ith element is found in finalArray already
			if (originalArray[i] == finalArray[j])
			{
				found = true;
			}
		}
		// if ith element not found in finalArray insert it, increment counter index and reset found to false
		(!found) ? finalArray[counter] = originalArray[i], counter++ : found = false;
	}
	return std::unique_ptr<char[]>(finalArray); // returns a unique smart pointer to finalArray
}
