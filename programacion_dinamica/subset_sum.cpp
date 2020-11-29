#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
typedef vector<int> vi;

bool dp[10][50];//fila cantidad de numeros
//columas rango maximo a evaluar

void pre(vi &num){
    memset(dp, false, sizeof(dp));

    for(int i = 0; i < num.size(); i++){
        if(i) for(int j = 1; j < 50; j++)
            if(dp[i - 1][j]) dp[i][j + num[i]] = true;

        dp[i][num[i]] = true;
    }
}

int main(){
    vi n;
    n.push_back(7);
    n.push_back(7);
    n.push_back(7);
    n.push_back(7);
    n.push_back(8);
    n.push_back(1);
    n.push_back(1);
    n.push_back(1);
    n.push_back(6);
    pre(n);

    int m = 14;
    if(dp[n.size() - 1][m]) cout << "existe subconjunto\n";
    else cout << "no existe subconjunto\n";

    return 0;
}

