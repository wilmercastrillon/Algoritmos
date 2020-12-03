#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;

struct UnionFind {
	int n,comp;
	vector<int> uf,si,c;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
		for(int i=0; i<n; ++i) uf[i]=i;
    }
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(c.size()>snap){
			int x=c.back();c.pop_back();
			si[uf[x]]-=si[x];uf[x]=x;comp++;
		}
	}
};
enum {ADD,DEL,QUERY};
struct Query {int type,x,y;};
struct DynCon {
	vector<Query> q;
	UnionFind dsu;
	vector<int> mt;
	map<pair<int,int>,int> last;
	DynCon(int n):dsu(n){}
	void add(int x, int y){
		if(x>y) swap(x,y);
		q.pb((Query){ADD,x,y}),mt.pb(-1);
		last[{x,y}]=q.size()-1;
	}
	void remove(int x, int y){
		if(x>y)swap(x,y);
		q.pb((Query){DEL,x,y});
		int pr=last[{x,y}];
		mt[pr]=q.size()-1;
		mt.pb(pr);
	}
	void query(){
		q.pb((Query){QUERY,-1,-1});mt.pb(-1);}
	void process(){ // answers all queries in order
		if(!q.size()) return;
		for(int i=0; i<q.size(); ++i)
            if(q[i].type==ADD&&mt[i]<0)mt[i]=q.size();
		go(0,q.size());
	}
	void go(int s, int e){
		if(s+1==e){
			if(q[s].type==QUERY) // answer query using DSU
				printf("%d\n",dsu.comp);
			return;
		}
		int k=dsu.snap(),m=(s+e)/2;
		for(int i=e-1;i>=m;--i)if(mt[i]>=0&&mt[i]<s)dsu.join(q[i].x,q[i].y);
		go(s,m);
		dsu.rollback(k);
		for(int i=m-1;i>=s;--i)if(mt[i]>=e)dsu.join(q[i].x,q[i].y);
		go(m,e);
		dsu.rollback(k);
	}
};

int main(){
	int n,m,k;
	int tipo, x, y;

	while(scanf("%d %d",&n,&k) != EOF){
        DynCon w(n);
        while(k--){
            scanf("%d", &tipo);
            if(tipo == 2){
                w.query();
            }else{
                scanf("%d %d",&x,&y);
                x--;  y--;
                w.add(x, y);
            }
        }
        w.process();
	}
	return 0;
}
