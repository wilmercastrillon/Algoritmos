#include <bits/stdc++.h>
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

int inverso(int a, int m){
    int x, y;
    int g = gcd_ex (a, m, x, y);
    if (g != 1) return -1;
    else  return (x % m + m) % m;
}

int metodoWilson(int n, int p)  {
	if (p <= n) return 0;
	int res = (p - 1);

	for (int i = n + 1; i < p; i++)
		res = (res * inverso(i, p)) % p;
	return res;
}

int main() {
	int n = 100, p = 127;//29
	cout << metodoWilson(n, p);
	return 0;
}


