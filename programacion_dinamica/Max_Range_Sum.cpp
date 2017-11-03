#include <stdio.h>
#define max(a, b) (a > b)? a: b

using namespace std;

int main(){
    int n, num, res, aux;

    while(scanf("%d", &n), n){
        res = aux = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            aux += num;
            res = max(aux, res);
            if(aux < 0) aux = 0;
        }

        if(res > 0) printf("MRS = %d\n", res);
        else printf("negativo.\n");
    }
    return 0;
}
