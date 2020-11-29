#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define mod 1000000000000LL;

lli prime = 131, tab[100005], pot[100005];
string v;

void hashing(){
    tab[0] = 0;  tab[1] = v[0];
    for(int i = 1; i < v.size(); i++)
        tab[i+1] = ((tab[i]*prime)) + v[i];
}//tab[v.size()] = hash_total

lli query(int p1, int p2){//pot[i] = prime^i
    p1--;
    return tab[p2] - tab[p1]*pot[p2-p1];
}

long long compute_hash(string const& s) {
    const int p = 131;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c + 0) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void pre(){
    pot[0] = 1;
    for(int i = 1; i <= v.size(); i++){
        pot[i] = (pot[i-1]*prime);
    }
}


int main(){
    //pre();
    string s1 = "ab";
    printf("hash = %lld\n", compute_hash(s1));
    return 0;
}


