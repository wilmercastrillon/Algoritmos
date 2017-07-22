#include <bits/stdc++.h>

using namespace std;
typedef queue<int> qi;
typedef vector<qi> vqi;

int ent[1000010];
vector<int> res;

bool topological_sort(vqi &lis, int tam, int aris){
    res.clear();
    qi s;
    for(int i = 1; i <= tam; i++){
        //printf("nodo %d , tiene %d aristas entantes\n", i, ent[i]);
        if(!ent[i]) s.push(i);
    }

    int n, m;
    while(s.size()){
        n = s.front();
        s.pop();
        res.push_back(n);

        while(lis[n].size()){
            m = lis[n].front();
            //cout << "entra " << n << " va a " << m;
            lis[n].pop();
            ent[m]--;
            aris--;
            //cout << " le quedan " << ent[m] << " aristas a " << m << endl;

            if(!ent[m]) s.push(m);
        }
    }

    return (aris == 0);
}

int main(){
    int n, m, x, y;

    while(scanf("%d %d", &n, &m), n, m){//cantidad de nodos y aristas
        vqi grafo(n + 1);
        memset(vis, 0, sizeof(vis));
        memset(ent, 0, sizeof(ent));

        for(int i = 0; i < m; i++){
            scanf("%d %d", &x, &y);
            grafo[x].push(y);
            ent[y]++;
        }

        bool aux = topological_sort(grafo, n, m);
        //cout << "ggg " << aux << endl;
        if(res.size() == n)
            for(int i = 0; i < res.size(); i++) printf("%d\n", res[i]);
        else
            printf("IMPOSSIBLE\n");//contiene ciclo!!!
    }
}
