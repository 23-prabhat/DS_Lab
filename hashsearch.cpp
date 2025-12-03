#include <bits/stdc++.h>
using namespace std;

#define SIZE 10
int hashTable[SIZE];

int hashFunc(int key){
    return key % SIZE;
}

void insertKey(int key){
    int i = hashFunc(key);
    while(hashTable[i] != 0)
        i = (i + 1) % SIZE;
    hashTable[i] = key;
}

int searchKey(int key){
    int i = hashFunc(key);
    int start = i;
    while(hashTable[i] != 0){
        if(hashTable[i] == key) return i;
        i = (i + 1) % SIZE;
        if(i == start) break;
    }
    return -1;
}

int main(){
    insertKey(23);
    insertKey(43);
    insertKey(13);
    insertKey(27);

    cout << searchKey(43);
}




// python
// SIZE = 10
// hash_table = [None] * SIZE

// def hash_func(key):
//     return key % SIZE

// def insert_key(key):
//     i = hash_func(key)
//     while hash_table[i] is not None:
//         i = (i + 1) % SIZE
//     hash_table[i] = key

// def search_key(key):
//     i = hash_func(key)
//     start = i
//     while hash_table[i] is not None:
//         if hash_table[i] == key:
//             return i
//         i = (i + 1) % SIZE
//         if i == start:
//             break
//     return -1

// insert_key(23)
// insert_key(43)
// insert_key(13)
// insert_key(27)

// print(search_key(43))
