#include <iostream>
#include <string.h>

using namespace std;

int tab[10][10];
int tab2[10][10];

/*ejemplo de entrada
1 9 6 3 7
7 5 3 0 5
0 7 6 5 3
7 8 9 5 0
9 5 3 7 8
*/

void pre(int f, int c){	//memorizacion
	for (int i = 1; i < 5; i++)
		tab[0][i] += tab[0][i - 1];
	for (int i = 1; i < 5; i++)
		tab[i][0] += tab[i - 1][0];
	
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			tab[i][j] += max(tab[i - 1][j], tab[i][j - 1]);
		}
	}
}

int pre2(int f, int c){	//buttom-up
	if(tab2[f][c] != -1) return tab2[f][c];
	
	if(f == 0) {
		tab2[f][c] = tab[f][c] + pre2(f, c - 1);
	}else{
		if(c == 0){
			tab2[f][c] = tab[f][c] + pre2(f - 1, c);
		}else{
			tab2[f][c] = tab[f][c] + max(pre2(f, c - 1), pre2(f - 1, c));
		}
	}
	return tab2[f][c];
}

int main(){
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> tab[i][j];
	
	
	/*pre(5, 5);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) cout << tab[i][j] << " ";
		cout << endl;
	}
	cout << "respuesta : " << tab[4][4] << endl;
	*/
	
	
	memset(tab2, -1, sizeof(tab));
	tab2[0][0] = tab[0][0];
	cout << "respuesta : " << pre2(4, 4) << endl;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) cout << tab2[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
