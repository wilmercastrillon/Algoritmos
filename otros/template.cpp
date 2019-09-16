#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef unsigned long long int ulli;
typedef long long int lli;

#define mpiii(a, b, c) iii(a, ii(b, c))
#define inf 1000000000//10^9
#define INFmemset 5436//inf para memeset en enteros
#define INFmemsetLL 3586//inf para memset en lli
#define forr(i, n) for(int i = 0; i < n; ++i)
#define forab(i, a, b) for(int i = a; i < b; ++i)

double eps = 1e-5;//ajustar segun se necesite

int main(){//fast I/O con iostream
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout << "hola mundo" << '\n';
    return 0;
}


void ayudas(){
    int n, x;
/* Expandir pila de memoria C++ 11
#include <sys/resource.h>
rlimit rl;
getrlimit(RLIMIT_STACK, &rl);
rl.rlim_cur=1024L*1024L*256L;//256mb
setrlimit(RLIMIT_STACK, &rl);
*/

//iterar mascara de bits
for(int i=n; i; i=(i-1)&n) // Decreciente
for (int i=0; i=i-n&n; ) // creciente
x = __builtin_popcount(n);//bits encendidos en n
x = __builtin_ctz(n);//ceros a la derecha de n
x = __builtin_clz(n);//ceros a la izquierda de n
x = __builtin_ffs(n);//primera posicion en 1
x = __builtin_ctzll((lli) n);//para lli agregars ll al nombre
x = (n&(-n));//least significant bit en 1
}


