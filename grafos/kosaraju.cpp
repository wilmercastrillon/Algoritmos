#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

vector<vi> grafo(5), transpuesto(5), comp;
stack<int> pila;
bool vis[5];

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

	for (int i = 0; i < 5; i++)
		if(!vis[i]) dfs(i, grafo, true, no_se_utiliza);

	memset(vis, false, sizeof(vis));
	int n;
	while(pila.size()){
		n = pila.top();
		pila.pop();
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
    for(int i = 0; i < 6; i++){
        scanf("%d %d", &x, &y);
        grafo[x-1].push_back(y-1);
        transpuesto[y-1].push_back(x-1);
    }

	kosaraju();

	return 0;
}
