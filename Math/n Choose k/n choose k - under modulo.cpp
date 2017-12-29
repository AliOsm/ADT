#include <iostream>

using namespace std;

typedef int T; // Change type if needed

int const MAX = 1000001; // Change maximum number of numbers if needed
T const MOD = 1000000007; // Change MOD if needed, MOD is big prime number
T fact[MAX], ifact[MAX]; // Factorial array, Factorial inverse array

// Fast Power
T fast_power(const T &base, const T &power) {
  if(power == 0)
    return 1;

  if(power == 1)
    return base;

  T ret = fast_power(base, power / 2) % MOD;
  ret = 1ll * ret * ret % MOD;

  if(power % 2 == 1)
    ret = 1ll * ret * base % MOD;

  return ret;
}

T n_choose_k(const T &n, const T &k) {
  return 1ll * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < MAX; ++i) {
    fact[i] = 1ll * fact[i - 1] * i % MOD;
    ifact[i] = fast_power(fact[i], MOD - 2);
  }

  n_choose_k(3, 2);
  
  return 0;
}
