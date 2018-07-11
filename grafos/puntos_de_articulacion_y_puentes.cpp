#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

vector<vi> x;
int n, m, dfsCont;
int dfs_num[100], dfs_low[100], padre[100];
//dfsCont, dfs_low y padre inician en cero
//dfs_num inicia en -1
void dfs(int u){//dfs modificado
    dfs_low[u] = dfs_num[u] = dfsCont++;
    int aux;
    for(int i = 0; i < lista[u].size(); i++){
        aux = lista[u][i];
        if(dfs_num[aux] == -1){
            padre[aux] = u;
            if(u == 1) //nodo raiz del dfs
                printf("raiz %d -punto de art.\n", u);

            dfs(aux);

            if(dfs_low[aux] >= dfs_num[u])
                printf("%d -punto de art.\n", u);
            if(dfs_low[aux] > dfs_num[u])
                printf("puente: (%d - %d)\n", u, aux);
            dfs_low[u] = min(dfs_low[u], dfs_low[aux]);
        }else if(aux != padre[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[aux]);
    }
}


int main(){
    int x, y;

    while(scanf("%d %d", &n, &m) != EOF && n && m){
        dfsCont = 0;
        memset(dfs_low, 0, sizeof(dfs_low));
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(padre, 0, sizeof(padre));
        lista.assign(100, vi(0));

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            lista[x].push_back(y);
            lista[y].push_back(x);
        }
        printf("Busqueda de puntos de articulacion y puentes:\n");
        dfs(1);
        printf("---------------------------------------------\n\n");
    }

    return 0;
}


