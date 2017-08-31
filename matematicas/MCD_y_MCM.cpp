#include <stdio.h>

using namespace std;

int mcd(int a, int b){//algoritmo de euclides
    return  a? mcd(b %a, a): b;
}

int mcm(int a, int b) {
	return a*b/mcd(a,b);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", mcm(a, b));

    return 0;
}
