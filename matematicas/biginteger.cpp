#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct biginteger{
    vi num;

    void iniciar(string c){
        num.clear();
		int tam = c.length();
		for(int i = tam - 1; i > -1; i--) num.push_back(c[i] - '0');
		quitar_zeros_izq();
	}

	void iniciar(int c){
		num.clear();
		while(c > 0){
			num.push_back(c % 10);
			c /= 10;
		}
	}

	void imprimir(){
		for(int i = num.size() - 1; i > -1; i--) printf("%d", num[i]);
		printf("\n");
	}

	void quitar_zeros_izq(){
	    int q = num.size();
	    while(q > 1 && !num[--q]) num.pop_back();
	}

	biginteger suma(biginteger b2){
	    vi b = b2.num;
	    biginteger res;
		res.num.assign(num.begin(), num.end());
		int aux = 0, pos = b.size(), tam = num.size();

		for(int i = 0; i < pos; i++){
			if(i < tam){
				aux += res.num[i] + b[i];
				res.num[i] = aux % 10;
			}else{
				aux += b[i];
				res.num.push_back(aux % 10);
			}
			aux /= 10;
		}

		while(aux > 0){
			if(pos >= tam)
				res.num.push_back(aux % 10);
			else{
				aux += res.num[pos];
				res.num[pos++] = aux % 10;
			}
			aux /= 10;
		}
		res.quitar_zeros_izq();
		return res;
	}

    biginteger multiplicar(biginteger b2) {
        vi y = b2.num;
        int n = num.size() , m = y.size(), aux = 0, l = n - 1;
        biginteger res;
        res.num.assign(n + m - 1, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i != l)
                    res.num[i + j] += (num[i] * y[j]);
                else{
                    aux += res.num[i + j] + (num[i] * y[j]);
                    res.num[i + j] = aux % 10;
                    aux /= 10;
                }
            }
            if(i != l){
                aux += res.num[i];
                res.num[i] = aux % 10;
                aux /= 10;
            }
        }

        while(aux){
            res.num.push_back(aux % 10);
            aux /= 10;
        }
        res.quitar_zeros_izq();
        return res;
    }

    biginteger resta(biginteger b2){//asumimos que b2 es menor
        vi x = b2.num;
        biginteger res;
        res.num.assign(num.begin(), num.end());
        int i;

        for(i = 0; i < x.size(); i++){
            if(x[i] > res.num[i]){
                res.num[i] += 10;
                res.num[i + 1]--;
            }
            res.num[i] -= x[i];
        }
        while(res.num[i] < 0){
            res.num[i++] += 10;
            res.num[i]--;
        }
        res.quitar_zeros_izq();
        return res;
    }

    int comparar(biginteger b){//1 mayor, 0 igual, -1 menor
        if(num.size() > b.num.size()) return 1;
        else
            if(num.size() < b.num.size()) return -1;
            else{
                 for(int i = num.size() - 1; i > -1; i--){
                    if(num[i] > b.num[i]) return 1;
                    else if(num[i] < b.num[i]) return -1;
                }
            }
        return 0;
    }
};
typedef biginteger bigint;

bigint operator+(bigint &x, bigint &y){return x.suma(y);}
bigint operator-(bigint &x, bigint &y){return x.resta(y);}
bigint operator*(bigint &x, bigint &y){return x.multiplicar(y);}

bigint operator+=(bigint &x, bigint &y){return x = x.suma(y);}
bigint operator-=(bigint &x, bigint &y){return x = x.resta(y);}
bigint operator*=(bigint &x, bigint &y){return x = x.multiplicar(y);}

bool operator<(bigint &x, bigint &y){return x.comparar(y) == -1;}
bool operator>(bigint &x, bigint &y){return x.comparar(y) == 1;}
bool operator==(biginteger &x, biginteger &y){ return x.comparar(y) == 0;}
bool operator<=(bigint &x, bigint &y){
    int q = x.comparar(y);
    return q == -1 || q == 0;
}
bool operator>=(bigint &x, bigint &y){
    int q = x.comparar(y);
    return q == 0 || q == 1;
}

int main(){
    string n, m;
    biginteger b1, b2;

    while(cin >> n >> m){
        b1.iniciar(n);
        b2.iniciar(m);
        b1 = b1 * b2;
        b1.imprimir();
    }
}
