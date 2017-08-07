#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
typedef vector<int> vi;

bool dp[5][50];

void pre(vi &num){
    memset(dp, false, sizeof(dp));
    //for(int i = 0; i < num.size())

    for(int i = 0; i < num.size(); i++){
        if(i) for(int j = 1; j < 50; j++)
            if(dp[i - 1][j]) dp[i][j + num[i]] = true;

        dp[i][num[i]] = true;
    }
}

int main(){
    vi n;
    n.push_back(1);
    n.push_back(3);
    n.push_back(5);
    pre(n);

    int m = 9;
    if(dp[n.size() - 1][m]) cout << "existe subconjunto\n";
    else cout << "no existe subconjunto\n";

    return 0;
}

