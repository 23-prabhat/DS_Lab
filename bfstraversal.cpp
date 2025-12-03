#include<bits/stdc++.h>
using namespace std;

int adj[10][10];
bool visited[10];
int n;

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=1; i<=n; i++)
            if(adj[node][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
    }
}

int main(){
    n = 5;
    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[2][5] = adj[5][2] = 1;

    bfs(1);
}



// python
// from collections import deque

// def bfs(adj, start):
//     n = len(adj)
//     visited = [False] * n
//     q = deque([start])
//     visited[start] = True
//     while q:
//         node = q.popleft()
//         print(node, end=" ")
//         for i in range(n):
//             if adj[node][i] == 1 and not visited[i]:
//                 visited[i] = True
//                 q.append(i)

// adj = [
//     [0,1,1,0,0],
//     [1,0,1,1,0],
//     [1,1,0,0,1],
//     [0,1,0,0,1],
//     [0,0,1,1,0]
// ]

// bfs(adj, 0)
