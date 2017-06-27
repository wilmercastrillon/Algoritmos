#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;

vector<vi> grafo (11);
vector<vi> matriz;

vi bfs(vector<vi> lista, int n){
	vi dis (lista.size(), lista.size());
	queue <int> cola;
	cola.push(n);
	int nodo, aux;
	dis[n] = 0;
	
	while(cola.size()){
		nodo = cola.front();
		cola.pop();
		aux = dis[nodo] + 1;
		for(int i = 0; i < lista[nodo].size(); i++){
			if (dis[lista[nodo][i]] > aux) {
				dis[lista[nodo][i]] = aux;
				cola.push(lista[nodo][i]);
			}
		}
	}
	
	return dis;
}

int main(){
	grafo[0].push_back(1);
	grafo[1].push_back(0);
	grafo[1].push_back(2);
	grafo[2].push_back(3);
	grafo[2].push_back(6);
	grafo[3].push_back(2);
	grafo[3].push_back(4);
	grafo[4].push_back(9);
	grafo[5].push_back(7);
	grafo[6].push_back(1);
	grafo[6].push_back(2);
	grafo[6].push_back(5);
	grafo[7].push_back(8);
	grafo[8].push_back(3);
	grafo[9].push_back(4);
	grafo[9].push_back(7);
	
	for(int i = 0; i < 10; i++) matriz.push_back(bfs(grafo, i));
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++) cout << matriz[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
