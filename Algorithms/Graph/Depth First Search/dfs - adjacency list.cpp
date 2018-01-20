#include <iostream>
#include <vector>

using namespace std;

int const MAX = 1000001; // Change maximum number of nodes if needed
int n, m, t = 0; // Number of nodes, Number of edges, DFS time
int in[MAX], out[MAX]; // In time for each node, Out time for each node
bool vis[MAX]; // Visited array
vector<vector<int> > adj; // Adjacency list
int parent[MAX]; // Parent of each node in the DFS tree

void dfs(int node) {
  in[node] = ++t;
  
  vis[node] = true;
  for(int i = 0; i < (int)adj[node].size(); ++i) {
    int child = adj[node][i];
    
    if(!vis[child]) {
      parent[child] = node;
      dfs(child);
    }
  }
  
  out[node] = ++t;
}

int main() {
  cin >> n >> m;
  adj.resize(n);
  for(int i = 0, from, to; i < m; ++i) {
    cin >> from >> to;

    // if 1-based input
    --from, --to;
    
    adj[from].push_back(to);
    
    // if bidirectional edges
    adj[to].push_back(from);
  }

  int src = 0; // Source node
  parent[src] = src;
  dfs(src);
  
  return 0;
}
