#include <bits/stdc++.h>u
using namespace std;

int partitionArray(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partitionArray(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[] = {9, 4, 7, 3, 1, 6};
    int n = 6;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}





// python
// def quick_sort(arr, low, high):
//     if low < high:
//         p = partition(arr, low, high)
//         quick_sort(arr, low, p-1)
//         quick_sort(arr, p+1, high)

// def partition(arr, low, high):
//     pivot = arr[high]
//     i = low - 1
//     for j in range(low, high):
//         if arr[j] < pivot:
//             i += 1
//             arr[i], arr[j] = arr[j], arr[i]
//     arr[i+1], arr[high] = arr[high], arr[i+1]
//     return i+1

// arr = [9, 4, 7, 3, 1, 6]
// quick_sort(arr, 0, len(arr)-1)
// print(arr)
