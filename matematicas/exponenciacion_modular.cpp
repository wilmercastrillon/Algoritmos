#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll mulmod(ll a, ll b, ll c){//(a*b) % c
    ll x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

ll expmod (ll b, ll e, ll m){//O(log b)
	if(!e) return 1;
	ll q = expmod(b,e/2,m); q = mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

int main(){

    ll a, b, c;
    while(scanf("%lld %lld %lld", &a, &b, &c) != EOF){
        cout << expmod(a, b, c) << endl;
    }

    return 0;
}
