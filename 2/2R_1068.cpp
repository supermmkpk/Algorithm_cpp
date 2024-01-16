#include <bits/stdc++.h>
using namespace std;

/**
 * <트리에서의 DFS>
 * 루트부터!
 * here, there
 * 각 부모에 대하여 child를 담고 있는 adj 이차원 백터
 */
vector<int> adj[54];
int erase;
int dfs(int here) {
    int ret = 0, child = 0;
    for(auto there : adj[here]) {
        if(there == erase)
            continue; //지울 노드면 그냥 탐색을 하지 않는다
        ret += dfs(there); //하나씩 더해서 올라감
        child++;
    }
    if(child == 0) //child 없으면 리프노드
        return 1;
    else
        return ret;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int root;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == -1)
            root = i;
        else
            adj[tmp].push_back(i); //tmp의 자식 i <=> i의 부모 tmp
    }
    cin >> erase;

    if(erase == root) //지울 노드가 루트노드(0)이면 남아있는 노드는 없음(0 출력)
        cout << 0 << '\n';
    else
        cout << dfs(root) << '\n';

    return 0;
}