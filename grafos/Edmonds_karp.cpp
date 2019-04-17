#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int start, target, MAX=110, mf, f, matriz[110][110];
vi p;  vvi grafo;

void augment(int v, int minEdge){
    if(v == start){ f = minEdge; return; }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, matriz[p[v]][v]));
        matriz[p[v]][v] -= f;  matriz[v][p[v]] += f;
} }

int EdmondsKarp(){
    mf = 0;
    while(true){
        f = 0;
        vector<bool> vis(MAX, false); vis[start] = true;
        queue<int> cola;  cola.push(start);
        p.assign(MAX, -1);
        while(cola.size()){
            int u = cola.front();  cola.pop();
            if(u == target) break;

            for(int j = 0; j < grafo[u].size(); j++){
                int v = grafo[u][j];
                if(matriz[u][v] > 0 && !vis[v]){
                    vis[v] = true;
                    cola.push(v);  p[v] = u;
        }}}
        augment(target, inf);
        if(f == 0) break;
        mf += f;
    }
    return mf;
}

void addEdgeUndirected(int x, int y, int z){
    grafo[x].push_back(y);  grafo[y].push_back(x);
    matriz[x][y] += z;  matriz[y][x] += z;
}
void addEdgeDirected(int x, int y, int z){
    grafo[x].push_back(y);  grafo[y].push_back(x);
    matriz[x][y] += z;  matriz[y][x] += 0;
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y, z;
    while(scanf("%d", &n), n){
        memset(matriz, 0, sizeof(matriz));
        grafo.assign(n+1, vi(0));

        MAX = n;
        scanf("%d %d %d", &start, &target, &m);

        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &x, &y, &z);
            addEdgeUndirected(x, y, z);
        }

        printf("Max Flow is %d\n", EdmondsKarp());
    }

    return 0;
}


