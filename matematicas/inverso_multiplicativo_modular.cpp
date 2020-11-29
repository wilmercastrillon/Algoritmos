#include <iostream>

using namespace std;
typedef long long int lli;

int gcd_ex (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd_ex (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

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

int inverso1(int a, int m){
    int x, y;
    int g = gcd_ex (a, m, x, y);
    if (g != 1) return -1;
    else  return (x % m + m) % m;
}

int inverso2(int a, int m) {
    return expmod(a, m - 2, m);
}

int main(){
    int a = 117, m = 241;//encuentra un x tal que
    int x, y;            //(a * x) es congruente a 1 con modulo p
                         //-> (a * x) % p = 1 % p
    cout << inverso1(a, m) << endl;
    cout << inverso2(a, m) << endl;

    return 0;
}
