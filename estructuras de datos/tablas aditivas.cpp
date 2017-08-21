#include <iostream>
#include <string.h>

using namespace std;

int tab[10][10], tab2[10][10];

/*
1 9 6 3 7
7 5 3 0 5
0 7 6 5 3
7 8 9 5 0
9 5 3 7 8
*/

void build(){
    memset(tab2, 0, sizeof(tab2));
    tab2[1][1] = tab[0][0];
    for (int i = 2; i < 6; i++) tab2[i][1] = tab2[i-1][1] + tab[i - 1][0];
    for (int j = 2; j < 6; j++) tab2[1][j] = tab2[1][j-1] + tab[0][j - 1];

    for (int i = 2; i < 6; i++)
		for (int j = 2; j < 6; j++)
            tab2[i][j] = tab2[i][j - 1] + tab2[i - 1][j] + tab[i - 1][j - 1] - tab2[i - 1][j - 1];
    //ejemplo: acumulado de 2,2 hasta 5,5
    //tab2[5][5] - tab2[2][5] - tab2[5][2] + tab2[2][2]
}

int main(){
    for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> tab[i][j];
    build();

    cout << "tabla aditiva:" << endl;
    for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++)
			cout << tab2[i][j] << "   ";
        cout << endl;
    }

    cout << "acumulado de 2,2 hasta 5,5" << endl;
    cout << tab2[5][5] - tab2[2][5] - tab2[5][2] + tab2[2][2] << endl;
    return 0;
}
