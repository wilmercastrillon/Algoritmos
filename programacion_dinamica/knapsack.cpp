#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

vi ben;//beneficio
vi cos;//costo
int knapsack(int cap, vi &cos, vi &ben, int n) {
    int dp[n+1][cap+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= cap; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(cos[i - 1] <= j)
                dp[i][j] = max(ben[i - 1] + dp[i - 1][j - cos[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][cap];
}

int main(){
    ben.push_back(8);
    ben.push_back(6);
    ben.push_back(5);
    ben.push_back(9);
    ben.push_back(7);

    cos.push_back(2);
    cos.push_back(3);
    cos.push_back(2);
    cos.push_back(1);
    cos.push_back(2);

    cout << knapsack(4, cos, ben, 5) << endl;
}


