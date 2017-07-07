#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

struct segment_tree{
    vi st, A;
    int n;

    int mov_izq(int index){
        return index << 1;
    }

    int mov_der(int index){
        return (index << 1) + 1;
    }

    void construir(int pos, int izq, int der){
        //cout << "llamado para pos " << pos << " en rango " << izq << " , " << der << endl;
        if(izq == der){
            st[pos] = der;
            //cout << "iguales" << endl;
            return;
        }

        construir(mov_izq(pos), izq, (izq + der) >> 1);
        construir(mov_der(pos), ((izq + der) >> 1) + 1, der);
        int aux1 = st[mov_izq(pos)], aux2 = st[mov_der(pos)];
        st[pos] = (A[aux1] < A[aux2])? aux1: aux2;
        //cout << "en pos " << pos << " en rango " << izq << " , " << der << " se guarda " << st[pos] << endl;
    }

    void iniciar(vi arr){
        A = arr;
        n = A.size();
        st.assign(n*4, 0);
        construir(1, 0, n - 1);
    }

    int rmq(int pos, int izq, int der, int i, int j){
        if(i > der || j < izq) return -1;
        if(i <= izq && j >= der) return st[pos];

        int aux1 = rmq(mov_izq(pos), izq, (izq + der) >> 1, i, j);
        int aux2 = rmq(mov_der(pos), ((izq + der) >> 1) + 1, der, i, j);
        if(aux1 == -1) return aux2;
        if(aux2 == -1) return aux1;

        return (A[aux1] < A[aux2])? aux1: aux2;
    }

    int RMQ(int i, int j){
        return rmq(1, 0, n-1, i, j);
    }

    int cambiar(int pos, int izq, int der, int index, int nuevo){
        if(index > der || index < izq) return st[pos];
        if(der == index && izq == index){
            A[index] =  nuevo;
            return st[pos] = index;
        }

        int aux1 = cambiar(mov_izq(pos), izq, (izq + der) >> 1, index, nuevo);
        int aux2 = cambiar(mov_der(pos), ((izq + der) >> 1) + 1, der, index, nuevo);
        return st[pos] = (A[aux1] < A[aux2])? aux1: aux2;
    }

    int update(int index, int num){
        return cambiar(1, 0, n-1, index, num);
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
    tree.update(5, 100);
    cout << tree.RMQ(4, 6) << endl;

    for(int i = 0; i < tree.st.size(); i++) cout << tree.st[i] << " ";
    cout << endl;
    return 0;
}
