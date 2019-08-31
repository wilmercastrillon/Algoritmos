#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int A[] = {-7, 10, 9, 2, 3, 8, 8, 6};
int aux[10], lis[10], indexAnt[10], n = 8;

void mostrar(int pos){
    stack<int> pila;
    while(pos != -1)
        pila.push(pos), pos = lis[pos];

    while(pila.size()){
        printf("%d\n", A[pila.top()]);
        pila.pop();
    }
}

void imp(int ar[], int v){
    for(int i = 0; i < v; ++i){
        printf("%3d",ar[i]);
    }
    printf("\n");
}

//Para decreciente invertir el signo de los numeros
void LIS(){                     //en el arreglo.
    int tam = 0, pos, res = 0;
    for(int i = 0; i < n; i++){
        pos = lower_bound(aux, aux + tam, A[i]) - aux;
        imp(aux,tam);
        printf("pos = %d hasta %d, buscando %d\n", pos,tam, A[i]);
        //usar upper_bound para contar repetidos
        aux[pos] = A[i];
        indexAnt[pos] = i;
        lis[i] = pos;
        lis[i] = pos? indexAnt[pos-1]: -1;
        if(pos + 1 > tam){
            tam = pos + 1;
            res = i;
        }
    }

    printf("longitud: %d\n", tam);
    mostrar(res);
}

int LIS_dp(){
    int res = 0;
    vector<int> vec(8, 1);

    for(int i = 0; i < 8; i++)
        for(int j = i + 1; j < 8; j++)
            if(A[i] < A[j]) vec[j] = max(vec[j], vec[i] + 1);
        res = max(res, vec[i]);
    return res;
}

int main(){
    LIS();
    //printf("%d\n", LIS_dp());
    return 0;
}
