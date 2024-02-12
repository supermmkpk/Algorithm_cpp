#include <bits/stdc++.h>
using namespace std;

/**
 * <BFS>
 * 가중치 동일(공격 횟수의 최소)
 * 3개 상태를 가지는 정점으로 볼 수 있음. (0,0,0) 되면 종료
 * (0,0,0)의 상태까지 최단경로.
 * 입력 주의 (out of bounds)
 */

int attack[6][3] = { //공격 경우의 수
        {9, 3, 1},
        {9, 1, 3},
        {3, 9, 1},
        {1, 9, 3},
        {3, 1, 9},
        {1, 3, 9}
};

int visited[64][64][64];
struct A {
    int a, b, c;
};

int bfs(int sa, int sb, int sc) {
    visited[sa][sb][sc] = 1;
    queue<A> q;
    q.push({sa, sb, sc});
    int a, b, c;
    while(!q.empty()) {
        if(visited[0][0][0])
            break;
        a = q.front().a;
        b = q.front().b;
        c = q.front().c;
        q.pop();
        for(int i = 0; i < 6; i++) {
            int na = max(0, a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0, c - attack[i][2]);
            if(visited[na][nb][nc] == 0) {
                visited[na][nb][nc] = visited[a][b][c] + 1;
                q.push({na, nb, nc});
            }
        }
    }
    return visited[0][0][0] - 1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int in[3] = {0, 0, 0};
    for(int i = 0; i < n; i++)
        cin >> in[i];
    cout << bfs(in[0], in[1], in[2]) << '\n';

    return 0;
}