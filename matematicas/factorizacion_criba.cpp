#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;
typedef long long int lli;

int m= 1000010, m2= 1000000, primo[1000020];
vector<lli> p;
map<lli, int> mapa;

void criba(){
    memset(primo, 0, sizeof(primo));

    for(int i = 2; i < m; i++){
        if(primo[i]) continue;
        p.push_back(i);
        primo[i] = i;
        if(i > 1000) continue;

        for(int j = i*i; j < m; j += i)
            primo[j] = i;
    }
}


void factCriba(lli n){
    int l;
    bool s;

    while(n != 1){
        if(n > m2){//n mayor a logintud del array
            l = sqrt(n) + 1;
            s = false;
            for(int i = 0; p[i] <= l; i++){
                if(n % p[i] == 0){
                    mapa[p[i]]++;
                    s = true;
                    n /= p[i];
                    break;
                }
            }
            if(!s){
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


