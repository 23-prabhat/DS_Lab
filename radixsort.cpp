#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n){
    int mx = arr[0];
    for(int i=1;i<n;i++) if(arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[n], count[10] = {0};
    for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i] += count[i-1];
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++) arr[i] = output[i];
}

void radixSort(int arr[], int n){
    int m = getMax(arr,n);
    for(int exp=1; m/exp>0; exp*=10)
        countSort(arr,n,exp);
}

int main(){
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    radixSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}







// python
// def counting_sort(arr, exp):
//     n = len(arr)
//     output = [0] * n
//     count = [0] * 10
//     for i in arr:
//         count[(i // exp) % 10] += 1
//     for i in range(1, 10):
//         count[i] += count[i-1]
//     for i in range(n-1, -1, -1):
//         index = (arr[i] // exp) % 10
//         output[count[index] - 1] = arr[i]
//         count[index] -= 1
//     for i in range(n):
//         arr[i] = output[i]

// def radix_sort(arr):
//     m = max(arr)
//     exp = 1
//     while m // exp > 0:
//         counting_sort(arr, exp)
//         exp *= 10

// arr = [170, 45, 75, 90, 802, 24, 2, 66]
// radix_sort(arr)
// print(arr)
