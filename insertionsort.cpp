#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {9, 5, 1, 4, 3};
    int n = 5;
    insertionSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}




// python:
// def insertion_sort(arr):
//     for i in range(1, len(arr)):
//         key = arr[i]
//         j = i - 1
//         while j >= 0 and arr[j] > key:
//             arr[j + 1] = arr[j]
//             j -= 1
//         arr[j + 1] = key

// arr = [9, 5, 1, 4, 3]
// insertion_sort(arr)
// print(arr)
