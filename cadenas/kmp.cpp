#include <bits/stdc++.h>

using namespace std;
int bordes[1000];

void preCalcular(string subcad){
    int i = 0, j = -1;
    bordes[0] = -1;

    while(i < subcad.size()) {
        while(j >= 0 && subcad[i] != subcad[j])
            j = bordes[j];
        i++; j++;
        bordes[i] = j;
    }
}

void kmp(string cad, string subcad){
    int i = 0, j = 0;
    while(i < cad.size()){
        while(j >= 0 && cad[i] != subcad[j]) j = bordes[j];
        i++; j++;
        if(j == subcad.size()){
            printf("%s esta en indice %d de la cadena: %s\n",
                   subcad.c_str(), i - j, cad.c_str());
            j = bordes[j];
        }
    }
}

int main(){
    string s1 = "Hola estadoestadoes hola";
    string s2 = "estadoes";
    preCalcular(s2);
    kmp(s1, s2);
    return 0;
}


