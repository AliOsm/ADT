#include <iostream>
#include <algorithm>

using namespace std;

typedef int T; // Change type if needed

int const MAX = 501; // Change maximum number of nodes if needed
T const INF = 1000000001; // Change maximum possible cost
int n, m; // Number of nodes, Number of edges
T cost[MAX][MAX], cst; // Cost to reach every node from every node, Temporary cost variable

int main() {
  cin >> n >> m;

  for(int i = 0; i < n; ++i) {
    fill(cost[i], cost[i] + n, INF);
    cost[i][i] = 0;
  }

  for(int i = 0, from, to; i < m; ++i) {
    scanf("%d %d %d", &from, &to, &cst);

    // if 1-based input
    --from, --to;

    cost[from][to] = min(cost[from][to], cst);

    // if bidirectional edges
    cost[to][from] = min(cost[to][from], cst);
  }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
  
  return 0;
}
