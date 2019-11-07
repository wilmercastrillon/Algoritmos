#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define mod 1000000000000LL;

lli prime = 573573, tab[100005], pot[100005];
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

lli compute_hash(string &s){//Hash
    lli res = 0;
    for(int i = 0; i < s.size(); i++)
        res = ((res*prime)) + s[i];
    return res;
}

void pre(){
    pot[0] = 1;
    for(int i = 1; i <= v.size(); i++){
        pot[i] = (pot[i-1]*prime);
    }
}


int main(){
    //pre();
    string s1 = "hola mundo";
    printf("hash = %lld\n", compute_hash(s1));
    return 0;
}


