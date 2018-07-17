#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> lista;
vi puntos, dfs_num, dfs_low, padre;
int n, m, dfsCont, root, dfsRoot;
vector<ii> puentes;//guardaa los puentes

void dfs(int u){
    dfs_low[u] = dfs_num[u] = dfsCont++;
    int aux;
    for(int i = 0; i < lista[u].size(); i++){
        aux = lista[u][i];
        if(dfs_num[aux] == -1){
            padre[aux] = u;
            if(u == dfsRoot) root++;
            dfs(aux);

            if(dfs_low[aux]>=dfs_num[u]) puntos[u]++;
            if(dfs_low[aux] > dfs_num[u])
                puentes.push_back(ii(aux, u));
            dfs_low[u] = min(dfs_low[u], dfs_low[aux]);
        }else if(aux != padre[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[aux]);
    }
}

void solve(){
    puntos.assign(n, 1); dfs_low.assign(n, 0);
    padre.assign(n, 0); dfs_num.assign(n, -1);

    for(int i = 0; i < n; i++)
        if(dfs_num[i] == -1){
            dfsCont = root = 0; dfsRoot = i;
            dfs(dfsRoot);
            puntos[i] = root - 1;
        }

    printf("puntos de articulacion:\n");
    for(int i = 0; i < n; i++)
        if(puntos[i] > 1)//cantidad de componentes
            printf("%d, conecta %d comp.\n",i,puntos[i]);
}

int main(){
    int x, y;

    while(scanf("%d %d", &n, &m) != EOF && n && m){
        lista.assign(100, vi(0));

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            lista[x].push_back(y);
            lista[y].push_back(x);
        }

        solve();
    }

    return 0;
}


