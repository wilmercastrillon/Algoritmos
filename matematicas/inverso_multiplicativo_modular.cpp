#include <iostream>

using namespace std;

int gcd_ex (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd_ex (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

void inverso(int a, int m){
    int x, y;

    int g = gcd_ex (a, m, x, y);
    if (g != 1)
        cout << "no solution";
    else {
        x = (x % m + m) % m;
        cout << x << endl;
    }
}

int main(){
    int a = 117, m = 244;//encuentra un x tal que
    int x, y;            //(a * x) es congruente a 1 con modulo p
                         //-> (a * x) % p = 1 % p
    inverso(a, m);

    return 0;
}
