#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100];
bool visited[100];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int x : adj[node])
        if (!visited[x]) dfs(x);
}

int main() {
    int n = 5;

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    dfs(1);
}
