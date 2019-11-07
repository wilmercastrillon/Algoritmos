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
            printf("%s esta en el indice %d de la cadena: %s\n",
                   subcad.c_str(), i - j, cad.c_str());
            j = bordes[j];
        }
    }
}

int main(){
    string s1 = "0010020030040050060070080090000100200300400500600700800900";
    string s2 = "00100200300400500600700800900";
    preCalcular(s2);
    kmp(s1, s2);
    return 0;
}


