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
};

//punto p esta dentro del circulo con centro c y radio r
double dentroDelCirculo(punto p, punto c, double r){
    double dx = p.x-c.x, dy = p.y-c.y;
    double euc = dx*dx + dy*dy, rsq = r*r;
    return (euc < rsq)? 0 : (euc==rsq)? 1 : 2;
}//0-dentro, 1-borde, 2-afuera
double

int main(){
    linea q(2, 1, 3), w(-4, 1, 5);
    punto p;

    if(interseccion(q, w, p)){
        printf("interceptan en (%.5f , %.5f)\n", p.x, p.y);
    }

    return 0;
}


