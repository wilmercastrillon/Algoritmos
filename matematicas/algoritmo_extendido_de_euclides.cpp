#include <iostream>

using namespace std;

int gcd_ex (int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd_ex (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;//Maximo comun divisor
}

int main(){
    int n, m, x, y, res;

    while(cin >> n >> m){
        res = gcd_ex(n, m, x, y);
        cout << "gcd = " << res << ", x = " << x << ", y = " << y << endl;
    }
}
