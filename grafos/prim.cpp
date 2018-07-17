#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;//peso - destino
typedef vector<ii> vii;
typedef vector<vii> vvii;

priority_queue<ii> cola;
vector<bool> vis;

void vecinos(vvii &lista, int nodo){
    vis[nodo] = true;
    for(int i = 0; i < lista[nodo].size(); i++){
        ii par = lista[nodo][i];//peso - destino
        if(!vis[par.second])
            cola.push(ii(-par.first, -par.second));
    }
}

int prim(vvii &lista, int n){
    vis.assign(n + 1, false);
    vecinos(lista, 1);
    int acum = 0; ii par;

    while(cola.size()){
        par = cola.top(); cola.pop();
        if(vis[-par.second]) continue;
        acum += -par.first;
        vecinos(lista, -par.second);
    }
    return acum;
}

int main(){
    int n, m, x, y, z;

    while(scanf("%d %d", &n, &m) != EOF){
        vvii lista(n+1);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);//no dirigido
            lista[x].push_back(ii(z, y));
            lista[y].push_back(ii(z, x));
        }

        printf("MTS = %d\n", prim(lista, n));
    }

    return 0;
}


