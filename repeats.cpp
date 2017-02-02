/* Nicholas Gallimore */
/* Contains the function deleteRepeats which takes array of chars and returns array of the unique characters */
/* repeats.cpp file */

#include "repeats.hpp"

// takes an array of chars and returns a unique_ptr to a version of the inputed array that contains no duplicate characters
std::unique_ptr<char[]> deleteRepeats(char* originalArray)
{
	// dynamically allocated array that will be attached to the returned unique_ptr containing final version of array
	char* finalArray = new char[SIZE + 1];
	
	// tracks how many unique characters have been found thus far
	int counter = 0;

	// iterates through array to find an element that we will be checked against all other elements in the array
	for (int i = 0; i < SIZE; i++)
    {
		// true if character is already in finalArray
		bool found = false;

    	// checking all other elements to see if our i'th index element is equal to any of them
		for (int j = 0; j < counter; j++)
        {
        	// if ith element is found in finalArray already
			if (originalArray[i] == finalArray[j])
			{
				found = true;
			}
		}
		// if ith element not found in finalArray insert it, increment counter index, else reset to false
		(!found) ? finalArray[counter] = originalArray[i], counter++ : 1;
	}

	// cleans remaining original array spots with terminator and adds terminator to finalArray[SIZE+1] to catch case where there are no duplicate characters
	// for (int i = counter; i < SIZE + 1; i++) 
	// {
	// 	finalArray[i] = '\0';
	// }
	finalArray[counter] = '\0';

	// returns a unique smart pointer to finalArray
	return std::unique_ptr<char[]>(finalArray);
}