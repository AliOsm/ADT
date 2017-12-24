#include <iostream>
#include <bitset>

using namespace std;

int const MAX = 100000001; // Change maximum number of numbers if needed
bitset<MAX> prime; // Status for each number

int main() {
	prime.set(); // Assume every number is prime

	prime[0] = prime[1] = 0; // 0 and 1 are not primes
	// Even numbers are not primes also
	for(int i = 4; i < MAX; i += 2)
		prime[i] = 0;

	for(int i = 3; i * i < MAX; i += 2)
		if(prime[i])
			for(int j = i * i; j < MAX; j += (i << 1))
				prime[j] = 0;

	return 0;
}
