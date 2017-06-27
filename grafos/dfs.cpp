#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
typedef vector<int> vi;

vector<vi> grafo (7);

bool IsTree(vector<vi> &lista, vector<bool> &vis, int padre, int nodo){
	
	vis[nodo] = true;
	
	for (int i = 0; i < lista[nodo].size(); i++)
	{
		if (vis[lista[nodo][i]] && padre != lista[nodo][i]) return false;
		if(vis[lista[nodo][i]]) continue;
		if(!IsTree(lista, vis, nodo, lista[nodo][i])) return false;
	}
	
	return true;
}

bool conexo(vector<bool> &vis){//verifica si el metodo IsTree recorrio todo el grafo
	for (int i = 0; i < vis.size(); i++)
		if(!vis[i]) return false;
		
	return true;
}

int main(){
	grafo[0].push_back(1);
	grafo[0].push_back(3);
	grafo[1].push_back(0);
	grafo[1].push_back(2);
	grafo[2].push_back(1);
	grafo[3].push_back(0);
	//grafo[3].push_back(4);	//hace que no sea arbol
	grafo[3].push_back(5);
	//grafo[4].push_back(3);	//tambien lo hace un no arbol
	grafo[4].push_back(5);
	grafo[5].push_back(3);
	grafo[5].push_back(4);
	grafo[5].push_back(6);
	grafo[6].push_back(5);
	
	vector<bool> vec(grafo.size(), false);
	
	if (IsTree(grafo, vec, 0, 0) && conexo(vec))
	{
		cout << "es arbol" << endl;
	}else
	{
		cout << "no es arbol" << endl;
	}
	
	return 0;
}
