#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int T; // Change type if needed

int const MAX = 1001; // Change maximum number of nodes if needed
int n, step = 1; // Number of nodes, Cost to go from one node to another
bool vis[MAX]; // Visited array
bool adj[MAX][MAX]; // Adjacency matrix
queue<int> q; // Queue of unprocessed nodes
T cost[MAX]; // Cost to reach every node from the source node
int parent[MAX]; // Parent of each node in the BFS tree

void bfs(int src) {
  vis[src] = true;
  q.push(src);
  cost[src] = 0;
  parent[src] = src;

  while(!q.empty()) {
    int front = q.front();
    q.pop();
    
    for(int i = 0; i < n; ++i)
      if(adj[front][i] && !vis[i]) {
        vis[i] = true;
        q.push(i);
        cost[i] = cost[front] + step;
        parent[i] = front;
      }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      cin >> adj[i][j];

  int src = 0; // Source node
  bfs(src);
  
  return 0;
}
