// codechef sept cookoff 17:
// while(x & 1 == 0){	//	WRONG : precedence of bitwise operators(&,|,^) and logical operators(&&,||) is less than that of relational operators(==, !=, >, >=, < , <=)
// recall that you use :(x==a && y==b): making use : precedence of && is less than that of ==.
while((x & 1) == 0){
	// x >> 1;	// This will go into an infinite loop
	x = (x >> 1);
}	


// codechef codenesia 3oct 2017
// b :
memset(vis, 0, sizeof(vis[0]*n));	// WRONG
memset(vis, 0, sizeof(vis[0])*n);

// c : 
const int maxn = 1e6+2;
void sieve(){
	for(int i=2; i<maxn; ++i) isPrime[i] = 1;		// donot forget to initialise isPrime[i] with 1;
	for(int i=2; i<maxn; ++i){
		if (isPrime[i]){
			// for(int j=i*i; j< maxn; j += i){		// WRONG ----------- : NOTE THAT i*i CAN CROSS THE INT LIMIT IF maxn is high(IT DID AT i=46349)
			for(ll j=ll(i)*i; j< maxn; j += i){		// so use long long
				// cerr << "j:" << j << "; ";
				isPrime[j] = 0;
			}
			// cerr << endl;
		}
	}
}


// codechef oct long (challenge prob. : cppgen):
// set< int, pii > edges;
set< pair<int, pii> > edges;


// In code chef contests:
// donot forget to print newline after every testcase and also clear/memset all global arrays/vectors/sets .


// IB : Backtracking : Sudoku
for(i=r; i<n; ++i){
    for(j=c; j<n; ++j){		//	Note here looping var j will always start from j & this is not what we need
        if (A[i][j] == '.') break;
    }
    if (j!=n) break;
}


// IB
const int eps=1e-5;	// double


// IB : dp : Tushar's Birthday Bombs
if ((A-B[i])/x >= kicks){	// WRONG bcoz (-2)/4 == 0;
if ((A-B[i]) >= kicks*x){	// this was required : if kicks==0 then prev statement would be true even if the diff(A-B[i]) is <0.