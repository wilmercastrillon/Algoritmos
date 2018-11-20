#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;//peso, nodo
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
#define inf 1000000000
vi padre;//opcional, usar cuando se necesite el camino.

vi dijkstra(vvii &grafo, int nodo, int tam){
    padre.assign(tam + 1, -1);
    vi dis(tam + 1, inf);
    priority_queue<ii> cola;
    cola.push(ii(-0, nodo));
    int peso, aux;
    ii par, par2;

    while(cola.size()){
        par = cola.top();//peso, nodo
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
                padre[par2.second] = nodo;
            }
        }
    }

    return dis;
}

void camino(int n){//imprimir el camino
    if(padre[n] == -1) printf("%d", n);
    else{
        camino(padre[n]);
        printf(" %d", n);
    }
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
    cout << endl;

    return 0;
}


