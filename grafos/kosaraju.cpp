#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

vector<vi> grafo(5), transpuesto(5), comp;
stack<int> pila;
bool vis[5];

void dfs(int n){
	vis[n] = true;
	
	for (int i = 0; i < grafo[n].size(); i++)
		if (!vis[grafo[n][i]]) dfs(grafo[n][i]);
	
	pila.push(n);
}

void dfs_2(int n, vi &grupo){
	vis[n] = true;
	grupo.push_back(n);
	
	for (int i = 0; i < transpuesto[n].size(); i++)
		if (!vis[transpuesto[n][i]]) dfs_2(transpuesto[n][i], grupo);
}

void kosaraju(){
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < 5; i++)
		if(!vis[i]) dfs(i);
	
	memset(vis, false, sizeof(vis));
	int n;
	while(pila.size())
	{
		n = pila.top();
		pila.pop();
		if (!vis[n])
		{
			vi vec;
			dfs_2(n, vec);
			comp.push_back(vec);
		}
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
	
	for (int i = 0; i < comp.size(); i++){
		for (int j = 0; j < comp[i].size(); j++) cout << comp[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
