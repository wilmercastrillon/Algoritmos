#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,
    rb_tree_tag,tree_order_statistics_node_update> set_t;
//it = s.find_by_order(k); iterador al k-esimo elemento
//x = s.order_of_key(k); posicion del lower_bound de k

int main(){
    int n, k, x, q, w;

    while(scanf("%d", &n) != EOF){
        set_t s;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            s.insert(x);
        }

        set_t::iterator it;
        scanf("%d", &k);
        for(int i = 0; i < k; i++){
            scanf("%d", &x);
            it = s.find_by_order(x);
            q = s.order_of_key(x);

            printf("i-esimo elemento: %d\n", *it);
            printf("posicion del lower_bound: %d\n", q);
        }
    }
}
//find_by_order(i) devuelve iterador al i-esimo elemento
//order_of_key(k): devuelve la pos del lower bound de k
//Ej: 12, 100, 505, 1000, 10000.
//order_of_key(10) == 0, order_of_key(100) == 1,
//order_of_key(707) == 3, order_of_key(9999999) == 5
