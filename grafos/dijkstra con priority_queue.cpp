#include <iostream>
#include <queue>
#include <vector>
#define inf 1000000000

using namespace std;
typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vi dijkstra(vvii &grafo, int nodo, int tam){
    vi dis(tam + 1, inf);
    priority_queue<ii> cola;
    cola.push(ii(-0, nodo));
    int peso, aux;
    ii par, par2;

    while(cola.size()){
        par = cola.top();
        cola.pop();
        peso = -par.first;
        nodo = par.second;

        if(dis[nodo] <= peso) continue;
        dis[nodo] = peso;

        for(int i = 0; i < grafo[nodo].size(); i++){
            par2 = grafo[nodo][i];
            aux = dis[nodo] + par2.first;
            if(dis[par2.second] > aux){
                cola.push(ii(-aux, par2.second));
            }
        }
    }

    return dis;
}

int main(){
    int n, m, x, y, z;
    cin >> n >> m;
    vvii grafo(n + 1);

    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        grafo[x].push_back(ii(z, y));
        grafo[y].push_back(ii(z, x));
    }

    vector<vi> matriz;
    for(int i = 0; i < n; i++) matriz.push_back(dijkstra(grafo, i, n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%3d ", matriz[i][j]);
        }
        cout << endl;
    }

    return 0;
}


