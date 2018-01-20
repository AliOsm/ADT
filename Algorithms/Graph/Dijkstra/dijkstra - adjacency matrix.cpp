#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int T; // Change type if needed

int const MAX = 1001; // Change maximum number of nodes if needed
T const INF = 2000000001; // Change maximum possible cost
int n; // Number of nodes
int parent[MAX]; // Parent of each node in the Dijkstra tree
T adj[MAX][MAX], cost[MAX], cst; // Cost to reach every node from the source node, Temporary cost variable
bool vis[MAX]; // Visited array
priority_queue<pair<T, int> > qu; // Nodes queue

void dijkstra(int src) {
  for(int i = 0; i < n; ++i)
    cost[i] = INF;
  cost[src] = 0;

  while(!qu.empty())
    qu.pop();
  qu.push(make_pair(-cost[src], src));

  parent[src] = src;

  while(!qu.empty()) {
    int v = qu.top().second;
    cst = -qu.top().first;

    qu.pop();

    if(vis[v])
      continue;
    vis[v] = true;

    for(int i = 0; i < n; ++i) {
      if(adj[v][i] == -1)
        continue;

      if(adj[v][i] + cst < cost[i]) {
        cost[i] = adj[v][i] + cst;
        qu.push(make_pair(-(adj[v][i] + cst), i));
        parent[i] = v;
      }
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) {
      cin >> adj[i][j];

      // Consider there is no edge if the cost equal to 0
      if(adj[i][j] == 0)
        adj[i][j] = -1;
    }

  int src = 0; // Source node
  dijkstra(src);
  
  return 0;
}
