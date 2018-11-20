#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define inf 1000000000 //10^9
int cam[10][10], matriz[10][10];

void imprimirCamino(int f, int c){
    if(cam[f][c] == f){
        printf("%d", f);
        return;
    }else{
        imprimirCamino(f, cam[f][c]);
        printf(" %d", cam[f][c]);
    }
}

void FloydWarshall(int nodos){
    int aux;
    //for(int i = 0; i < nodos; i++) matriz[i][i] = 0;//sin caminos
    for(int i = 0; i < nodos; i++){
        for(int j = 0; j < nodos; j++){
            if(i == j) matriz[i][j] = 0;
            if(i != j && matriz[i][j] != inf) cam[i][j] = i;
        }
    }

    for(int k = 0; k < nodos; k++)
        for(int i = 0; i < nodos; i++)
            for(int j = 0; j < nodos; j++){
                aux = matriz[i][k] + matriz[k][j];
                if(matriz[i][j] > aux){
                    matriz[i][j] = aux;
                    cam[i][j] = cam[k][j];
                }
            }
}

int main(){
    memset(matriz, 5436, sizeof(matriz));

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

	FloydWarshall(10);

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) cout << matriz[i][j] << " ";
		cout << "\n";
	}

	imprimirCamino(0, 7);

	return 0;
}
