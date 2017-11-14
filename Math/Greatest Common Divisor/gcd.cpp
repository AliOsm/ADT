#include <iostream>

using namespace std;

typedef int T; // Change type if needed

T gcd(T a, T b) {
  if(b == 0)
    return a;
  
  return gcd(b, a % b);
}

int main() {
  T a, b;
  
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  
  return 0;
}
