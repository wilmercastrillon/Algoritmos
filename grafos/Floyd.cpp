#include <iostream>
#include <vector>

#define inf 1000

using namespace std;

vector<vector<int>> matriz(10, vector<int>(10, inf));

void FloydWarshall(vector<vector<int>> &grafo, int nodos){
    int aux;
    for(int i = 0; i < nodos; i++) grafo[i][i] = 0;
    
    for(int k = 0; k < nodos; k++)
        for(int i = 0; i < nodos; i++)
            for(int j = 0; j < nodos; j++){
                aux = grafo[i][k] + grafo[k][j];
                if(grafo[i][j] > aux) grafo[i][j] = aux;
            }
}

int main(){
	
	matriz[0][1] = 2;
	matriz[1][0] = 2;
	matriz[1][2] = 4;
	matriz[2][3] = 12;
	matriz[2][6] = 6;
	matriz[3][2] = 12;
	matriz[3][4] = 7;
	matriz[4][9] = 1;
	matriz[5][7] = 5;
	matriz[6][1] = 8;
	matriz[6][2] = 6;
	matriz[6][5] = 11;
	matriz[7][8] = 3;
	matriz[8][3] = 10;
	matriz[9][4] = 1;
	matriz[9][7] = 9;
	
	FloydWarshall(matriz, 10);
	
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) cout << matriz[i][j] << " ";
		cout << "\n";
	}
	
	return 0;
}
