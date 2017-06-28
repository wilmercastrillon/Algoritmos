#include <iostream>
#include <vector>

using namespace std;
typedef pair<double, pair<int, int>> pdii;
typedef vector<int> vi;

#define mpii(a, b) pair<int, int>(a, b)
#define mpdii(a, b, c) pdii(a, mpii(b, c))//(peso, nodo padre, nodo hijo)
#define inf 1000

vector<pdii> grafo; //lista de incidencia
vector<vi> matriz(10);
int padre[10];

bool BellmanFord(vector<pdii> &lista, int nodos, int inicio, vector<int> &dis){
	
	for(int i = 0; i < nodos; i++){
		dis[i] = inf;
		padre[i] = i;
	}
	dis[inicio] = 0;
	int aux;
	
	for (int i = 0; i < nodos; i++)
		for (int j = 0; j < lista.size(); j++)
		{
			aux = dis[lista[j].second.first] + lista[j].first;
			if (dis[lista[j].second.second] > aux)
			{
				dis[lista[j].second.second] = aux;
				padre[lista[j].second.second] = lista[j].second.first;
			}
		}
		
		for(int j = 0; j < nodos; j++){
			aux = dis[lista[j].second.first] + lista[j].first;
			if(dis[lista[j].second.second] > aux) return false;
		}
	return true;
}

int main(){
	
	grafo.push_back(mpdii(2, 0, 1));
	grafo.push_back(mpdii(2, 1, 0));
	grafo.push_back(mpdii(4, 1, 2));
	grafo.push_back(mpdii(12, 2, 3));
	grafo.push_back(mpdii(6, 2, 6));
	grafo.push_back(mpdii(12, 3, 2));
	grafo.push_back(mpdii(7, 3, 4));
	grafo.push_back(mpdii(1, 4, 9));
	grafo.push_back(mpdii(5, 5, 7));
	grafo.push_back(mpdii(8, 6, 1));
	grafo.push_back(mpdii(6, 6, 2));
	grafo.push_back(mpdii(11, 6, 5));
	grafo.push_back(mpdii(3, 7, 8));
	grafo.push_back(mpdii(10, 8, 3));
	grafo.push_back(mpdii(1, 9, 4));
	grafo.push_back(mpdii(9, 9, 7));
	
	for(int j = 0; j < 10; j++){
		vector<int> vec(10);
		matriz[j] = vec;
	}
	
	for(int j = 0; j < 10; j++)
		if(BellmanFord(grafo, 10, j, matriz[j])){
			for(int i = 0; i < 10; i++) cout << matriz[j][i] << " ";
			cout << endl;
		}else{
			cout << "ciclo negativo!!!" << endl;
		}
	
	return 0;
}
