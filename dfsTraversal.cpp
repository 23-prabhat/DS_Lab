#include <bits/stdc++.h>
using namespace std;

int adj[10][10];
bool visited[10];
int n;

void dfs(int node){
    visited[node] = true;
    cout << node << " ";
    for(int i=1; i<=n; i++)
        if(adj[node][i] == 1 && !visited[i])
            dfs(i);
}

int main(){
    n = 5;
    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[2][5] = adj[5][2] = 1;

    dfs(1);
}
