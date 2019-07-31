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
struct vec{
    double x, y;
    vec(double _x, double _y){
        x = _x;  y = _y;
    }
};
vec toVec(punto a, punto b){return vec(b.x-a.x, b.y-a.y);}
double dot(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}
double norm_sq(vec v){
    return v.x*v.x + v.y*v.y;
}
punto transladar(punto p, vec v){
    return punto(p.x+v.x, p.y+v.y);
}
vec escalar(vec v, double s){
    return vec(v.x*s, v.y*s);
}
double dist(punto p1, punto p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

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
            c = -a*p1.x-p1.y;
        }
    }
};

bool paralelas(linea l1, linea l2){
    return fabs(l1.a-l2.a)<eps && fabs(l1.b-l2.b)<eps;
}
bool iguales(linea l1, linea l2){
    return paralelas(l1, l2) && fabs(l1.c-l2.c)<eps;
}
bool interseccion(linea l1, linea l2, punto &p){
    if(paralelas(l1, l2)) return false;
    p.x = (l2.b*l1.c-l1.b*l2.c) / (l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b)>eps) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}
bool intersecSegmentos(linea l1, linea l2, punto &p){
    punto pp, c;
    if(interseccion(l1,l2,pp)){
        if(distSegmento(pp,l1,c)<eps &&
           distSegmento(pp,l2,c)<eps){
            p.x = pp.x;  p.y = pp.y;
            return true;
        }
    }
    return false;
}
//distancia minima entre p y l
double distLinea(punto p, linea l, punto &c){
    punto a = l.p1, b = l.p2;
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = transladar(a, escalar(ab, u));//punto mas cercano
    return dist(p, c);
}
double distSegmento(punto p, linea l, punto &c){
    punto a = l.p1, b = l.p2;
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if(u < 0.0){
        c = punto(a.x, a.y); return dist(p, a);
    }
    if(u > 1.0){
        c = punto(b.x, b.y); return dist(p, b);
    }
    return distLinea(p, l, c);
}

int main(){
    linea q(2, 1, 3), w(-4, 1, 5);
    punto p;

    if(interseccion(q, w, p)){
        printf("interceptan en (%.5f , %.5f)\n", p.x, p.y);
    }

    return 0;
}


