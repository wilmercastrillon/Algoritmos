#include <bits/stdc++.h>

using namespace std;
int bordes[1000];

void algoritmoBordes(string subcad){
    int i = 0, j = -1;
    bordes[0] = -1;

    while(i < subcad.size()) {
        while(j >= 0 && subcad[i] != subcad[j])
            j = bordes[j];
        i++; j++;
        bordes[i] = j;
    }
}

int main(){
    string str = "seventy seven";
    algoritmoBordes(str);
    for(int i = 0; i < str.size(); i++){
        printf(" %d", bordes[i]);
    }
    printf("\nLongitud de borde: %d\n",
        bordes[str.size()-1] + 1);

    return 0;
}


