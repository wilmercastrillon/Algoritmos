#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const lli INFFLUJO=1e14, MAXN = 100010;
lli dist[MAXN], min_cost, cap[MAXN], max_flow;
int pre[MAXN];  bool en_cola[MAXN];//int n;

struct edge {
    int u, v;  lli cap, flow, cost;
    lli rem(){return cap-flow;}
};
vector<edge> aristas;  vector<int> grafo[MAXN];

void add_edge(int u, int v, lli cap, lli cost) {
    grafo[u].push_back(aristas.size());
    aristas.push_back(edge{u,v,cap,0,cost});
    grafo[v].push_back(aristas.size());
    aristas.push_back(edge{v,u,0,0,-cost});
}//Agrega aristas unidireccionales

void flow(int s, int t){
    memset(en_cola,0,sizeof(en_cola));
    max_flow = min_cost = 0;

    while(1){
        memset(dist, 3586, sizeof(dist));//inf 10^17
        memset(pre, -1, sizeof(pre));
        memset(cap, 0, sizeof(cap));
        pre[s] = dist[s] = 0;
        cap[s] = INFFLUJO;
        queue<int> cola;
        cola.push(s);  en_cola[s]=1;

        while(cola.size()){
            int u = cola.front();  cola.pop();  en_cola[u]=0;
            for(int j = 0; j < grafo[u].size(); j++){
                int i = grafo[u][j];
                edge &E = aristas[i];
                if(E.rem() && dist[E.v]>dist[u]+E.cost+1e-9){
                    dist[E.v] = dist[u]+E.cost;
                    pre[E.v]=i;
                    cap[E.v]= min(cap[u], E.rem());
                    if(!en_cola[E.v]){
                        cola.push(E.v);  en_cola[E.v] = 1;
                    }
                }
            }
        }

        if(pre[t] < 0) break;
        max_flow+=cap[t];  min_cost+=cap[t]*dist[t];
        for(int v = t; v != s; v = aristas[pre[v]].u){
            aristas[pre[v]].flow += cap[t];
            aristas[pre[v]^1].flow -= cap[t];
        }
    }
}

int main(){
    lli n,m,a,b,k,z,x,y, start, target, capacidad, costo;

    while(scanf("%lld %lld", &n, &m) != EOF){
		n++;
        for(int i = 0; i < n; i++) grafo[i].clear();
		aristas.clear();

        for(int i = 0; i < m; i++){
            scanf("%lld %lld %lld %lld", &x,&y,&capacidad,&costo);
            add_edge(x, y, capacidad, costo);
        }

        scanf("%lld %lld", &start, &target);
        flow(start, target);
        printf("minCost %lld , maxFlow %lld\n", min_cost, max_flow);
    }

	return 0;
}


