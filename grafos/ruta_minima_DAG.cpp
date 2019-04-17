#include <iostream>
#include <algorithm>
#include <vector>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

bool vis[110];  vi ts;

void dfs(vvii &lista, int nodo){
    vis[nodo] = 1;  ii par;
    for(int i = 0; i < lista[nodo].size(); i++){
        par = lista[nodo][i];
        if(!vis[par.second]) dfs(lista, par.second);
    }
    ts.push_back(nodo);
}

void topological_sort(vvii &lis, int tam){
    for(int i = 0; i < tam; i++)
        if(!vis[i]) dfs(lis, i);
    reverse(ts.begin(), ts.end());
}

vi sp_DAG(vvii &lista, int n){
    topological_sort(lista, n);
    vi dist(n, inf);
    ii par;  int aux;
    dist[ts[0]] = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < lista[ts[i]].size(); j++){
            par = lista[ts[i]][j];
            aux = dist[ts[i]] + par.first;
            if(dist[par.second] > aux){
                dist[par.second] = aux;
            }
        }
    return dist;
}

int main(){
    int n, m, x, y, z;
    cin >> n >> m;
    vvii grafo(n + 1);

    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        grafo[x].push_back(ii(z, y));
    }

    vi dist = sp_DAG(grafo, n);
    for(int i = 0; i < dist.size(); i++){
        printf("[%d] = %d\n", i, dist[i]);
    }

    return 0;
}


