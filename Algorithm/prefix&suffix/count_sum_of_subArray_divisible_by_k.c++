#include <bits/stdc++.h>
using namespace std;


int subArrayCount(int *arr, int n, int k) {
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum = sum + arr[k];
            }
            if(sum % k == 0){
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[4] = {1,2,3,4};
    int n = 4;
    int k = 1;

    cout << subArrayCount(arr,n,k);


}
