#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int mod = 1e9 + 9;

lli compute_hash(string s) {
    int p = 31;//numero primo
    lli hash_value = 0;
    lli pot = 1;
    for(char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * pot) % mod;
        pot = (pot * p) % mod;
    }
    return hash_value;
}

int main(){
    string s1 = "hola mundo";
    printf("hash = %lld\n", compute_hash(s1));
    return 0;
}


