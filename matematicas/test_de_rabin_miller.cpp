#include <bits/stdc++.h>

using namespace std;

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

bool es_primo_prob(lli n, int a) {
	if (n == a) return true;
	lli s = 0,d = n-1;
	while (d % 2 == 0) s++,d/=2;

	lli x = expmod(a,d,n);
	if ((x == 1) || (x+1 == n)) return true;

	for(int i = 0; i < s-1; i++){
		x = mulmod(x, x, n);
		if (x == 1) return false;
		if (x+1 == n) return true;
	}
	return false;
}

bool rabin (lli n){ //devuelve true si n es primo
	if (n == 1)	return false;
	const int ar[] = {2,3,5,7,11,13,17,19,23};
	for(int j = 0; j < 9; j++)
		if (!es_primo_prob(n,ar[j]))
			return false;
	return true;
}

int main(){
    lli n;
    while(scanf("%lld", &n), n > 0){
        if(rabin(n)){
            printf("es primo\n");
        }else{
            printf("no es primo\n");
        }
    }
return 0;
}
