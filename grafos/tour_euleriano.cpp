#include <stdio.h>
#include <string.h>
#include <list>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

typedef list<int>::iterator lii;
int degree[100];
vector<vector<pair<int, bool>>> lista;//destino, visitado
list<int> cyc;

void EulerTour(lii i, int u){
    for(int j = 0; j < lista[u].size(); j++){
        ib v = lista[u][j];
        if(v.second){
            v.second = false;
            lista[u][j].second = false;
            for(int k = 0; k < lista[v.first].size(); k++){
                ib uu = lista[v.first][k];
                if(uu.first==u && uu.second){
                    uu.second = false;
                    lista[v.first][k].second = false;
                    break;
                }
            }
            //inserta conexion (v.first,u)
            EulerTour(cyc.insert(i, u), v.first);
        }
    }
}

int main(){
    int n, m, x, y, t, caso = 0;

    while(scanf("%d %d", &n, &m) != EOF){
        lista.assign(n+1, vector<ib>(0));
        memset(degree, 0, sizeof(degree));

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            lista[x].push_back(ib(y, true));
            lista[y].push_back(ib(x, true));
            degree[x]++;
            degree[y]++;
        }

        bool par = true;
        int inicio = 1;
        for(int i = 0; i < 52 && par; i++){
            if(degree[i]&1) par = false;
            else if(degree[i]){
                inicio = i;
            }
        }

        if(!par){
            printf("No es euleriano\n");
        }else{
            cyc.clear();
            EulerTour(cyc.begin(), inicio);

            for(lii it = cyc.begin(); it != cyc.end(); it++){
                printf("%d\n", *it);
            }
        }
    }

    return 0;
}




