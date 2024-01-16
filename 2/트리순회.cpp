#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1004];
int visited[1004];

void postOrder(int here){ //LRV
    if(visited[here] == 0) {
        if(adj[here].size() == 1) {
            postOrder(adj[here][0]);
        }
        else if(adj[here].size() == 2) {
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
        visited[here] = 1;
        cout << here << ' ';
    }
    return;
}

void preOrder(int here){ //VLR
    if(visited[here] == 0) {
        visited[here] = 1;
        cout << here << ' ';
        if(adj[here].size() == 1) {
            preOrder(adj[here][0]);
        }
        else if(adj[here].size() == 2) {
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
    return;
}

void inOrder(int here){ //LVR
    if(visited[here] == 0) {
        if(adj[here].size() == 1) {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << ' ';
        }
        else if(adj[here].size() == 2) {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << ' ';
            inOrder(adj[here][1]);
        }
        else {
            visited[here] = 1;
            cout << here << ' ';
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    int root = 1;
    cout << "\n 트리순회 : postOrder \n";
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : preOrder \n";
    preOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : inOrder \n";
    inOrder(root);

    return 0;
}
