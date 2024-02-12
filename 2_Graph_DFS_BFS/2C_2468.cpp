#include <bits/stdc++.h>
using namespace std;

/**
 * connected component => <DFS>
 * 기준에 맞춰서 해주면 됨 Ex) a[ny][nx] > d
 * 초기화 신경 쓰기!!
 * 꼭 반대의 경우도 생각하기! Ex) 비가 아예 안 올 수도 있다.
 */
const int dy[] = { -1, 0, 1, 0};
const int dx[] = { 0, 1, 0, -1};
int n = 0;
int a[104][104], visited[104][104];
int d;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if(a[ny][nx] > d && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cnt = 0, ret = 1; ///비가 안 올 수도 있다!!

    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(d = 1; d < 101; d++) {
        // 초기화!
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        //connected component
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > d && visited[i][j] == 0) {
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret << '\n';

    return 0;
}
