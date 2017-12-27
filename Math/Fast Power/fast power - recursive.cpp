#include <iostream>

using namespace std;

typedef int T; // Change type if needed

T fast_power(const T &base, T power) {
	if(power == 0)
		return 1;

	if(power == 1)
		return base;

	T ret = fast_power(base, power / 2);
	ret *= ret;

	if(power % 2 == 1)
		ret *= base;

	return ret;
}

int main() {
	fast_power(2, 3);

	return 0;
}
