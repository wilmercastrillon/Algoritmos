#include <bits/stdc++.h>
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef long long int lli;

lli gcd_ex(lli a, lli b, lli &x, lli &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	lli x1, y1;
	lli d = gcd_ex(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;//Maximo comun divisor
}

void solve(lli a, lli b, lli c){
    double q, w;
    lli x, y, d, xx, yy, men, may;
    d = gcd_ex(a,b,x,y);
    q = (double) x*(c/b);
    w = (double) y*(c/a);
    men = (lli) ceil(-1.0*q);
    may = (lli) floor(w);

    if(c%d || may < men){
        printf("Sin solucion\n");
        return;
    }
    for(lli i=men; i<=may; ++i){
        xx = x*(c/d)+((b/d)*i);
        yy = y*(c/d)-((a/d)*i);
        printf("solucion (%lld , %lld)\n",xx,yy);
    }
}

int main(){
    //freopen("salida.txt", "w", stdout);
    lli a,b,c;
    while(scanf("%lld %lld %lld", &a, &b, &c) != EOF){
        solve(a, b, c);
    }
}


