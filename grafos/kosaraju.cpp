#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

int n, m;
vector<vi> grafo(100), transpuesto(100), comp;
stack<int> pila;
bool vis[100];

void dfs(int n, vector<vi> lista, bool f, vi &grupo){
	vis[n] = true;
	if(!f) grupo.push_back(n);

	for (int i = 0; i < lista[n].size(); i++)
		if (!vis[lista[n][i]]) dfs(lista[n][i], lista, f, grupo);
    if(f) pila.push(n);
}

void kosaraju(){
	memset(vis, false, sizeof(vis));
	vi no_se_utiliza;
	for (int i = 0; i < n; i++)
		if(!vis[i]) dfs(i, grafo, true, no_se_utiliza);

	memset(vis, false, sizeof(vis));
	int n;
	while(pila.size()){
		n = pila.top();  pila.pop();
		if (!vis[n]){
			vi vec;
			dfs(n, transpuesto, false, vec);
			comp.push_back(vec);
		}
	}

	for (int i = 0; i < comp.size(); i++){
		for (int j = 0; j < comp[i].size(); j++) cout << comp[i][j] << " ";
		cout << endl;
	}
}

int main() {

    int x, y;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        grafo[x].push_back(y);
        transpuesto[y].push_back(x);
    }

	kosaraju();

	return 0;
}
