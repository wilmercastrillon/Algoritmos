#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; i++)
#define forab(i,a,b) for(int i = a; i < b; i++)

using namespace std;
const double eps = 1e-5;
const double PI = acos(-1.0);

struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
    vec operator - (const vec& q) const{
        return vec(x-q.x, y-q.y);
    }
};
double cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
}
double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}
double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
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
bool ccw(punto p, punto q, punto r){
    return cross(toVec(p,q), toVec(p,r)) > 0;
}
double angulo(punto a, punto o, punto b){//en radianes
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

double AreaPoligono(vector<punto> &p){
    double s = 0.0, d = 0.0;
    int n = p.size();
    forr(i, n){
        s += p[i].x*p[(i+1)%n].y;
        d += p[(i+1)%n].x*p[i].y;
    }
    return fabs(0.5*(s-d));
}

bool puntoLimite(punto p1, punto p2, punto q){
    if(colineal(p1,p2,q)){
        if((min(p1.x, p2.x)-q.x < eps) &&
           (q.x-max(p1.x, p2.x) < eps) &&
           (min(p1.y, p2.y)-q.y < eps) &&
           (q.y-max(p1.y, p2.y) < eps))
            return true;
    }
    return false;
}

//Metodo general
bool enPoligono(punto pt, vector<punto> &p){
    if(p.size() == 0) return false;
    double sum = 0.0;
    for(int i = 1; i < p.size(); i++){
        if(ccw(pt, p[i-1], p[i]))
            sum+= angulo(p[i-1],pt,p[i]);
        else sum -= angulo(p[i-1],pt,p[i]);
    }
    return fabs(fabs(sum) - 2*PI) < eps;
}
//Metodo mas preciso para poligonos convexos
double areaTriangulo(punto &pa, punto &pb, punto &pc){
    vec a(pa.x,pa.y), b(pb.x,pb.y), c(pc.x,pc.y);
    return (cross((c-a),(b-a)))/2.0;
}
//considerar el caso de todos los puntos iguales o colineales
bool enPoligonoConvexo(punto pt, vector<punto> &p) {
    double area = AreaPoligono(p), sum = 0.0;
    for(int i = 0; i < p.size()-1; i++) {
        if(p[i] == pt) return true;
        sum += fabs(areaTriangulo(p[i],pt,p[i+1]));
    }
    return fabs(area - sum) < eps;
}

int main(){
    int n, x, y;

    while(scanf("%d", &n) != EOF){
        vector<punto> a;
        forr(i, n){
            scanf("%d %d", &x, &y);
            a.push_back(punto(x, y));
        }
        a.push_back(a[0]);
        punto p = punto(1.0, 0.0);

        if(enPoligono(p, a)) printf("Adentro\n");
        else printf("Afuera\n");

        if(enPoligonoConvexo(p, a)) printf("Adentro\n");
        else printf("Afuera\n");
    }
    return 0;
}


