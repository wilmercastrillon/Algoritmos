#include <iostream>
#include <string.h>

using namespace std;

int tab[20][20], memo[20][20], fila, col;

/*
1 9 6 3 7
7 5 3 0 5
0 7 6 5 3
7 8 9 5 0
9 5 3 7 8
*/

void build(){
    memset(memo, 0, sizeof(memo));
    memo[1][1] = tab[0][0];
    for (int i = 2; i <= fila; i++)
        memo[i][1] = memo[i-1][1] + tab[i - 1][0];
    for (int j = 2; j <= col; j++)
        memo[1][j] = memo[1][j-1] + tab[0][j - 1];

    for (int i = 2; i <= col; i++)
		for (int j = 2; j <= col; j++)
            memo[i][j] = memo[i][j - 1] + memo[i - 1][j] +
                    tab[i - 1][j - 1] - memo[i - 1][j - 1];
}
//indexando desde 1
int query(int f1, int c1, int f2, int c2){
    return memo[f2][c2] - memo[f1-1][c2] -
                memo[f2][c1-1] + memo[f1-1][c1-1];
}

int main(){
    fila = col = 5;
    for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> tab[i][j];
    build();

    cout << "tabla aditiva:" << endl;
    for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++)
			cout << memo[i][j] << "   ";
        cout << endl;
    }

    cout << query(2, 2, 5, 5) << endl;
    return 0;
}
