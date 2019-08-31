#include <stdio.h>

using namespace std;
typedef long long int lli;

lli exp_bin(lli a, lli n) {
	lli res = 1;
	while (n) {
		if (n & 1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main(){
    lli n, m;

    while(scanf("%lld %lld", &n, &m) != EOF){
        printf("%lld\n", exp_bin(n, m));
    }

    return 0;
}
