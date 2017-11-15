#include <iostream>

using namespace std;

int const MAX = 1000; // Change maximum number of nodes if needed
int n, t = 0; // Number of nodes, DFS time
int in[MAX], out[MAX]; // In time for each node, Out time for each node
bool vis[MAX]; // Visited array
bool adj[MAX][MAX]; // Adjacency matrix

void dfs(int node) {
  if(vis[node])
    return;
  
  in[node] = ++t;
  
  vis[node] = true;
  for(int i = 0; i < n; ++i)
    if(adj[node][i])
      dfs(i);
  
  out[node] = ++t;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> adj[i][j];

  int src = 0; // Source node
  dfs(src);
  
  return 0;
}
