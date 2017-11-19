#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int T; // Change type if needed

int const MAX = 1000001; // Change maximum number of nodes if needed
int n, m, step = 1; // Number of nodes, Number of edges, Number of edges
bool vis[MAX]; // Visited array
vector<vector<int> > adj; // Adjacency list
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
    
    for(int i = 0; i < (int)adj[front].size(); ++i) {
      int child = adj[front][i];
      
      if(vis[child])
        continue;
      
      vis[child] = true;
      q.push(child);
      cost[child] = cost[front] + step;
      parent[child] = front;
    }
  }
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
  bfs(src);
  
  return 0;
}
