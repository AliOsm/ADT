#include <bits/stdc++.h>
using namespace std;

int const MAX = 1000001; // Change maximum number of nodes if needed
int n, m, u, v; // Number of nodes, Number of edges, DFS time
bool vis[MAX]; // Visited array
vector<vector<int> > adj; // Adjacency list
stack<int>sk;

void dfs(int node) {
	vis[node] = true;
	for(int i = 0; i < (int)adj[node].size(); ++i) {
		int child = adj[node][i];

		if(!vis[child]) 
			dfs(child);
	}
	sk.push(node);
}
void print(){
	while(!sk.empty()){
		printf("%d ",sk.top());
		sk.pop();
	}
	puts("");
}
void TopologicalSort(){
	for(int i=0;i<n;++i)
		if(!vis[i])
			dfs(i);

	print();
}
int main(){
	scanf("%d%d",&n,&m);
	adj.resize(n);

	while(m--){
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
	}
	TopologicalSort();
	return 0;
}