#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e6+2;
bool isPrime[maxn];
void sieve(int n){	// determine for every natural no. <= n whether it is prime or not;	Time complexity : O(nlogn)
	for (int i = 0; i <= n; ++i) isPrime[i] = 1;
	for (int i = 2; i*i <= n; ++i){
		if (isPrime[i]){
			for (int j = i*i; j <= n; j += i){
				isPrime[j] = 0;
			}
		}
	}
}

vector<ll> factorize(ll n){		// Time complexity : O(sqrt(n))
	vector<ll> res;
	// for(int i = 2; i*i <= n; ++i){	// BIG MISTAKE FIXED
	for(ll i = 2; i*i <= n; ++i){
		while(n%i == 0){
			res.push_back(i);
			n /= i;
		}
	}
	if (n != 1) res.push_back(n);
	return res;
}


ll gcd(ll a, ll b){		// Time complexity : O(log(max(a, b)))
	if (b==0) return a;
	if (a==0) return b;
	return gcd(b, a%b);
}

ll xgcd(ll a, ll b, ll& x, ll &y){	// find x & y s.t. a*x + b*y = gcd(a, b); Time complexity : O(log(max(a, b)))
	if (b==0){
		x = 1;
		y = 0;
		return a;
	}
	else if (a==0){
		x = 0;
		y = 1;
		return b;
	}
	ll x2, y2;
	ll ans = xgcd(b, a%b, x2, y2);
	x = y2;
	y = x2 - (a/b)*y2;
	return ans;
}

ll modExponentiation(ll a, int b, int m){		// calculate (a^b)%m; Time complexity : O(logb)
	if (b == 1) return a%m;
	ll half_ans = modExponentiation(a, b/2, m);
	ll ans = (half_ans*half_ans)%m;
	if (b & 1) ans = (ans*a)%m;
	return ans;
}

ll modularInverse(ll c, ll m){	// calculate x s.t. (c*x)%m = 1	; ASSUMPTION : gcd(c, m) = 1;
	ll x, y;
	xgcd(c, m, x, y);
	return ((x%m)+m)%m;
	// return x;	// this could be negative
}
