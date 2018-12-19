#include <stdio.h>
#define max 2

using namespace std;

typedef long long int lli;

struct matrix{  lli mat[max][max];  };

matrix matmul(matrix a, matrix b){//multiplicar
    matrix ans;
    int i, j, k;

    for(i = 0; i < max; i++)
    for(j = 0; j < max; j++)
        for(ans.mat[i][j] = k = 0; k < max; k++)
            ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);

    return ans;
}

matrix matpow(matrix base, int p){//exp binaria
    matrix ans;
    int i, j;

    for(i = 0; i < max; i++)
        for(j = 0; j < max; j++)
            ans.mat[i][j] = (i == j);

    while(p){
        if(p&1) ans = matmul(ans, base);
        base = matmul(base, base);
        p >>= 1;
    }
    return ans;
}

int main(){
    lli n;

    while(scanf("%llu", &n) != EOF){
        matrix base;
        base.mat[0][0] = 1;
        base.mat[0][1] = 1;
        base.mat[1][0] = 1;
        base.mat[1][1] = 0;
        matrix w = matpow(base, n);

        printf("%llu\n", w.mat[0][1]);
    }

    return 0;
}

