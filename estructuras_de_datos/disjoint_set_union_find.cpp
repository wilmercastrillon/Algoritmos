#include <iostream>
#include <vector>

using namespace std;

struct union_find{
	int padre[100], rango[100];
	vector<int> grupo[100];

	void iniciar(int n){
		for (int i = 0; i < n; i++) {
			padre[i] = i;  rango[i] = 0;
			grupo[i].clear();  grupo[i].push_back(i);
		}
	}

	int raiz(int x){
		if(padre[x] == x) return x;
		return raiz(padre[x]);
	}

	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		if(x == y) return;

		if(rango[x] > rango[y]){
			padre[y] = x;
			grupo[x].insert(grupo[x].begin(), grupo[y].begin(), grupo[y].end());
			grupo[y].clear();
			return;
		}

		padre[x] = y;
		grupo[y].insert(grupo[y].begin(), grupo[x].begin(), grupo[x].end());
        grupo[x].clear();
		if(rango[y] == rango[x]) rango[y]++;
	}

	bool MismoGrupo(int x, int y){return raiz(x) == raiz(y);}

	void grupo_n(int n){
	    cout << "#elementos en el grupo de " << n << endl;
	    n = raiz(n);
	    for(int i = 0; i < grupo[n].size(); i++) cout << grupo[n][i] << '\n';
	}
};

int main(){

	union_find uf;

	uf.iniciar(10);
	uf.unir(0, 1);
	uf.unir(2, 3);
	uf.unir(8, 9);

	uf.unir(3, 0);
	uf.unir(8, 7);

	uf.unir(4, 5);
	uf.unir(5, 6);
	uf.unir(0, 6);

	for(int i = 0; i < 10; i++) cout << i << " ";
	cout << endl;

	for(int i = 0; i < 10; i++)
	cout << uf.padre[i] << " ";
	cout << endl;

	uf.grupo_n(5);

	if(uf.MismoGrupo(4, 1))
		cout << "si" << endl;
	else
		cout << "no" << endl;

	return 0;
}
