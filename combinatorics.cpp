#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll modu = 1e9+7;
const int maxn = 1e3+2;
ll nCr[maxn][maxn];

void calnCr(int n){
	for(int i=0; i<=n; ++i){
		nCr[i][0] = 1;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=i; ++j){
			nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%modu;
		}
	}
}

int main(){
	calnCr(maxn-1);	// don't do calnCr(maxn) -> gives segmentation fault;

	return 0;
}