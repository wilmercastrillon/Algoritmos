#include <iostream>

using namespace std;

int gcdex (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcdex (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main(){
    int a = 117, m = 244;//encuentra un x tal que
    int x, y;            //(a * x) es congruente a 1 con modulo p
                         //-> (a * x) % p = 1 % p

    int g = gcdex (a, m, x, y);
    if (g != 1)
        cout << "no solution";
    else {
        x = (x % m + m) % m;
        cout << x << endl;
    }

    return 0;
}
