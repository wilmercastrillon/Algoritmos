#include <bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
typedef long long int lli;

lli gcd(lli a, lli b){
    return a?gcd(b %a, a):b;
}

lli mulmod (lli a, lli b, lli c) { //retorna (a*b) % c
	lli x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

lli expmod (lli b, lli e, lli m){//O(log b)
	if(!e) return 1;
	lli q= expmod(b,e/2,m); q=mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

bool es_primo_prob (lli n, int a) {
	if (n == a) return true;
	lli s = 0,d = n-1;
	while (d % 2 == 0) s++,d/=2;

	lli x = expmod(a,d,n);
	if ((x == 1) || (x+1 == n)) return true;

	forn (i, s-1){
		x = mulmod(x, x, n);
		if (x == 1) return false;
		if (x+1 == n) return true;
	}
	return false;
}

bool rabin (lli n){ //devuelve true si n es primo
	if (n == 1)	return false;
	const int ar[] = {2,3,5,7,11,13,17,19,23};
	forn (j,9)
		if (!es_primo_prob(n,ar[j]))
			return false;
	return true;
}

lli rho(lli n){
    if( (n & 1) == 0 ) return 2;
    lli x = 2 , y = 2 , d = 1;
    lli c = rand() % n + 1;
    while( d == 1 ){
        x = (mulmod( x , x , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        if( x - y >= 0 ) d = gcd( x - y , n );
        else d = gcd( y - x , n );
    }
    return d==n? rho(n):d;
}

map<lli, lli> prim;

void factRho (lli n){ //O (lg n)^3. un solo numero
	if (n == 1) return;
	if (rabin(n)){
		prim[n]++;
		return;
	}
	lli factor = rho(n);
	factRho(factor);
	factRho(n/factor);
}

int main(){
    lli n;
    while(scanf("%lld", &n), n > 0){
        prim.clear();
        factRho(n);

        for(map<lli, lli>::iterator it = prim.begin(); it != prim.end(); it++){
            cout << "el " << (it)->first << " aparece " << (it)->second << " veces.\n";
        }
    }
    return 0;
}
