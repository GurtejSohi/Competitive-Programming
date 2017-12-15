// reference : 1 - http://codeforces.com/blog/entry/15729
// reference : 2 - https://s3.amazonaws.com/codechef_shared/download/Solutions/JAN15/Setter/QSET.cpp

#include <bits/stdc++.h>
using namespace std;

#define mid(x, y) (x+y)/2
const int maxn=1e5+2;
// int s[4*maxn];
int a[maxn];
int n;

// modify defintion of struct segtree, assign and merge for new problem:
struct segtree{
	int sum;
	segtree(){
		sum = 0;
	}
};

segtree s[4*maxn];

void assign(int node, int val){
	s[node] = segtree();
	s[node].sum = val;
}

segtree merge(segtree a, segtree b){
	segtree ret;
	ret.sum = a.sum + b. sum;
	return ret;
}

void build(int l=0, int r=n, int node=1){
	if (r-l==1){
		// s[node] = a[l];
		assign(node, a[l]);
		return;
	}
	build(l, mid(l, r), 2*node);
	build(mid(l, r), r, 2*node+1);
	// s[node] = s[2*node] + s[2*node+1];
	s[node] = merge(s[2*node], s[2*node+1]);
}

void modify(int p, int x, int l=0, int r=n, int node=1){
	// s[node] += x - a[p];
	if (r-l==1){
		a[p] = x;
		assign(node, x);
		return;
	}
	if (p < mid(l, r)) modify(p, x, l, mid(l, r), 2*node);
	else modify(p, x, mid(l, r), r, 2*node+1);
	// s[node] = s[2*node] + s[2*node+1];
	s[node] = merge(s[2*node], s[2*node+1]);
}

// int query(int x, int y, int l=0, int r=n, int node=1){
segtree query(int x, int y, int l=0, int r=n, int node=1){
	if (y <= l || x >= r) return segtree();
	if (x <= l && y >= r) return s[node];
	// return query(x, y, l, mid(l, r), 2*node) + query(x, y, mid(l, r), r, 2*node+1);
	segtree a = query(x, y, l, mid(l, r), 2*node);
	segtree b = query(x, y, mid(l, r), r, 2*node+1);
	return merge(a, b);
}