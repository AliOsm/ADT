#include <iostream>
#include <memory.h>

using namespace std;

int const MAX = 100000001; // Change maximum number of numbers if needed
bool prime[MAX]; // Status for each number

int main() {
	memset(prime, true, sizeof prime); // Assume every number is prime

	prime[0] = prime[1] = false; // 0 and 1 are not primes

	for(int i = 2; i * i < MAX; ++i)
		if(prime[i])
			for(int j = i * i; j < MAX; j += i)
				prime[j] = false;
	
	return 0;
}
