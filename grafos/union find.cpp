#include <iostream>

using namespace std;

struct union_find{
	int padre[100];
	int rango[100];
	
	void iniciar(int n){
		for (int i = 0; i < n; i++)
		{
			padre[i] = i;
			rango[i] = 0;
		}
	}
	
	int raiz(int x){
		if(padre[x] == x) return x;
		return raiz(padre[x]);
	}
	
	void unir(int x, int y){
		x = raiz(x);
		y = raiz(y);
		
		if(rango[x] > rango[y]){
			padre[y] = x;
			return;
		}
		
		padre[x] = y;
		if(rango[y] == rango[x]) rango[y]++;
	}
	
	bool MismoGrupo(int x, int y){
		return raiz(x) == raiz(y);
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
	
	if(uf.MismoGrupo(4, 1))
		cout << "si" << endl;
	else
		cout << "no" << endl;
	
	return 0;
}