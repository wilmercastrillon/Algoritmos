#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

int solve(int a, int b, int m){
    int n = (int) sqrt(m + 0.0) + 1;
    int an = 1;
    for (int i = 0; i < n; ++i) an = (an * a) % m;

    map<int, int> vals;
    for (int p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur)) vals[cur] = p;
        cur = (cur * an) % m;
    }
    for (int q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

int main(){
    int a, b, m;
    while(scanf("%d %d %d", &a, &b, &m) != EOF){
        printf("%d\n", solve(a,b,m));
    }
}


