#include<bits/stdc++.h>

using namespace std;

int ar[10];

int f(int a, int b){
    return ar[a] > b;
}

int busqueda_binaria(int min, int max, int v){
    int epsilon = 1, med = 0;

    while(max-min > epsilon){
        med = (max+min)/2;
        if(f(med,v))
            max = med;
        else
            min = med;
    }
    return min;
}

int main(){

    for(int i = 0; i < 10; i++){
        ar[i] = i*i;
        cout << "i = " << i << " " << ar[i] << endl;
    }

    cout << busqueda_binaria(0, 10, 25) << endl;

    return 0;
}
