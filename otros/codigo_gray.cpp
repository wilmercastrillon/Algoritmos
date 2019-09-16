#include <iostream>

using namespace std;

int gray(int n) { return n ^ (n >> 1); }

int num(int gray) {//invertir
	int n = 0;
	for (; gray; gray >>= 1)
		n ^= gray;
	return n;
}

int main() {
	int n, m;

	while(cin >> n){
        n = gray(n);
        m = num(n);
        cout << "numero gray " << n << endl;
        cout << "original " << m << endl;
	}
}
