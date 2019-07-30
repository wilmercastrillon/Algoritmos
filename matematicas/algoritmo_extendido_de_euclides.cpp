#include <iostream>

using namespace std;
typedef long long int lli;

lli gcd_ex (lli a, lli b, lli &x, lli &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	lli x1, y1;
	lli d = gcd_ex (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;//Maximo comun divisor
}

int main(){
    freopen("salida.txt", "w", stdout);
    lli n, m, x, y, res, aux;

    while(scanf("%lld %lld", &n, &m) != EOF){
        res = gcd_ex(n, m, x, y);
        if(y < x){
            aux = x;
            x = y;
            y = aux;
        }
        printf("%lld %lld %lld\n", x, y, res);
    }
}
