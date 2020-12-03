#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)

using namespace std;
typedef vector<int> vi;
const double PI = acos(-1);

typedef complex<double> base;
int rev[600010];//Longitun >= n

void fft(vector<base> &a, bool invert) {
	int n = (int) a.size();

	for(int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);

	for(int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w(1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if(invert)
		for(int i=0; i<n; ++i)
			a[i] /= n;
}
//Llamar este metodo antes del primer llamado a multiply
void calc_rev(int n, int log_n){
	for(int i=0; i<n; ++i) {
		rev[i] = 0;
		for(int j=0; j<log_n; ++j)
			if(i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}
//n >= a.size()+b.size(), y debe ser potencia de 2
void multiply(vector<int> &a, vector<int> &b, int &n, vector<int> &res) {
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n);  fb.resize(n);

    fft(fa, false),  fft(fb, false);
    for(int i=0; i<n; ++i) fa[i] *= fb[i];
    fft(fa, true);

    res.resize(n);
    for(int i=0; i<n; ++i)
        res[i] = int(fa[i].real() + 0.5);

    //Omitir lo de abajo para multiplicar polinomios
    //Acarreos para la multiplicacion de numeros
    int carry = 0;
    for(int i=0; i<n; ++i) {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
}

char s1[300005], s2[300005], res[300010];

int main(){
    int ls1, ls2;

    while(scanf("%s", &s1) != EOF){
        scanf("%s", &s2);
        ls1 = strlen(s1);  ls2 = strlen(s2);
        reverse(s1, s1+ls1);  reverse(s2, s2+ls2);

        vector<int> v1(ls1,0), v2(ls2,0);
        int n = 1;
        while(n < v1.size() + v2.size()) n <<= 1;
        calc_rev(n, round(log2(n)));
        vector<int> mult(n, 0);

        forr(j, ls1)
            v1[j] = s1[j] - '0';
        forr(j, ls2)
            v2[j] = s2[j] - '0';

        multiply(v1, v2, n, mult);

        reverse(mult.begin(), mult.end());
        forr(i, mult.size()){
            printf("%d", mult[i]);
        }
        printf("\n");
    }

    return 0;
}


