#include <iostream>
#include <algorithm>

using namespace std;

typedef int T; // Change type if needed

struct edge {
	int from, to;
	T cost;
	edge() {}
	edge(int from, int to, int cost) :
		from(from), to(to), cost(cost) {}
	bool operator<(const edge &e) const {
		return cost < e.cost;
	}
};

int const MAX = 1000001; // Change maximum number of {nodes, edges} if needed
int n, m; // Number of nodes, Number of edges
int ds[MAX]; // Disjoint Set Union array
edge edges[MAX], taken_edges[MAX]; // Original edges array, Taken edges array

int find(int x) {
	return x == ds[x] ? x : ds[x] = find(ds[x]);
}

void kruskal() {
	for(int i = 0; i < n; ++i)
		ds[i] = i;

	int taken = 0; // Number of taken edges until now
	for(int i = 0, from, to; i < m && taken < n - 1; ++i) {
		from = find(edges[i].from);
		to = find(edges[i].to);

		if(from != to) {
			ds[from] = to;
			taken_edges[taken] = edges[i]; // if you need tree edges
			++taken;
		}
	}
}

int main() {
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
		cin >> edges[i].from >> edges[i].to >> edges[i].cost;
	sort(edges, edges + m);

	kruskal();

  return 0;
}
