/* Nicholas Gallimore */
/* Driver program to test function that removes repeat characters from a test array of characters */
/* main.cpp */

#include "repeats.cpp"

int main(int argc, char** argv)
{
	// init of final array removed of repeat letters
	std::unique_ptr<char[]> noRepeats;

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

	return 0; // successful execution returns 0
}