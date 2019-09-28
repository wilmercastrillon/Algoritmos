#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int memo[110][110];
char dummy = (char) 1;
int costo(char a, char b){
    if(a == b) return 1;
    else if (a==dummy || b == dummy)
        return 0;
    else return -1000000;
}//Maximizar y casos base memo[][] = 0

int dp(string &cad1, string &cad2){
    int ans;
    for(int i = 0; i <= cad2.size(); ++i) memo[0][i] = 0;
    for(int i = 0; i <= cad1.size(); ++i) memo[i][0] = 0;

    for(int i = 0; i < cad1.size(); ++i)//f
        for(int j = 0; j < cad2.size(); ++j){//c
            ans = costo(cad1[i],cad2[j]) + memo[i][j];
            ans = max(ans,costo(cad2[i],dummy) + memo[i+1][j]);
            ans = max(ans,costo(cad1[i],dummy) + memo[i][j+1]);
            memo[i+1][j+1] = ans;
        }
    return memo[cad1.size()][cad2.size()];
}

int main(){
    string cad1, cad2;
    int dist, caso = 0;

    while(cin >> cad1 >> cad2){
        printf("LCS = %d\n", dp(cad1, cad2));
    }
}


