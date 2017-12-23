#include <iostream>
#include <algorithm>

using namespace std;

typedef int T; // Change type if needed

int const MAX = 501; // Change maximum number of nodes if needed
T const INF = 1000000001; // Change maximum possible cost
int n; // Number of nodes
T cost[MAX][MAX]; // Cost to reach every node from every node

int main() {
  cin >> n;

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> cost[i][j];
      
      if(cost[i][j] == 0)
        cost[i][j] = INF;
    }
    
    cost[i][i] = 0;
  }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
  
  return 0;
}
