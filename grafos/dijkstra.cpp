#include <iostream>
#include <vector>
#include <string.h>

#define inf 1000

using namespace std;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;

vector<vii> grafo(10);

vi dijkstra(vector<vii> lista, int nodo){
	
	bool vis[lista.size()];
	memset(vis, false, sizeof(vis));
	vi dis(lista.size(), inf);
	dis[nodo] = 0;
	int aux;
	
	for(int i = 0; i < lista.size(); i++){
		vis[nodo] = true;
		
		for(int j = 0; j < lista[nodo].size(); j++)
			dis[lista[nodo][j].first] = min(dis[lista[nodo][j].first], 
				dis[nodo] + lista[nodo][j].second);
		
		for(int j = 0; j < lista.size(); j++)
			if(vis[nodo] || (!vis[j] && dis[j] < dis[nodo])) nodo = j;
	}
	
	return dis;
}

int main(){
	grafo[0].push_back(pair<int, int>(1,2));
	grafo[1].push_back(pair<int, int>(0,2));
	grafo[1].push_back(pair<int, int>(2,4));
	grafo[2].push_back(pair<int, int>(3,12));
	grafo[2].push_back(pair<int, int>(6,6));
	grafo[3].push_back(pair<int, int>(2,12));
	grafo[3].push_back(pair<int, int>(4,7));
	grafo[4].push_back(pair<int, int>(9,1));
	grafo[5].push_back(pair<int, int>(7,5));
	grafo[6].push_back(pair<int, int>(1,8));
	grafo[6].push_back(pair<int, int>(2,6));
	grafo[6].push_back(pair<int, int>(5,11));
	grafo[7].push_back(pair<int, int>(8,3));
	grafo[8].push_back(pair<int, int>(3,10));
	grafo[9].push_back(pair<int, int>(4,1));
	grafo[9].push_back(pair<int, int>(7,9));
	
	vector<vi> matriz;
	for(int k = 0; k < 10; k++) matriz.push_back(dijkstra(grafo, k));
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++) cout << matriz[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
