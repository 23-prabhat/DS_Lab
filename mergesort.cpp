#include <bits/stdc++.h>
using namespace std;

void mergeArr(int arr[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int a[n1], b[n2];
    for(int i=0;i<n1;i++) a[i]=arr[l+i];
    for(int i=0;i<n2;i++) b[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }
    while(i<n1) arr[k++] = a[i++];
    while(j<n2) arr[k++] = b[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        mergeArr(arr,l,m,r);
    }
}

int main(){
    int arr[] = {8, 3, 5, 1, 9, 6};
    int n = 6;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}







// python
// def merge_sort(arr):
//     if len(arr) > 1:
//         mid = len(arr)//2
//         L = arr[:mid]
//         R = arr[mid:]
//         merge_sort(L)
//         merge_sort(R)
//         i = j = k = 0
//         while i < len(L) and j < len(R):
//             if L[i] < R[j]:
//                 arr[k] = L[i]
//                 i += 1
//             else:
//                 arr[k] = R[j]
//                 j += 1
//             k += 1
//         while i < len(L):
//             arr[k] = L[i]
//             i += 1
//             k += 1
//         while j < len(R):
//             arr[k] = R[j]
//             j += 1
//             k += 1

// arr = [8, 3, 5, 1, 9, 6]
// merge_sort(arr)
// print(arr)
