#include<bits/stdc++.h>

using namespace std;

int ar[10];

int f(int a, int b){
    return ar[a] > b;
}

int busqueda_binaria(int men, int may, int v){
    int epsilon = 1, med = 0;

    while(may-men > epsilon){
        med = (may+men)/2;
        if(f(med,v))
            may = med;
        else
            men = med;
    }
    return men;
}

int main(){

    for(int i = 0; i < 10; i++){
        ar[i] = i*i;
        cout << "i = " << i << " " << ar[i] << endl;
    }

    cout << busqueda_binaria(0, 10, 25) << endl;

    return 0;
}
