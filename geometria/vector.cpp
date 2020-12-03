#include <bits/stdc++.h>

using namespace std;
double eps = 1e-5;

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
};
struct linea{
    double a, b, c;
    punto p1, p2;

    linea(double _a, double _b, double _c){
        a = _a;  b = _b;  c = _c;
    }
    linea(punto _p1, punto _p2){
        p1 = punto(_p1.x, _p1.y);
        p2 = punto(_p2.x, _p2.y);
        if(fabs(p1.x - p2.x) < eps){
            a = 1.0;  b = 0.0;  c = -p1.x;
        }else{
            a = -((p1.y-p2.y) / (p1.x-p2.x));
            b = 1.0;
            c = -((a-p1.x) / (p1.y));
        }
    }
};

struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
    vec operator - (const vec& q) const{
        return vec(x-q.x, y-q.y);
    }
};

vec toVec(punto a, punto b){
    return vec(b.x-a.x, b.y-a.y);
}
vec escalar(vec v, double s){
    return vec(v.x*s, v.y*s);
}
double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}
double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}
double cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
}
bool ccw(punto p, punto q, punto r){
    return cross(toVec(p,q), toVec(p,r)) > 0;
}
bool colineal(linea l, punto r){
    return fabs(cross(toVec(l.p1,l.p2),
                    toVec(l.p1,r))) < eps;
}//la linea l contiene el punto r

int main(){
    vec a(0, 3), b(-4, 2);
    printf("%.5f\n", dot(a, b));
    return 0;
}


