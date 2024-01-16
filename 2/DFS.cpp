#include <bits/stdc++.h>
using namespace std;

const int N = 5;
vector<int> adj[N];
bool visited[N];
void dfs(int u) {
    visited[u] = 1;
    cout << u << '\n';
    for(int v : adj[u]) {
        if(visited[v] == 0) {
            dfs(v);
        }
    }
    return;
}

/*void dfs(int u) {
    if(visited[u]) return;
    visited[u] = 1;
    cout << u << '\n';
    for(int v : adj[u]) {
        dfs(v);
    }
    return;
}*/

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    adj[1].push_back(2); adj[1].push_back(3);
    adj[2].push_back(1); adj[2].push_back(4); adj[2].push_back(5);
    adj[3].push_back(1);
    adj[4].push_back(2);
    adj[5].push_back(2);

    dfs(1);

    return 0;
}