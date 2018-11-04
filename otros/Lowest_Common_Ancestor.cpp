#include <stdio.h>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

struct sparseTable{
    int arr[100], spt[100][10] = {0};

    sparseTable(){}

    sparseTable(int n, int a[]){
        for(int i = 0; i < n; i++){
            arr[i] = a[i];
            spt[i][0] = i;
        }

        for(int j = 1; (1<<j) <= n; j++){
            for(int i=0; i+(1<<j)-1 < n; i++)
                if(arr[spt[i][j-1]] < arr[spt[i+(1<<(j-1))][j-1]])
                    spt[i][j] = spt[i][j-1];
                else
                    spt[i][j] = spt[i+(1<<(j-1))][j-1];
        }
    }

    int query(int i, int j){//de i hasta j, index desde 0
        int k = (int) floor(log(((j-i+1)*1.0))/log(2.0));
        if(arr[spt[i][k]] <= arr[spt[j-(1<<k)+1][k]])
            return spt[i][k];
        else return spt[j-(1<<k)+1][k];
    }
};

typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX 100
int l[2*MAX], e[2*MAX], h[MAX], idx;
sparseTable table;

void dfs(int nodo, int deep, vvi &grafo){
    h[nodo] = idx;
    e[idx] = nodo;
    l[idx++] = deep;

    for(int i = 0; i < grafo[nodo].size(); i++){
        if(h[grafo[nodo][i]] != -1) continue;
        dfs(grafo[nodo][i], deep+1, grafo);
        e[idx] = nodo;
        l[idx++] = deep;
    }
}

void BuildRMQ(vvi &grafo){//llamar antes de LCA
    idx = 0;
    memset(h, -1, sizeof(h));
    dfs(0, 0, grafo);
    table = sparseTable(grafo.size()*2, l);
}

int LCA(int u, int v){//h[u] < h[v]
    return e[table.query(h[u], h[v])];
}

int main(){
    int n, m, x, y, z;

    while(scanf("%d %d", &n, &m) != EOF){
        vvi grafo(n);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }

        //Query
        BuildRMQ(grafo);
        scanf("%d", &z);
        for(int i = 0; i < z; i++){
            scanf("%d %d", &x, &y);
            printf("LCA = %d\n", LCA(x, y));
        }
    }

    return 0;
}


