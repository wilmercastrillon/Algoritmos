#include <iostream>

using namespace std;

int gcd_ex(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd_ex(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;//Maximo comun divisor
}

int main(){
    //freopen("salida.txt", "w", stdout);
    int n, m, x, y, res, aux;

    while(scanf("%d %d", &n, &m) != EOF){
        res = gcd_ex(n, m, x, y);
        printf("(%d * %d) + (%d * %d) = %d\n",n,x,m,y,res);
    }
}


