#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int MAX;//luego de leer n hacer: MAX = (1<<n)-1;
int matriz[15][15], memo[15][(1<<15)+1], n;

int tsp(int pos, int mask){
    if(mask == MAX) return matriz[pos][0];
    if(memo[pos][mask] != -1)
        return memo[pos][mask];

    int res = 1000000000;
    for(int i = 0; i < n; i++)
        if(!(mask & (1<<i))){
            res = min(res, matriz[pos][i]
                    + tsp(i, mask | (1<<i)));
        }
    return memo[pos][mask] = res;
}

int main(){
    scanf("%d", &n);
    MAX = (1<<n)-1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    memset(memo, -1, sizeof(memo));
    printf("%d\n", tsp(0, 1));
    return 0;
}


