#include <iostream>

using namespace std;

typedef int T; // Change type if needed

int const MAX = 11; // Change maximum number of numbers if needed
T fact[MAX]; // Factorial array

T n_choose_k(const T &n, const T &k) {
  return 1ll * fact[n] / (fact[k] * fact[n - k]);
}

int main() {
  fact[0] = 1;
  for(int i = 1; i < MAX; ++i)
    fact[i] = 1ll * fact[i - 1] * i;

  n_choose_k(3, 2);
  
  return 0;
}
