// reference : http://codeforces.com/blog/entry/15729

#include <bits/stdc++.h>
using namespace std;

#define mid(x, y) (x+y)/2
const int maxn=1e5+2;
int s[4*maxn];
int a[maxn];
int n;

void build(int l=0, int r=n, int node=1){
	if (r-l==1){
		s[node] = a[l];
		return;
	}
	build(l, mid(l, r), 2*node);
	build(mid(l, r), r, 2*node+1);
	s[node] = s[2*node] + s[2*node+1];
}

void modify(int p, int x, int l=0, int r=n, int node=1){
	// s[node] += x - a[p];
	if (r-l==1){
		s[node] = x;
		a[p] = x;	// not required
		return;
	}
	if (p < mid(l, r)) modify(p, x, l, mid(l, r), 2*node);
	else modify(p, x, mid(l, r), r, 2*node+1);
	s[node] = s[2*node] + s[2*node+1];
}

int sum(int x, int y, int l=0, int r=n, int node=1){
	if (y <= l || x >= r) return 0;
	if (x <= l && y >= r) return s[node];
	return sum(x, y, l, mid(l, r), 2*node) + sum(x, y, mid(l, r), r, 2*node+1);
}