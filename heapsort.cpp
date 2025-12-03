#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1, r = 2*i+2;
    if(l<n && arr[l]>arr[largest]) largest = l;
    if(r<n && arr[r]>arr[largest]) largest = r;
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>=0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int arr[] = {5, 12, 11, 3, 7, 2};
    int n = 6;
    heapSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}






// python
// def heapify(arr, n, i):
//     largest = i
//     l = 2*i + 1
//     r = 2*i + 2
//     if l < n and arr[l] > arr[largest]:
//         largest = l
//     if r < n and arr[r] > arr[largest]:
//         largest = r
//     if largest != i:
//         arr[i], arr[largest] = arr[largest], arr[i]
//         heapify(arr, n, largest)

// def heap_sort(arr):
//     n = len(arr)
//     for i in range(n//2 - 1, -1, -1):
//         heapify(arr, n, i)
//     for i in range(n - 1, 0, -1):
//         arr[0], arr[i] = arr[i], arr[0]
//         heapify(arr, i, 0)

// arr = [12, 11, 13, 5, 6, 7]
// heap_sort(arr)
// print(arr)
