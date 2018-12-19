#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli mulmod(lli a, lli b, lli c){//(a*b) % c
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
	lli q = expmod(b,e/2,m); q = mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

int main(){

    lli a, b, c;
    while(scanf("%lld %lld %lld", &a, &b, &c) != EOF){
        cout << expmod(a, b, c) << endl;
    }

    return 0;
}
