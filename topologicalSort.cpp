// code taken from my solution for #460-D
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+2;
vector<int> adj[maxn];
vector<int> revTopSort;
bool vis[maxn];
bool fin[maxn];

bool dfs(int node){		// returns 1 if cycle found
	vis[node] = 1;
	for(int ch : adj[node]){
		// cerr << "node:" << node << " ch:" << ch << endl;
		// cerr << "vis:" << vis[ch] << " fin:" << fin[ch] << endl;
		if (vis[ch] && !fin[ch]) return 1;
		// if (!vis[ch]) dfs(ch);		// MISTAKE
		if (!vis[ch]){
			if (dfs(ch)) return 1;
		}
	}
	fin[node] = 1;
	revTopSort.push_back(node);
	return 0;
}

int main(){
	int n, m;
	cin >> n >> m;
	int u, v;
	for(int i=0; i<m; ++i){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}

	for(int i=1; i<=n; ++i){
		if (!vis[i] && dfs(i)){
			cout << "Cycle found ... So topological ordering not possible\n";
			return 0;
		}
	}
	// Now we have nodes topologically sorted in reverse order in revTopSort vector

	return 0;
}