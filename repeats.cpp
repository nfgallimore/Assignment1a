/* Nicholas Gallimore */
/* Contains the function deleteRepeats which removes repeat characters from an array of characters */
/* repeats.hpp file */

#include "repeats.hpp"

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