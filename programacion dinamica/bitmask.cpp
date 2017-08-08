#include <iostream>
#include <stdio.h>

using namespace std;

void mask(int n, int ar[]){
    int l = 1 << n;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                printf("%d ", ar[j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int n;
    cin >> n;

    int ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    mask(n, ar);

    return 0;
}
