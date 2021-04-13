#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100;

struct union_find{
    int padre[MAX], rango[MAX];//Rango opcional

    void iniciar(int n){
        for (int i = 0; i < n; i++){
            padre[i] = i;  rango[i] = 0;
        }
    }

    int raiz(int x){
        if(x == padre[x]) return x;
        else return padre[x] = raiz(padre[x]);
    }

    void unir(int x, int y){
        x = raiz(x);  y = raiz(y);
        if(x == y) return;

        if(rango[x] > rango[y]){
            padre[y] = x;
            return;
        }
        padre[x] = y;
        if(rango[y] == rango[x]) rango[y]++;
    }

    bool MismoGrupo(int x, int y){return raiz(x) == raiz(y);}

    //Usar este para compresion de caminos
    int raiz_compresion(int x){
        if(x == padre[x]) return x;
        else return padre[x] = raiz(padre[x]);
    }
    //Usar este para compresion de caminos
    void unir_compresion(int x, int y){
        padre[raiz(x)] = raiz(y);
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

	//uf.grupo_n(5);

	if(uf.MismoGrupo(4, 1))
		cout << "si" << endl;
	else
		cout << "no" << endl;

	return 0;
}
