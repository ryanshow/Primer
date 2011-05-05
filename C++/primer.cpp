// Prime Number Generator
// Coded by Tank

//cout
#include <iostream>

//sqrt
#include <cmath>

//atoi
#include <stdlib.h>

//vector
#include <vector>

int main(int argc, char **argv) {

	int numprimes = 10000;
	std::vector<int> plist;
	std::vector<int>::iterator it;

	//Check to see if the user wants a certain number of primes
	if (argc > 1) {
		numprimes = atoi(argv[1]);
	}

	// 2 is prime by definition, so add it first.
	plist.insert(plist.end(), 2);	

	int x = 1;

	// Loop through this algorithm until we acquire the desired number of primes
	while (plist.size() < numprimes) {
		//This complicated looking incriment just skips anything ending in 5
		x+=((x+2)>5&&(x+2)%5==0)?4:2;

		bool isPrime = true;

		it = plist.begin();
		// Continue comparing until the number is either proven not to be prime
		// or it reaches the maximum possible comparison number, which makes it prime.
		int root = sqrt(x);
		while(*it <= root) {
			if(x%(*it) == 0) {
				isPrime = false;
				break;
			}
			it++;
		}

		// If the number is prime, then create a new prime node and assign it the prime number
		if (isPrime) {
			plist.insert(plist.end(), x);
		}
	}

	std::cout << std::endl << std::endl;

	// Print out our newly discovered primes; it actually takes an order of
	// magnitude of time longer to print than it does to generate the primes

	for (it = plist.begin(); it != plist.end(); it++)
		std::cout << (*it) << ", ";

	std::cout << std::endl << std::endl;
}
