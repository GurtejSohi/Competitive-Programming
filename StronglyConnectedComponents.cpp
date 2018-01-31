#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+2;
vector<int> adj[2][maxn];	// 0- normal; 1- reversed
bool vis[maxn];
// int dis[maxn];
// int fin[maxn];
vector<int> orderedNodes;	// nodes ordered in desc order of fin. time
int mytime = 0;
vector< vector<int> > connectedComp;
vector<int> currentComp;

void dfs(int node, int i){	// i=0-> normal dfs; i=1-> dfs on reversed graph;
	vis[node] = 1;
	// if (i==0) dis[node] = ++mytime;
	for(int ch : adj[i][node]){
		if (!vis[ch]) dfs(ch, i);
	}
	if (i==0) orderedNodes.push_back(node);
	else currentComp.push_back(node);
	// if (i==0) fin[node] = ++mytime;
}

int main(){
	int n, m;
	cin >> n >> m;
	int u, v;
	for(int i=0; i<m; ++i){
		cin >> u >> v;
		adj[0][u].push_back(v);
		adj[1][v].push_back(u);
	}

	for(int i=1; i<=n; ++i){
		if (!vis[i]) dfs(i, 0);
	}
	assert(orderedNodes.size() == n);
	memset(vis, 0, sizeof(vis));

	for(int i=n-1; i>=0; --i){
		// if (!vis[i]) {	--------- WRONG
		if (!vis[orderedNodes[i]]) {
			// cerr << "i:" << i << " orderedNodes[i]:" << orderedNodes[i] << endl;
			// dfs(i, 1);	---------- WRONG
			dfs(orderedNodes[i], 1);
			connectedComp.push_back(currentComp);
			// cerr << "sz : " << currentComp.size() << endl;	
			// for(int j : currentComp) cerr << j << ",";
			// cerr << endl;
			currentComp.clear();
		}
	}

	// now we have all strongly connected components in connectedComp.

	int c=0, d=0;
	for(int i=0; i < connectedComp.size(); ++i){
		int sz = connectedComp[i].size();
		// cerr << "sz : " << sz << endl;
		if (sz & 1) c += sz;
		else d += sz;
	}
	cout << c-d << endl;

	return 0;
}