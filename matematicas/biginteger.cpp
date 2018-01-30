#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;
typedef long long int tdato; //no debe ser unsigned para la resta!!!
tdato base = 1000000000;

struct biginteger{
    vector<tdato> num;

    void iniciar(int n){
        num.clear();
        while(n){
            num.push_back((n >= base)? n % base: n);
            n /= base;
        }
    }

    void iniciar(string n){
        num.clear();
        for(int i = n.size(); i > 0; i -= 9){
            if(i < 9) num.push_back(atoi(n.substr(0, i).c_str()));
            else num.push_back(atoi(n.substr(i-9, 9).c_str()));
        }
        quitar_zeros_izq();
    }

    void quitar_zeros_izq(){
        while(num.size() && !num.back()) num.pop_back();
    }

    void imprimir(){
        printf("%d", ((num.size())? num.back(): 0));
        for(int i = num.size() - 2; i >= 0; i--)
            printf("%09d", num[i]);
        printf("\n");
    }

    biginteger suma(biginteger b){
        ulli carry = 0, aux;
        int l = max(b.num.size(), num.size());
        biginteger c;

        for(int i = 0; i < l || carry; i++){
            aux = carry;
            if(i < b.num.size()) aux += b.num[i];
            if(i < num.size()) aux += num[i];

            if(aux >= base){
                c.num.push_back(aux % base);
                carry = aux / base;
            }else{
                c.num.push_back(aux);
                carry = 0;
            }
        }
        return c;
    }

    biginteger resta(biginteger b){//asumimos que b es menor
        tdato carry = 0;//no debe ser unsigned
        biginteger c;

        for(int i = 0; i < num.size(); i++){
            c.num.push_back(num[i]);
            c.num[i] -= ((i < b.num.size())? b.num[i]: 0) + carry;
            if(c.num[i] < 0){
                c.num[i] += base;
                carry = 1;
            }else carry = 0;
        }
        c.quitar_zeros_izq();
        return c;
    }

    biginteger multiplicar(biginteger b){
        ulli aux = 0, carry;
        biginteger c;
        c.num.assign(num.size() + b.num.size(), 0);

        for(int i = 0; i < num.size(); i++){
            carry = 0;
            for(int j = 0; j < b.num.size() || carry; j++){
                aux = c.num[i + j] + carry + (num[i] * ((j < b.num.size())? b.num[j] : 0));
                carry = aux / base;
                c.num[i + j] = aux % base;
            }
        }
        c.quitar_zeros_izq();
        return c;
    }

    int comparar(biginteger b){//este es: 1 mayor, 0 igual, -1 menor
        if(num.size() > b.num.size()){
            return 1;
        }else if(num.size() < b.num.size()){
            return -1;
        }else{
            for(int i = num.size() - 1; i >= 0; i--){
                if(num[i] > b.num[i]) return 1;
                else if(num[i] < b.num[i]) return -1;
            }
            return 0;
        }
    }
};

typedef biginteger bigint;

int main(){
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);

    int n, m;
    string s1, s2;
    bigint a, b;

    while(cin >> n){
        a.iniciar(1);

        for(int i = 1; i <= n; i++){
            b.iniciar(i);
            a = a.multiplicar(b);
        }

        a.imprimir();    }

    return 0;
}


