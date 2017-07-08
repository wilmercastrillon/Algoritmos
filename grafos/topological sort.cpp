#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> grafo(110);
vi res;
bool vis[110];

void dfs(vector<vi> &lista, int nodo){
    vis[nodo] = 1;
    for(int i = 0; i < lista[nodo].size(); i++){
        if(!vis[lista[nodo][i]]){
            dfs(lista, lista[nodo][i]);
        }
    }
    res.push_back(nodo);
}

void topological_sort(vector<vi> &lis, int tam){
    for(int i = 1; i <= tam; i++){
        if(!vis[i]) dfs(lis, i);
    }
}

int main(){
    int n = 5;

    grafo[5].push_back(4);
    grafo[1].push_back(2);
    grafo[2].push_back(3);
    grafo[1].push_back(3);
    grafo[1].push_back(5);

    topological_sort(grafo, n);
    for(int i = res.size() - 1; i > 0; i--) printf("%d ", res[i]);
    printf("%d\n", res[0]);

}
