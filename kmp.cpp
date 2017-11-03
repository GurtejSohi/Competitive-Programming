#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+2;
int h[maxn];

int main(){
	string p, s;
	cin >> p >> s;
	int len_p = p.length();
	int len_s = s.length();

	// compute prefix fn. h:
	h[0] = 0;
	for(int i=1; i<len_p; ++i){
		int x = h[i-1];
		while(x && p[x] != p[i]){
			x = h[x-1];
		}
		if (p[x]==p[i]) h[i] = x+1;
		else h[i] = 0;
	}

	// matching starts:
	int i=0, j=0;
	int occurences = 0;
	while(j < len_s){
		// cerr << "j: " << j << endl;
		while(j-i < len_p && j<len_s && s[j] == p[j-i]){
			j++;
		}
		if (j-i == len_p) occurences++;
		if (j != i) i = j-h[j-i-1];
		else {
			i++;
			j++;
		}
	}

	cout << occurences << endl;	

	return 0;
}