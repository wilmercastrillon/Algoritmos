#include <stdio.h>
#include<algorithm>

using namespace std;
typedef unsigned long long int ulli;

ulli ar[200010];

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

void pre(){
    ar[0] = 0;
    ar[1] = 2;
    for(int i = 2; i < 200005; i++){
        ar[i] = ar[i - 1] + phi(i);
    }
    for(int i = 0; i < 100; i++){
        printf("pos = %d , ar = %d\n", i, ar[i]);
    }
}

int BS(ulli q){
    int menor = 0, mayor = 200000, med;

    while(mayor - menor > 1){
        med = (mayor + menor) >> 1;
        if(ar[med] >= q){
            mayor = med;
        }else{
            menor = med;
        }
    }
    return menor;
}

void res(int ini, ulli lim){
    ulli con = ar[ini - 1];
    for (int d = ini; d < 200010; d++)
        for (int n = 0; n <= d; n++){
            if (__gcd(n,d) == 1){
                con++;
                if(con >= lim){
                    printf("%d/%d\n", n, d);
                    return;
                }
            }
        }
}

void fuerza(int lim){
    int con = 0;
    for (int d = 1; d < 100; d++){
        for (int n = 0; n <= d; n++){
            if (__gcd(n,d) == 1){
                con++;
                //printf("caso numero %d %d/%d\n", con, n, d);

                if(con == lim){
                    printf("res = %d/%d\n", n, d);
                    return;
                }
            }
        }
    }
}

int main(){

    pre();

    ulli n;
    while(scanf("%llu", &n) != EOF){
        int pos = BS(n);
        //fuerza((int) n);
        printf("pos = %d , arr = %llu\n\n", pos, ar[pos]);
        res(pos, n);
    }

    return 0;
}
