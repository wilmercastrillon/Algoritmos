#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int m = 13000000, itc = 0;
bool primo[13000100], used[13000100], sig;

void ciclo(int p, int con){
    if(p*6 > m/con){ sig = false; return; }
    int p6 = p*6;
    for(int n = con, np6 = p6*con; np6 - p < m; n++, np6= p6*n){
        itc++;
        used[np6 - p] = true;
        if(np6 + p < m) used[np6 + p] = true;
    }
}

void criba_6np(){
    memset(primo, false, sizeof(primo));
    memset(used, false, sizeof(used));
    int q, w, con = 0; sig = true;
    primo[2] = primo[3] = true;

    for(int i = 6; i < m; i += 6){
        q = i - 1; w = i + 1;
        if(used[q] && used[w]) continue;

        con++;
        if(!used[q]){
            primo[q] = true;
            if(sig) ciclo(q, con);
        }
        if(!used[w]){
            primo[w] = true;
            if(sig) ciclo(w, con);
        }
    }
}

int main(){
    int n;
    criba_6np();
    cout << "iteracciones: " << itc << endl;

    while(scanf("%d", &n) != EOF)
        printf("%s\n", (primo[n])? "primo": "no es primo");

    return 0;
}


