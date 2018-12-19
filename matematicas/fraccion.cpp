#include <bits/stdc++.h>

using namespace std;

int MCD(int a, int b){
    return  a? MCD(b %a, a): b;
}

struct fraccion {
    int num, den;

    fraccion(int x, int y) {
        num = x; den = y;
        if (den < 0){ num *= -1;  den *= -1; }
        if (num == 0) den = 1;
        else {
            int dividir = MCD(num, den);
            num /= dividir;
            den /= dividir;
        }
    }

    fraccion operator+(fraccion b) {//suma
        return fraccion(num*b.den + b.num*den,
                         den*b.den);
    }
    fraccion operator-(fraccion b) {//resta
        return fraccion(num*b.den - b.num*den,
                         den*b.den);
    }
    fraccion operator*(fraccion b) {//multiplicar
        return fraccion(num*b.num, den*b.den);
    }
    fraccion inversa() {
        return fraccion(den, num);
    }
    fraccion operator/(fraccion b) {//dividir
        return fraccion(num*b.den, b.num*den);
    }
    string toString() {
        stringstream ss;
        ss << num;
        if (den == 1) return ss.str();
        ss << "/"; ss << den;
        return ss.str();
    }
};

int main(){

    int q, w;
    while(cin >> q >> w){
        fraccion c(q, w);
        cout << c.toString() << endl;
    }

    return 0;
}
