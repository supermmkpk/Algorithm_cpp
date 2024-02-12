#include <bits/stdc++.h>
using namespace std;

/**
 * 트리에서의 DFS
 */
int visited[100004];
vector<int> adj[1000004];

int dfs(int here) {
    visited[here] = 1;
    int ret = 1;
    for(auto there : adj[here]) {
        if(visited[there] == 0) {
            ret += dfs(there); //방문할 수 있는 정점 개수 다 더하기(해킹 가능 컴퓨터 수)
        }
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a); //b를 해킹하면 -> a 해킹 => 트리 구조 완성
    }

    int dp[100004], mx; //가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호 한 개 이상일 수도 있으니까
    for(int i = 1; i <= n; i++) { //n보다 작거나 같은 자연수!
        //visited 오염되자너!!! => 초기화!!
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx); // 해킹 가능 컴퓨터 수의 최대
    }
    for(int i = 1; i <= n; i++) {
        if(dp[i] == mx)
            cout << i << " ";
    }

    return 0;
}
