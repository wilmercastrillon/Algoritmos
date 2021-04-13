#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int m = 130, cont = 2, p6;
//const int tam = sqrt(m) + 1;
bool primo[100000000], sig;

void ciclo(int p, int con){
    p6 = (p<<1)+(p<<2);
    if(p6 > m/con){ sig = false; return; }
    for(int n = con, np6 = p6*con; np6 - p < m; n++, np6= p6*n){
        primo[np6 - p] = false;
        if(np6 + p < m) primo[np6 + p] = false;
    }
}

void criba_6np(){
    memset(primo, true, sizeof(primo));
    int q, w, con = 0, i; sig = true;
    primo[1] = primo[4] = false;

    for(i = 6; sig; i += 6){
        q = i - 1; w = i + 1;
        con++;
        if(primo[q]){
            cont++;
            ciclo(q, con);
        }
        if(primo[w]){
            cont++;
            ciclo(w, con);
        }
    }
    //printf("hasta %d\n", i);

    for(; i < m; i += 6){
        if(primo[i - 1]) cont++;
        if(primo[i + 1]) cont++;
    }
}

int main(){
    int n;
    criba_6np();
    cout << "primos: " << cont << endl;

    /*while(scanf("%d", &n) != EOF)
        printf("%s\n", (primo[n])? "primo": "no es primo");
    */
    return 0;
}


