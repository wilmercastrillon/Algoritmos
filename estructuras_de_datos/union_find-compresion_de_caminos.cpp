#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

const int MAX = 100;

struct union_find{
    int padre[MAX];

    void iniciar(int n){
        for (int i = 0; i < n; i++) padre[i] = i;
    }

    int raiz(int x){
        if(x == padre[x]) return x;
        else return padre[x] = raiz(padre[x]);
    }

	void unir(int x, int y){padre[raiz(x)] = raiz(y);}
};

int main(){
    int n, m, x, y;
    scanf("%d %d", &n, &m);

	union_find uf;
    uf.iniciar(n+1);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        uf.unir(x, y);
    }

	for(int i = 0; i < n; i++) cout << i << " ";
	cout << endl;

	for(int i = 0; i < n; i++)
	cout << uf.padre[i] << " ";
	cout << endl;

	return 0;
}
