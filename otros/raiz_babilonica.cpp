#include <bits/stdc++.h>
using namespace std;

double raiz(double x) {
    double b = x, h = 0, apro = 1;
    while (apro > 1e-8) {
        b = (h + b) / 2;
        h = x / b;
        apro = abs(h - b);
    }
    return b;
}

int main(){
    printf("%.5f\n", raiz(3));
}
