#include <bits/stdc++.h>
using namespace std;

const int V = 10;
vector<int> adj[V];
bool visited[V];

void go(int from) {
    visited[from] = 1;
    cout << from << '\n';
    for(int i : adj[from]) {
        if(visited[i])
            continue;
        go(i);
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    adj[1].push_back(2); adj[1].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(1); adj[3].push_back(4);
    adj[4].push_back(3);

    for(int i = 0; i < V; i++) {
        /*for(int j : adj[i]) {  // 2 1 3 4
            if(visited[j] == 0) {
                go(j);
            }
        }*/
        if(adj[i].size() && visited[i] == 0) {
            go(i);
        }
    }

    return 0;
}
