#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
bool visited[100];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int x : adj[node])
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    bfs(1);
}
