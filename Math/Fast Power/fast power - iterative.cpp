#include <iostream>

using namespace std;

typedef int T; // Change type if needed

T fast_power(T base, T power) {
	T ret = 1;

	while(power > 0) {
		if(power % 2 == 0) {
			power /= 2;
			base *= base;
		} else {
			--power;
			ret *= base;

			power /= 2;
			base *= base;
		}
	}

	return ret;
}

int main() {
	fast_power(2, 3);

	return 0;
}
