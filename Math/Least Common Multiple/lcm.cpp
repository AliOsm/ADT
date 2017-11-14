#include <iostream>

using namespace std;

typedef int T; // Change type if needed

T gcd(T a, T b) { // Greatest Common Divisor
  if(b == 0)
    return a;
  
  return gcd(b, a % b);
}

T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

int main() {
  T a, b;
  
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  
  return 0;
}
