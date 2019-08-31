#include<bits/stdc++.h>

using namespace std;

int ar[10];

int f(int a, int b){return ar[a] > b;}
int busqueda_binaria(int men, int may, int v){
    int epsilon = 1, med = 0;
    while(may-men > epsilon){
        med = (may+men)/2;
        if(f(med,v)) may = med;
        else men = med;
    }
    return men;
}
//lower_bound -> cambiar f por: f(a,b){return ar[a] < b;}
//  cambiar "return men" por: return (f(med,v))? may: men;
//  y por ultimo invertir "may=med;" con "men = med;"

int main(){

    for(int i = 0; i < 10; i++){
        ar[i] = i*i;
        cout << "i = " << i << " " << ar[i] << endl;
    }

    cout << busqueda_binaria(0, 10, 25) << endl;

    return 0;
}
