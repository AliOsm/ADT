#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h> 
using namespace std;
#define oo 2000000007 // Change Maximum possible cost
#define N 100005 //Change Maximum number of nodes if needed
typedef int T;//Change type if needed
int n,m;//n nodes & m edges
int from,to,cst;
vector<vector<pair<int,T> > >adj; // Adjacency list
T cost[N];
int per[N];
bool vis[N];
void prim(int &src){
	for(int i = 0 ; i <= n ; ++i){
		cost[i] = oo;
		per[i] = -1;
	}
	
	priority_queue< pair < T , int > >pq; //Nodes queue
	cost[src]=0;
	pq.push(make_pair(0,src));
	
	while(!pq.empty()){
		T c = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		
		if(vis[u])continue;
		vis[u] = 1;
		
		for(int i=0;i<(int)adj[u].size();++i){
			int v = adj[u][i].first;
			
			if(adj[u][i].second < cost[v] && !vis[v]){
				cost[v] = adj[u][i].second;
				per[v] = u;
				pq.push(make_pair(-cost[v],v));
			}
		}
	}
}
int main(){
	cin >>n>>m;
	adj.resize(n+1);
	while(m--){
		cin >>from>>to>>cst;
		// if 1-based input
    	//--from, --to;
		adj[from].push_back(make_pair(to,cst));
		// if undirected Graph
		adj[to].push_back(make_pair(from,cst));
	}
	int src;
	cin >>src;//Source node
	prim(src);
	return 0;
}