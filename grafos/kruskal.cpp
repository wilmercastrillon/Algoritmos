#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct union_find{
    int padre[100];
	int tam = 0;

	void iniciar(int n){
		for(int i = 0; i < n; i++) {
			padre[i] = i;
		}
		tam = n;
	}

	int raiz(int x){
		if(padre[x] == x) return x;
		return raiz(padre[x]);
	}

	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		padre[x] = y;
	}

	bool MismoGrupo(int x, int y){
		return raiz(x) == raiz(y);
	}
};

typedef pair<int, int> ii;
#define mpiii(a, b, c) iii(a, ii(b, c))
//insertar: grafo.push_back(mpiii(7, 0, 1))

typedef pair<int, ii> iii;//peso, origen y destino
vector<iii> listaInc;//lista de incidencia
union_find arbol;

int kruskal(vector<iii> lista, int nodos, union_find &uf){
	sort(lista.begin(), lista.end());
	uf.iniciar(nodos);
	int acum = 0, ejes = 0, n = nodos - 1;

	for (int i = 0; i < lista.size(); i++) {
		if (!uf.MismoGrupo(lista[i].second.first,
                      lista[i].second.second)) {
			ejes++;
			uf.unir(lista[i].second.first, lista[i].second.second);
			acum += lista[i].first;
			if(ejes == n) return acum;
		}
	}
	return -1;
}

int main(){

	listaInc.push_back(mpiii(7, 0, 1));
	listaInc.push_back(mpiii(5, 0, 3));
	listaInc.push_back(mpiii(8, 1, 2));
	listaInc.push_back(mpiii(7, 1, 4));
	listaInc.push_back(mpiii(9, 1, 3));
	listaInc.push_back(mpiii(5, 2, 4));
	listaInc.push_back(mpiii(15, 3, 4));
	listaInc.push_back(mpiii(6, 3, 5));
	listaInc.push_back(mpiii(8, 4, 5));
	listaInc.push_back(mpiii(9, 4, 6));
	listaInc.push_back(mpiii(11, 5, 6));

	cout << "peso " << kruskal(listaInc, 7, arbol) << endl;

	for(int i = 0; i < 7; i++) cout << i << " ";
	cout << endl;
	for(int i = 0; i < 7; i++) cout << arbol.padre[i] << " ";
	cout << endl;

	return 0;
}
