#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef long long int lli;
const double eps = 1e-5;

struct punto{
    double x, y;
    punto(){ x = y = 0; }
    punto(double _x, double _y){
        x = _x;  y = _y;
    }
};

vector<punto> puntos;

double distpow2(punto p1, punto p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

double CircumCircle(punto &A, punto &B, punto &C, punto &c){
    double bx = B.x-A.x, by = B.y-A.y;
    double cx = C.x-A.x, cy = C.y-A.y;
    double _B = bx * bx + by * by;
    double _C = cx * cx + cy * cy;
    double _D = bx * cy - by * cx;
    c = punto((cy*_B - by*_C) / (2*_D),
                (bx*_C - cx*_B) / (2*_D));
    c.x += A.x;
    c.y += A.y;
    return distpow2(c, A);
}

double minCoverCircle(vector<punto> &p){
    double maxlen = 0.0, aux;
    punto c = p[0];
    double r = 0.0;

    forab(i,1,p.size()){
        if(distpow2(c, p[i]) >= r+eps){
            r = 0.0;
            c = p[i];
            forr(j, i){
                if(distpow2(c, p[j]) >= r+eps){
                    c.x = (p[i].x+p[j].x)/2.0;
                    c.y = (p[i].y+p[j].y)/2.0;
                    r = distpow2(c, p[i]);
                    forr(k, j){
                        if(distpow2(p[k], c) >= r+eps)
                            r = CircumCircle(p[i],p[j],p[k],c);
                    }
                }
            }
        }
    }
    return sqrt(r);
}

int main(){
    double x, y, r, minr;
    int t;

    while(cin >> t){
        puntos.clear();
        forr(i, t){
            cin >> x >> y;
            puntos.pb(punto(x, y));
        }

        minr = minCoverCircle(puntos);
        printf("Radio menor %.5f\n", minr);
    }

    return 0;
}


