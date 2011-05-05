/*

Started and Finished on November 12, 2009
by Ryan Showalter

Simple prime number generator, written in Google's "Go" programming language
Check out http://www.golang.org for more info.

To compile:

#> 6g primer.go
#> 6l primer.6
#> ./6.out

If you're on x86, replace 6g and 6l with 8g and 8l respectively
If you're compiling for arm, use 5g and 5l

I don't know how to compile using gccgo yet

You can specify how many primes you want it to generate with the "-n" flag

*/

package main

import ("fmt" ; 
	"math";
	"flag";)

func main() {
	//Handy method for handling command-line flags
	maxp := flag.Int("n", 10000, "Numer of primes to generate");
	flag.Parse();

	//Dynamically allocate our storage array
	plist := make([]int, *maxp);

	//Declare some variables
	plist[0] = 2;
	nprimes := 1;
	x := 1;

	for nprimes < *maxp {
		x += 2;
		isPrime := checkPrime(x, plist[0:nprimes]);
		if isPrime {
			plist[nprimes] = x;
			nprimes++;
		}
	}

	//Print out the primes
	for i := 0; i < nprimes; i++ {
		fmt.Print(plist[i], ", ");
	}
	fmt.Println();
}

func checkPrime(x int, plist []int) bool {
	root := math.Sqrt(float64(x));
	for i := 0; i < len(plist) && root >= float64(plist[i]); i++ {
		if x % plist[i] == 0 {
			return false;
		}
	}

	return true;
}
