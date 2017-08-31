#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;//metodo normal
lli mulmod (lli a, lli b, lli c) {
	lli x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

typedef __int128 bi; //metodo con __int128
lli mulmod_2(bi a, bi b, bi c){
    return (lli) ((a*b) % c);
}

int main(){
    lli a, b, c;
    cin >> a >> b >> c;
    cout << mulmod_2((bi) a, (bi) b, (bi) c) << endl;
    return 0;
}
