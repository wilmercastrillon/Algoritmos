#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

double dist[20][20], dp[1 << 16], aux;
int n;

double matching(int mask){
    if(dp[mask] > -0.5) return dp[mask];
    if(mask == aux) return dp[mask] = 0;

    double ans = 1000000000;
    int p1, p2;

    for(p1 = 0; p1 < 2*n; p1++)
        if(!(mask & (1 << p1))) break;
    for(p2 = p1 + 1; p2 < 2*n; p2++)
        if(!(mask & (1 << p2))){
            ans = min(ans, dist[p1][p2] + matching(mask | (1 << p1) | (1 << p2)));
        }

    return dp[mask] = ans;
}

int main(){
    int posx[20], posy[20], caso = 1;

    while(scanf("%d", &n), n){
        for(int i = 0; i < n*2; i++) scanf("%*s %d %d", &posx[i], &posy[i]);

        for(int i = 0; i < n*2; i++)
            for(int j = i + 1; j < n*2; j++)
                dist[i][j] = dist[j][i] = hypot(posx[i] - posx[j], posy[i] - posy[j]);

        for(int i = 0; i < (1<<16); i++) dp[i] = -1;
        aux = (1 << (n << 1)) - 1;
        printf("Case %d: %.2lf\n", caso++, matching(0));
    }
    return 0;
}
