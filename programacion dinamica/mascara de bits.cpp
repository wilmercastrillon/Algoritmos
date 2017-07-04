#include <iostream>
#include <string.h>
#define forn(a, b) for(int a = 0; a < n; a++)

using namespace std;

double dp[1 << 18], p[18][18];
int n;

double f(int mask){
    //cout << "mask = " << mask << endl;
    //cout << "dp = " << dp[mask] << endl;
    if(dp[mask] > -0.5) return dp[mask];
    int vivos = 0;

    forn(i, n) if((mask >> i) % 2 == 1) vivos++;
    double pares = (vivos*(vivos -1))/2;
    if(vivos == 1){
        if(mask == 1) dp[mask] = 1.;
        else dp[mask] = 0.;
        return dp[mask];
    }

    dp[mask] = 0.;
    forn(i, n) forn(j, i)
        if((mask >> i)%2 == 1 && (mask >> j) %2 == 1){
                if(i != 0 && j != 0)
                    dp[mask] += (f(mask^(1<<i))*p[j][i]+f(mask^(1<<j))*p[i][j])/pares;
                else if(i == 0) dp[mask] += f(mask^(1<<j))*p[i][j]/pares;
                else if(j == 0) dp[mask] += f(mask^(1<<i))*p[j][i]/pares;
        }
    return dp[mask];
}

int main(){
    memset(dp, -1, sizeof(dp));

    cin >> n;
    forn(i, n) forn(j, n) cin >> p[i][j];

    printf("%.6lf\n", f((1 << n) - 1));
    return 0;
}
