#include <bits/stdc++.h>

using namespace std;

struct fraccion {
    int num, den;

    void iniciar(int x, int y) {
        num = x; den = y;
        fraccion c = simplificar();
        num = c.num; den = c.den;
    }

    fraccion sumar(fraccion b) {
        fraccion c;
        c.num = num * b.den + b.num * den;
        c.den = den * b.den;
        return c.simplificar();
    }

    fraccion restar(fraccion b) {
        fraccion c;
        c.num = num * b.den - b.num * den;
        c.den = den * b.den;
        return c.simplificar();
    }

    fraccion multiplicar(fraccion b) {
        fraccion c;
        c.num = num * b.num;
        c.den = den * b.den;
        return c.simplificar();
    }

    fraccion inversa() {
        fraccion c;
        c.iniciar(den, num);
        return c;
    }

    fraccion dividir(fraccion b) {
        return multiplicar(b.inversa()).simplificar();
    }

    int mcd(int a, int b){
        return  a? mcd(b %a, a): b;
    }

    fraccion simplificar() {
        fraccion c;
        c.num = num; c.den = den;
        if (c.den < 0) {
            c.num *= -1; c.den *= -1;
        }
        if (c.num == 0) c.den = 1;
        else {
            int dividir = mcd(c.num, c.den);
            c.num /= dividir;
            c.den /= dividir;
        }
        return c;
    }

    string toString() {
        stringstream ss;
        ss << num;
        if (den == 1) return ss.str();
        ss << "/";
        ss << den;
        return ss.str();
    }
};

int main(){

    fraccion c;
    c.iniciar(2, 4);
    cout << c.toString() << endl;

    return 0;
}
