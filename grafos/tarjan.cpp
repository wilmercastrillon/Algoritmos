#include <stdio.h>
#include <vector>

using namespace std;
typedef vector<int> vi;

int n, m;
vector<vi> lista;
vi dfs_low, dfs_num, s; vector<bool> vis;
int dfsCont;

void dfs(int u){
    dfs_low[u] = dfs_num[u] = dfsCont++;
    s.push_back(u);  vis[u] = true;

    for(int i = 0; i < lista[u].size(); i++){
        int aux = lista[u][i];
        if(dfs_num[aux] == -1) dfs(aux);
        if(vis[aux])
            dfs_low[u] = min(dfs_low[u], dfs_low[aux]);
    }

    if(dfs_low[u] == dfs_num[u]){
        printf("comp:\n");
        while(true){
            int v = s.back(); s.pop_back();
            printf(" %d\n", v);  vis[v] = false;
            if(v == u) break;
        }
        printf("\n");
    }
}

void tarjan(){
    dfs_num.assign(n+1,-1); dfs_low.assign(n+1,0);
    vis.assign(n+1, false);  dfsCont = 0;
    for(int i = 0; i < n; i++)
        if(dfs_num[i] == -1) dfs(i);
}

int main(){
    int x, y;

    while(scanf("%d %d", &n , &m) != EOF){
        lista.assign(n+1, vi(0));
        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            lista[x].push_back(y);
        }
        solve();
    }

    return 0;
}


