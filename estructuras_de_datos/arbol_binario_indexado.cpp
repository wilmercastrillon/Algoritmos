#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
typedef vector<int> vi;

struct FenwickTree{
    vi ft;

    void construir(int n){//indexamos desde 1
        ft.assign(n + 1, 0);
    }

    void construir(vi &v){
        ft.assign(v.size() + 1, 0);
        for(int i = 1; i <= v.size(); i++)
            actualizar(i, v[i - 1]);
    }

    int lsOne(int n){//bit menos significativo en 1
        return n & (-n);
    }

    int rsq(int i){//suma de 1 hasta i
        int acum = 0;
        for(; i; i -= lsOne(i)) acum+=ft[i];
        return acum;
    }

    int rsq(int i, int j){//suma de i hasta j
        return rsq(j) - ((i==1)? 0: rsq(i - 1));
    }

    void actualizar(int pos, int n){//n = nuevo - anterior
        for(; pos < ft.size(); pos += lsOne(pos))
            ft[pos] += n;
    }
};

int main(){
    int arr[] = {0, 1, 0, 1, 2, 3, 2, 1, 1, 0};
    vi ar;
    for(int i = 0; i < 10; i++) ar.push_back(arr[i]);

    FenwickTree tree;
    tree.construir(ar);

    cout << tree.rsq(8) << endl;
    cout << tree.rsq(5, 6) << endl;

    return 0;
}


