#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef vector<int> vi;

const int MAX = 4 * 1000;//poner 4 * longitud maxima

struct segment_tree{
    int st[MAX];
    vi A;
    int n, tamst;

    int mov_izq(int index){ return index << 1; }
    int mov_der(int index){ return (index << 1) + 1; }

    void iniciar(vi arr){//metodo a invocar
        A = arr;
        n = A.size();
        tamst = n << 2;
        construir(1, 0, n - 1);
    }

    int RMQ(int i, int j){//metodo a invocar
        return query(1, 0, n-1, i, j);
    }

    int lazy[MAX];

    void construir(int pos, int izq, int der){
        lazy[pos] = -1;//reiniciar lazy
        if(izq == der){
            st[pos] = A[der];
            return;
        }

        construir(mov_izq(pos), izq, (izq + der) >> 1);
        construir(mov_der(pos), ((izq + der) >> 1) + 1, der);
        int aux1 = mov_izq(pos), aux2 = mov_der(pos);
        st[pos] = min(st[aux1], st[aux2]);
    }

    int query(int pos, int izq, int der, int i, int j){
        if(i > der || j < izq) return -1;
        solve_lazy(pos, izq, der);//resolver algun lazy pendiente
        if(i <= izq && j >= der) return st[pos];

        int aux1 = query(mov_izq(pos), izq, (izq + der) >> 1, i, j);
        int aux2 = query(mov_der(pos), ((izq + der) >> 1) + 1, der, i, j);
        if(aux1 == -1) return aux2;
        if(aux2 == -1) return aux1;

        return min(aux1, aux2);
    }

    void solve_lazy(int pos, int izq, int der){//resolver lazy
        if(lazy[pos] == -1) return;

        st[pos] = lazy[pos];
        if(izq != der){
            lazy[mov_izq(pos)]=lazy[mov_der(pos)]=lazy[pos];
        }
        lazy[pos] = -1;
    }

    int lazy_propagation(int pos, int izq, int der, int i, int j, int nuevo){
        solve_lazy(pos, izq, der);
        if(i > der || j < izq) return st[pos];

        if(i <= izq && j >= der){
            lazy[pos] = nuevo;
            solve_lazy(pos, izq, der);
            return st[pos];
        }

        int aux1 = lazy_propagation(mov_izq(pos), izq, (izq + der) >> 1, i, j, nuevo);
        int aux2 = lazy_propagation(mov_der(pos), ((izq + der) >> 1) + 1, der, i, j, nuevo);
        return st[pos] = min(aux1, aux2);
    }

    int update(int i, int j, int nuevo){//metodo a invocar
        return lazy_propagation(1, 0, n-1, i, j, nuevo);
    }
};

int main(){

    vi vec;
    vec.push_back(18);
    vec.push_back(17);
    vec.push_back(13);
    vec.push_back(19);
    vec.push_back(15);
    vec.push_back(11);
    vec.push_back(20);

    segment_tree tree;
    tree.iniciar(vec);

    cout << tree.RMQ(4, 6) << endl;
    tree.update(3, 6, 100);
    cout << tree.RMQ(2, 6) << endl;
    return 0;
}
