#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

int main(){
    int arr[] = {5, 2, 9, 1, 6};
    int n = 5;
    bubbleSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}




// python
// def bubble_sort(arr):
//     n = len(arr)
//     for i in range(n-1):
//         for j in range(n-i-1):
//             if arr[j] > arr[j+1]:
//                 arr[j], arr[j+1] = arr[j+1], arr[j]

// arr = [5, 2, 9, 1, 6]
// bubble_sort(arr)
// print(arr)
