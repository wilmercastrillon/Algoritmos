#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

int n, m;
vector<vi> grafo(100), grafoT(100);
vector<int> ts;  bool vis[100];

void dfs(int u, int pass){
    vis[u] = true;  vi vecino;
    if(pass == 1) vecino = grafo[u];
    else vecino = grafoT[u];

    for(int i = 0; i < vecino.size(); i++)
        if(!vis[vecino[i]]) dfs(vecino[i], pass);
    ts.push_back(u);
}

int kosaraju(){
    ts.clear();
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
        if(!vis[i]) dfs(i, 1);

    int num_comp = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = ts.size()-1; i >= 0; i--)
        if(!vis[ts[i]]){
            num_comp++;  dfs(ts[i], 2);
        }
    return num_comp;
}

int main() {

    int x, y;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        grafo[x].push_back(y);
        grafoT[y].push_back(x);
    }

	printf("Existen %d SCC\n", kosaraju());

	return 0;
}
