#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;//(peso, nodo padre, nodo hijo)
typedef vector<int> vi;
#define mpiii(a, b, c) iii(a, ii(b, c))
#define inf 1000000000

vector<iii> grafo; //lista de incidencia

bool BellmanFord(vector<iii> &lista, int nodos, int inicio, vector<int> &dis){
    dis.assign(nodos + 1, inf);
	dis[inicio] = 0;
	int aux;

	for (int i = 0; i < nodos; i++)
		for (int j = 0; j < lista.size(); j++) {
			aux = dis[lista[j].second.first] + lista[j].first;
			if (dis[lista[j].second.second] > aux){
				dis[lista[j].second.second] = aux;
			}
		}

    for(int j = 0; j < lista.size(); j++){
        aux = dis[lista[j].second.first] + lista[j].first;
        if(dis[lista[j].second.second] > aux)
            return false;//existe ciclo!!!
    }
	return true;
}

vector<vi> matriz(10);

int main(){
	grafo.push_back(mpiii(2, 0, 1));
	grafo.push_back(mpiii(2, 1, 0));
	grafo.push_back(mpiii(4, 1, 2));
	grafo.push_back(mpiii(12, 2, 3));
	grafo.push_back(mpiii(6, 2, 6));
	grafo.push_back(mpiii(12, 3, 2));
	grafo.push_back(mpiii(7, 3, 4));
	grafo.push_back(mpiii(1, 4, 9));
	grafo.push_back(mpiii(5, 5, 7));
	grafo.push_back(mpiii(8, 6, 1));
	grafo.push_back(mpiii(6, 6, 2));
	grafo.push_back(mpiii(11, 6, 5));
	grafo.push_back(mpiii(3, 7, 8));
	grafo.push_back(mpiii(10, 8, 3));
	grafo.push_back(mpiii(1, 9, 4));
	grafo.push_back(mpiii(9, 9, 7));

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
