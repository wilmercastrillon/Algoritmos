#include <iostream>
#include <string.h>

using namespace std;
typedef unsigned long long int ulli;

ulli fibo[102];

ulli recursivo(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	return recursivo(n - 2) + recursivo(n - 1);
}

void memorizacion(int n){
	fibo[0] = 0;
	fibo[1] = 1;
	
	for (int i = 2; i <= n; i++){
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
}

ulli buttom_up(int n){
	if(n == 0) return 0;
	if(fibo[n] != 0) return fibo[n];
	else return fibo[n] = buttom_up(n - 2) + buttom_up(n - 1);
}

int main(){
	
	int num;
	
	/* recursivo normal
	while(cin >> num, num >= 0) cout << recursivo(num) << endl;
	*/
	
	
	/* memorizacion
	memorizacion(100);
	while(cin >> num, num >= 0) cout << fibo[num] << endl;
	*/
	
	
	// buttom up
	memset(fibo, 0, sizeof(fibo));
	fibo[1] = 1;
	while(cin >> num, num >= 0){
		cout << buttom_up(num) << endl;
	}
	
	return 0;
}
