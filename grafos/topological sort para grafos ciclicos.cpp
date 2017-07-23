#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector <vi> vii;

vector<int> res, ent;

void topological_sort(vii &lis, int tam){
    res.clear();
    queue<int> s;
    for(int i = 1; i <= tam; i++){
        //printf("nodo %d , tiene %d aristas entantes\n", i, ent[i]);
        if(!ent[i]) s.push(i);
    }

    int n, m;
    while(s.size()){
        n = s.front();
        s.pop();
        res.push_back(n);

        for(int i = 0; i < lis[n].size(); i++){
            m = lis[n][i];
            ent[m]--;
            if(!ent[m]) s.push(m);
        }
    }
}

int main(){
    int n, m, x, y;

    while(scanf("%d %d", &n, &m), n, m){//cantidad de nodos y aristas
        vii grafo(n + 1);
        ent.assign(n + 1, 0);

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            grafo[x].push_back(y);
            ent[y]++;
        }

        topological_sort(grafo, n);
        
        if(res.size() == n)//ordenamiento topologico
            for(int i = 0; i < res.size(); i++) printf("%d\n", res[i]);
        else
            printf("hay un ciclo!!!\n");//contiene ciclo!!!
    }
}
