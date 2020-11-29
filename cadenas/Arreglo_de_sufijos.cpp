#include <bits/stdc++.h>
#define forr(i,n) for(int i = 0; i < n; ++i)
#define forab(i,a,b) for(int i = a; i < b; ++i)

using namespace std;

#define maxn 100100
char cad[maxn];
int c[maxn];
int len_cad, len_subcad;//len t, len p
int ra[maxn], temp_ra[maxn], sa[maxn], temp_sa[maxn];

void countingSort(int k){
    int aux, may = max(300,len_cad);
    memset(c,0,sizeof(c));
    for(int i = 0; i < len_cad; ++i)
        c[(i+k<len_cad)? ra[i+k] : 0]++;
    for(int i = 0, sum = 0; i < may; ++i){
        aux = c[i];
        c[i] = sum;
        sum += aux;
    }
    for(int i = 0; i < len_cad; ++i)
        temp_sa[c[(sa[i]+k<len_cad)?
            ra[sa[i]+k] : 0]++] = sa[i];
    for(int i = 0; i < len_cad; ++i) sa[i] = temp_sa[i];
}

void construir_SA(){//hasta 10^5 caracteres
    strcat(cad,"$");
    len_cad = strlen(cad);

    int r;
    for(int i = 0; i < len_cad; ++i){
        ra[i] = cad[i];
        sa[i] = i;
    }
    for(int k = 1; k < len_cad; k<<=1){
        countingSort(k);
        countingSort(0);
        temp_ra[sa[0]] = r = 0;
        for(int i = 1; i < len_cad; ++i)
            temp_ra[sa[i]]=(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k])?
                r: ++r;
        for(int i = 0; i < len_cad; ++i) ra[i] = temp_ra[i];
        if(ra[sa[len_cad-1]]==len_cad-1) break;
    }
}

int phi[maxn], plcp[maxn], lcp[maxn];
void LCP(){
    phi[sa[0]] = -1;
    for(int i = 1; i < len_cad; ++i) phi[sa[i]] = sa[i-1];
    for(int i = 0, l = 0; i < len_cad; ++i){
        if(phi[i]==-1){
            plcp[i] = 0;
            continue;
        }
        while(cad[i+l]==cad[phi[i]+l] && cad[i+l]!='$') l++;
        plcp[i] = l;
        l = max(l-1,0);
    }
    for(int i = 0; i < len_cad; ++i)
        lcp[i] = plcp[sa[i]];
}//lcp[i] = maximo prefijo en sa[i].

char subcad[maxn];
vector<string> LCS(){
    int l = strlen(cad), best = -1;
    strcat(cad,"."); strcat(cad,subcad); strcat(cad,"$");
    construir_SA();  LCP();
    string aux;  set<string> ss;  vector<string> res;

    for(int i = 0; i < len_cad; ++i){
        if(lcp[i] < best) continue;
        if((sa[i]>l && sa[i-1]>l) || (sa[i]<l&&sa[i-1]<l) || lcp[i]<1)
            continue;

        aux = "";
        for(int j=0; j<lcp[i]; ++j)
            aux.push_back(cad[sa[i]+j]);
        if(lcp[i]>best){
            best = lcp[i];
            ss.clear();
            ss.insert(aux);
        }else if(lcp[i]==best) ss.insert(aux);
    }
    res.assign(ss.begin(),ss.end());
    return res;
}

ii stringMatching() {
    len_subcad = strlen(subcad);
    int lo = 0, hi = len_cad-1, mid = lo;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(cad + sa[mid], subcad, len_subcad);
        if (res >= 0) hi = mid;
        else lo = mid + 1;
    }
    if (strncmp(cad + sa[lo], subcad, len_subcad) != 0)
        return ii(-1, -1);
    ii ans; ans.first = lo;
    lo = 0;  hi = len_cad - 1;  mid = lo;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(cad + sa[mid], subcad, len_subcad);
        if (res > 0) hi = mid;
        else lo = mid + 1;
    }
    if (strncmp(cad + sa[hi], subcad, len_subcad) != 0) hi--;
    ans.second = hi;
    return ans;
}

int main(){

    while(scanf("%s", &cad) != EOF){
        construir_SA();
        LCP();

        forr(i,len_cad){
            printf("%2d | SA %2d | lcp %2d | %s\n", i, sa[i], lcp[i], cad+sa[i]);
        }
        printf("\n");
    }

    return 0;
}


