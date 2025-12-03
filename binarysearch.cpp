#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
    int arr[] = {2, 5, 8, 12, 16, 23, 38};
    int n = 7, key = 16;
    cout << binarySearch(arr, n, key);
}





// python
// def binary_search(arr, key):
//     l, r = 0, len(arr) - 1
//     while l <= r:
//         mid = (l + r) // 2
//         if arr[mid] == key:
//             return mid
//         elif arr[mid] < key:
//             l = mid + 1
//         else:
//             r = mid - 1
//     return -1

// arr = [2, 5, 8, 12, 16, 23, 38]
// print(binary_search(arr, 16))

