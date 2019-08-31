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
    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", mcd(a, b));
    }

    return 0;
}
