for(int i=0; i<=n; ++i){    // trick : i can also be equal to n:...
    if (i==n || A[i] < 0){ // reset
        if (ca > maxSum || (ca == maxSum && len > maxLen)){
            maxSum = ca;
            maxLen = len;
            maxSi = si;
        }
        ca = 0;
        si = i+1;
        len=0;
    }


// not using double in case you have to handle a/b where a and b are both integers; Instead use pairs and gcd to store a/b;
// https://www.interviewbit.com/problems/points-on-the-straight-line/
if (xdiff < 0) {
    xdiff *= -1; 
    ydiff *= -1;
}
int g = gcd(xdiff, ydiff);  // but here gcd also has to handle negative cases.
M[make_pair(xdiff / g, ydiff / g)]++;
int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < 0) return gcd(-1 * a, b);
    if (b < 0) return gcd(a, -1 * b);
    if (a > b) return gcd(b, a);
    return gcd(b%a, a);
}