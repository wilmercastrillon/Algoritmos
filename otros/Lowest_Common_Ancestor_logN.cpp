#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <map>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX 1000010

#define Log2 20//2^Log2 > MAX
int padre[MAX], nivel[MAX], peso[MAX];//padre, deep, peso
int spt[MAX][Log2];//spt[i][j] = (2^j)-th ancestro de i
vvi grafo;

void dfs(int nodo, int deep, int ant){
    nivel[nodo] = deep;
    padre[nodo] = ant;
    for(int i = 0; i < grafo[nodo].size(); i++){
        if(nivel[grafo[nodo][i]] != -1) continue;
        dfs(grafo[nodo][i], deep+1, nodo);
    }
}

void proceso(int n){//Llamar antes de LCA
    memset(nivel, -1, sizeof(nivel));
    dfs(0, 0, -1);
    for(int i = 0; i < n; i++)
        spt[i][0] = padre[i];

    for(int i = 1; i < Log2; i++)
    for(int j = 0; j < n; j++)
        if(spt[j][i-1] != -1){
            spt[j][i] = spt[spt[j][i-1]][i-1];
        }
}

int LCA(int u, int v){
    if(nivel[u] > nivel[v]) swap(u, v);//v debe estar arriba de u

    for(int i = 0; i < Log2; i++)//subimos a u
        if((nivel[v] - nivel[u])>>i&1)
            v = spt[v][i];
    if(u == v) return u;

    for(int i = Log2-1; i >= 0; i--)
        if(spt[u][i] != spt[v][i]){
            u = spt[u][i];
            v = spt[v][i];
        }
    return spt[u][0];
}

int main(){
    int n, m, x, y, q, u, v, lca;

    while(scanf("%d %d", &n, &m) != EOF){
        grafo.assign(n+1, vi(0));

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            grafo[x].push_back(y);
        }

        proceso(n);
        scanf("%d", &q);
        while(q--){
            scanf("%d %d", &u, &v);
            lca = LCA(u, v);
            printf("%d\n", lca);
        }
    }

	return 0;
}


