#include <bits/stdc++.h>

using namespace std;

int tab[5][10]; //filas solucion para la i-esima moneda

void solve(vector<int> &v, int c){
    int aux;

    for(int i = 0; i < v.size(); i++){
        if(i != 0)
            for(int j = 0; j < v[i]; j++) tab[i][j] = tab[i-1][j];

        for(int j = v[i]; j < c; j++){
            if(i == 0) aux = 1000000;
            else aux = tab[i - 1][j];
            tab[i][j] = min(1 + tab[i][j - v[i]], aux);
        }
    }
}

int recursivo(vector<int> &v, int f, int c){
    if(f < 0 || c < 0) return 1000;
    if(tab[f][c] != -1) return tab[f][c];

    if(c == 0) return 0;
    if(f == 0) return tab[f][c] = 1 + recursivo(v, f, c - v[f]);

    return tab[f][c] = min(1 + recursivo(v, f, c - v[f]), recursivo(v, f - 1, c));
}

int main(){

    vector<int> vi;
    vi.push_back(1);
    vi.push_back(4);
    vi.push_back(6);

    memset(tab, -1, sizeof(tab));
    //solve(vi, 10);
    recursivo(vi, 2, 8);

    for(int i = 0; i < vi.size(); i++){
        for(int j = 0; j < 10; j++){
            printf("%5d", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}


