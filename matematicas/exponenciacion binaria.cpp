#include <stdio.h>

using namespace std;
typedef unsigned long long int ulli;

ulli exp_bin (ulli a, ulli n) {
	ulli res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main(){
    ulli n, m;

    while(scanf("%llu %llu", &n, &m) != EOF){
        printf("%llu\n", exp_bin(n, m));
    }

    return 0;
}
