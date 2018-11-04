#include <stdio.h>
#include <math.h>

using namespace std;

#define MAX 1000 //n
#define Log2 10 //2^10 > 1000

struct sparseTable{
    int arr[MAX], spt[MAX][Log2] = {0};

    sparseTable(int n, int a[]){
        for(int i = 0; i < n; i++){
            arr[i] = a[i];
            spt[i][0] = i;
        }

        for(int j = 1; (1<<j) <= n; j++){
            for(int i=0; i+(1<<j)-1 < n; i++)
                if(arr[spt[i][j-1]] < arr[spt[i+(1<<(j-1))][j-1]])
                    spt[i][j] = spt[i][j-1];
                else
                    spt[i][j] = spt[i+(1<<(j-1))][j-1];
        }
    }

    int query(int i, int j){//de i hasta j, index desde 0
        int k = (int) floor(log(((j-i+1)*1.0))/log(2.0));
        if(arr[spt[i][k]] <= arr[spt[j-(1<<k)+1][k]])
            return spt[i][k];
        else return spt[j-(1<<k)+1][k];
    }
};

int main(){

    int a[] = {0, 1, 2, 1, 2, 3, 2, 3, 2, 1, 2, 1, 0, 1, 2, 1, 2, 1};
    sparseTable st(18, a);
    //st.imp();

    int q, w, index;
    while(scanf("%d %d", &q, &w) != EOF){
        index = st.query(q, w);
        printf("index = %d | num = %d\n", index, a[index]);
    }

    return 0;
}


