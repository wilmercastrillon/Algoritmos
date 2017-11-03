#include <stdio.h>
#include <vector>

using namespace std;

int arr[] = {15, 1, 29, 5, 28, 10, 84, 99};

int LIS(){
    int res = 0;
    vector<int> vec(8, 1);

    for(int i = 0; i < 8; i++){
        for(int j = i + 1; j < 8; j++)
            if(arr[i] < arr[j]) vec[j] = max(vec[j], vec[i] + 1);
        res = max(res, vec[i]);
    }

    return res;
}

int main(){

    printf("%d\n", LIS());

    return 0;
}
