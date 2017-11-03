#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+2;
int s[4*maxn];
int a[maxn];
int n;

void build(int l=0, int r=n, int node=1){
	if (r-l==1){
		s[node] = a[l];
		return;
	}
	build(l, (l+r)/2, 2*node);
	build((l+r)/2), r, 2*node+1);
	s[node] = s[2*node] + s[2*node+1];
}

void modify(int p, int x, int l=0, int r=n, node=1){
	s[node] += x - a[p];
	if (r-l==1){
		// s[node] = x;
		a[p] = x;
		return;
	}
	// s[node] += x - a[p];
	if (p < (l+r)/2){
		modify(p, x, l, (l+r)/2, 2*node);
	}
	else modify(p, x, (l+r)/2, r, 2*node+1);
}

int sum(int l=0, int r=n, int node=1, int x, int y){
	if (y <= l || x >= r) return 0;
	if (x <= l && y >= r) return s[node];
	return sum(l, (l+r)/2, 2*node, x, y) + sum((l+r)/2, r, 2*node+1, x, y);
}