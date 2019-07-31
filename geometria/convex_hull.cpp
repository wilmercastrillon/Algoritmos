#include <bits/stdc++.h>

using namespace std;
double eps = 1e-5;


struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
};
double cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
}


struct punto{
    double x, y;

    punto(){ x = y = 0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }

    bool operator < (punto p) const{//para poder usar sort
        if(fabs(x - p.x) > eps) return x < p.x;
        return y < p.y;
    }
    bool operator == (punto p) const{
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }
};
vec toVec(punto a, punto b){
    return vec(b.x-a.x, b.y-a.y);
}
bool colineal(punto p, punto q, punto r){
    return fabs(cross(toVec(p,q),toVec(p,r))) < eps;
}
double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
bool ccw(punto p, punto q, punto r){
    return cross(toVec(p,q), toVec(p,r)) > 0;
}


punto pivote;

bool angleCmp(punto a, punto b){
    if(colineal(pivote,a,b))
        return dist(pivote,a) < dist(pivote,b);
    double d1x = a.x-pivote.x, d1y = a.y-pivote.y;
    double d2x = b.x-pivote.x, d2y = b.y-pivote.y;
    return (atan2(d1y,d1x) - atan2(d2y,d2x)) < 0;
}

vector<punto> ConvexHull(vector<punto> p){
    pivote = punto(0,0);
    int i, j, n = p.size();
    if(n <= 3){
        if(!(p[0]==p[n-1])) p.push_back(p[0]);
        return p;
    }

    int p0 = 0;
    for(int i = 0; i < n; i++)
        if(p[i].y<p[p0].y || (p[i].y==p[p0].y && p[i].x>p[p0].x))
            p0 = i;

    punto temp = p[0]; p[0] = p[p0]; p[p0] = temp;
    pivote = p[0];
    sort(++p.begin(), p.end(), angleCmp);

    vector<punto> s;
    s.push_back(p[n-1]); s.push_back(p[0]); s.push_back(p[1]);
    i = 2;
    while(i < n){
        j = s.size()-1;
        if(ccw(s[j-1],s[j],p[i])) s.push_back(p[i++]);
        else s.pop_back();
    }
    return s;
}

int main(){
    int n, r, x, y;
    while(scanf("%d", &n) != EOF){
        vector<punto> p;

        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            p.push_back(punto(x, y));
        }

        vector<punto> ch = ConvexHull(p);
        for(int i = 0; i < ch.size(); i++){
            printf("(%.3f %.3f)\n", ch[i].x, ch[i].y);
        }

        printf("\n");
    }
    return 0;
}


