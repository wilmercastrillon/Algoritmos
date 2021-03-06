#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;
typedef long long int lli;

int m = 1000010, primo[1000020];
vector<lli> p;  int lim = sqrt(m)+1;
map<lli, int> mapa;

void criba(){
    memset(primo, 0, sizeof(primo));

    for(int i = 2; i < m; i++){
        if(primo[i]) continue;
        p.push_back(i);
        primo[i] = i;
        if(i > lim) continue;

        for(int j = i*i; j < m; j += i)
            primo[j] = i;
    }
}

void factCriba(int n){
    int l, pos;
    while(n != 1){
        if(n >= m){//n mayor a logintud del array
            l = sqrt(n) + 1;  pos = -1;
            while(p[++pos] <= l)
                if(n % p[pos] == 0){
                    mapa[p[pos]]++;
                    n /= p[pos];
                    break;
                }
            if(p[pos] > l){
                mapa[n]++;
                break;
            }
        }else{
            mapa[primo[n]]++;
            n /= primo[n];
        }
    }
}

int main(){
    criba();
    lli n;

    while(scanf("%lld", &n) != EOF){
        mapa.clear();
        factCriba(n);
        map<lli, int>::iterator it;

        for(it = mapa.begin(); it != mapa.end(); it++)
            printf("el %lld aparece %d veces\n", it->first, it->second);
    }
    return 0;
}


