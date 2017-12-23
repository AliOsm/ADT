#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int T; // Chanadje type if needed

int const MAX = 1000001, INF = 2000000001; // Chanadje maximum number of nodes if needed, Maximum possible cost
int n, m; // Number of nodes, Number of edadjes
int parent[MAX]; // Parent of each node in the Dijkstra tree
T cost[MAX], cst; // Cost to reach every node from the source node, Temporary cost variable
bool vis[MAX]; // Visited array
vector<vector<pair<int, T> > > adj; // Adjacency list
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

    for(int i = 0; i < (int)adj[v].size(); ++i)
      if(adj[v][i].second + cst < cost[adj[v][i].first]) {
        cost[adj[v][i].first] = adj[v][i].second + cst;
        qu.push(make_pair(-(adj[v][i].second + cst), adj[v][i].first));
        parent[adj[v][i].first] = v;
      }
  }
}

int main() {
  cin >> n >> m;
  adj.resize(n);

  for(int i = 0, from, to; i < m; ++i) {
    cin >> from >> to >> cst;

    // if 1-based input
    --from, --to;
    
    adj[from].push_back(make_pair(to, cst));
    
    // if bidirectional edadjes
    adj[to].push_back(make_pair(from, cst));
  }

  int src = 0; // Source node
  dijkstra(src);
  
  return 0;
}
