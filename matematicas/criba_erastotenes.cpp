#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;

int MAX = 1000010, lim = sqrt(1000010)+1;
bool primo[1000020];
vector<int> p;//lista de primos

void criba(){
    memset(primo, true, sizeof(primo));
    primo[0] = primo[1] = false;

    for(int i = 2; i < MAX; i++){
        if(!primo[i]) continue;
        p.push_back(i);
        if(i > lim) continue;

        for(int j = i*i; j < MAX; j += i)
            primo[j] = false;
    }
}

int main(){
    criba();
    int n;

    while(scanf("%d", &n) != EOF){
        if(primo[n]) printf("Es primo\n");
        else printf("No es primo\n");
    }
    return 0;
}


