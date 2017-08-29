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
	while(pila.size())
	{
		n = pila.top();
		pila.pop();
		if (!vis[n])
		{
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

	grafo[0].push_back(1);
	grafo[1].push_back(2);
	grafo[2].push_back(4);
	grafo[1].push_back(3);
	grafo[3].push_back(0);

	transpuesto[1].push_back(0);
	transpuesto[2].push_back(1);
	transpuesto[4].push_back(2);
	transpuesto[3].push_back(1);
	transpuesto[0].push_back(3);

	kosaraju();

	return 0;
}
