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
#define MAX 100010

int p[100], d[100], peso[100];//padre, deep, peso
int spt[100][7];//spt[i][j] = (2^j)-th ancestro de i
vvi grafo;//spt[MAX][(int) log_2(MAX) + 1]

void dfs(int nodo, int deep, int ant){
    d[nodo] = deep;
    p[nodo] = ant;
    for(int i = 0; i < grafo[nodo].size(); i++){
        if(d[grafo[nodo][i]] != -1) continue;
        dfs(grafo[nodo][i], deep+1, nodo);
    }
}

void proceso(int n){//Llamar antes de LCA
    memset(d, -1, sizeof(d));
    dfs(0, 0, -1);
    memset(spt, -1, sizeof(spt));

    for(int i = 0; i < n; i++){
        spt[i][0] = p[i];
//mayor[i][0] = peso[i];
    }

    for(int j = 1; 1 << j < n; j++)
    for(int i = 0; i < n; i++)
        if(spt[i][j-1] != -1){
            spt[i][j] = spt[spt[i][j-1]][j-1];
//mayor[i][j] = max(mayor[i][j-1], mayor[spt[i][j-1]][j-1]);
        }
}

int LCA(int u, int v){
    if(d[u] < d[v]) swap(u, v);//v debe estar arriba de u

    for(int i = 16; i >= 0; i--)//subimos a u
        if(d[u] - (1<<i) >= d[v])
            u = spt[u][i];

    if(u == v) return u;

    for(int i = 16; i >= 0; i--)
        if(spt[u][i] != spt[v][i]){
            u = spt[u][i];
            v = spt[v][i];
        }

    return p[v];
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


