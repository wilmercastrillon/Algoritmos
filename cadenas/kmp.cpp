#include <bits/stdc++.h>

using namespace std;
string cad, pat;
int tabla[1000];

void preCalcular(){
    int i = 0, j = -1;
    tabla[0] = -1;

    while(i < pat.length()){
        while(j >= 0 && pat[i] != pat[j]) j = tabla[j];
        i++;
        j++;
        tabla[i] = j;
    }
}

void kmp(){
    int i = 0, j = 0;
    while(i < cad.length()){
        while(j >= 0 && cad[i] != pat[j]) j = tabla[j];
        i++;
        j++;
        if(j == pat.length()){
            printf("%s esta en el indice %d de la cadena: %s\n", pat.c_str(), i - j, cad.c_str());
            j = tabla[j];
        }
    }
}

int main(){
    cad = "hola mundo";
    pat = "o";
    preCalcular();
    kmp();
    return 0;
}


