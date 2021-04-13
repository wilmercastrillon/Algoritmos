#include <bits/stdc++.h>

using namespace std;
double eps = 1e-5;

struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
};
double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}
double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}
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

vec toVec(punto a, punto b){return vec(b.x-a.x, b.y-a.y);}
double DEG_TO_RAD(double n){ return n*3.1416/180.0; }

punto rotar(punto p, double grados){//en sentido antihorario
    double rad = DEG_TO_RAD(grados);
    return punto(p.x*cos(rad) - p.y*sin(rad),
                p.x*sin(rad) + p.y*cos(rad));
}
punto transladar(punto p, vec v){
    return punto(p.x+v.x, p.y+v.y);
}
double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
double angulo(punto a, punto o, punto b){//en radianes
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}
bool colineal(punto p, punto q, punto r){
    return fabs(cross(toVec(p,q),toVec(p,r))) < eps;
}//r esta en la misma linea que p-q

double RAD_TO_DEG(double n){ return n*180.0/3.1416; }

int main(){
    punto a(1.0, 0.0), b(1.0, 1.0), c(1.0, 2.0);
    printf("%.5f\n", RAD_TO_DEG(angulo(a, b, c)));

    return 0;
}


