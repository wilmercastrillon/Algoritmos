#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;//peso, destino
#define MAX 100010
#define log2 16

int p[MAX], d[MAX], spt[MAX][log2];
int mayor[MAX][log2], peso[MAX];
vvii grafo;

void dfs(int nodo, int deep, int ant){
    d[nodo] = deep;
    p[nodo] = ant;
    ii par;

    for(int i = 0; i < grafo[nodo].size(); i++){
        par = grafo[nodo][i];
        if(d[par.second] != -1) continue;
        peso[par.second] = par.first;
        dfs(par.second, deep+1, nodo);
    }
}

void proceso(int n){//spt[i][j] = (2^j)-th ancestro de i
    memset(d, -1, sizeof(d));
    memset(mayor, 0, sizeof(mayor));
    memset(peso, 0, sizeof(peso));
    dfs(0, 0, -1);
    memset(spt, -1, sizeof(spt));
    for(int i = 0; i < n; i++){
        spt[i][0] = p[i];
        mayor[i][0] = peso[i];
    }

    for(int j = 1; 1 << j < n; j++)
    for(int i = 0; i < n; i++)
        if(spt[i][j-1] != -1){
            spt[i][j] = spt[spt[i][j-1]][j-1];
            //opcional, para obtener suma o mayor arista
            mayor[i][j] = max(mayor[i][j-1], mayor[spt[i][j-1]][j-1]);
            //mayor[i][j] = mayor[i][j-1] + mayor[spt[i][j-1]][j-1];
        }
}

//Opcional, para recorrer los nodos entre u y V
int maxEdge(int u, int v){
    if(d[u] < d[v]) swap(u, v);
    int may = 0, suma = 0;
    for(int i = 16; i >= 0; i--)
        if(d[u] - (1<<i) >= d[v]){
            may = max(may, mayor[u][i]);
			//suma += mayor[u][i];//en caso de requerir suma
            u = spt[u][i];
        }
    return may;
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
    int n, m, x, q, u, v, lca, z;

    while(scanf("%d", &n), n){
        grafo.assign(n+1, vii(0));

        for(int i = 1; i < n; i++){
            scanf("%d %d", &x, &z);
            grafo[x].push_back(ii(z, i));
            grafo[i].push_back(ii(z, x));
        }

        proceso(n);
        scanf("%d", &q);
        int res;

        scanf("%d %d", &u, &v);
        lca = LCA(u, v);
        res = sumEdge(lca, u) + sumEdge(lca, v);
        printf("%lld", res);
        q--;

        while(q--){
            scanf("%d %d", &u, &v);
            lca = LCA(u, v);
            res = sumEdge(lca, u) + sumEdge(lca, v);
            //printf("%d, | lca %d\n", res, lca);
            printf(" %lld", res);
        }
        printf("\n");
    }

	return 0;
}


