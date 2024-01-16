#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool visited[104][104];
int a[104][104];
int n = 0, m = 0;
int cnt = 0;

void dfs(int y, int x) {
    visited[y][x] = 1;
    cout << y << " : " << x << '\n';
    for(int i = 0; i < 4; i++ ) {
        int ny = y + dy[i];
        int nx = x  + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if(visited[ny][nx] == 0 && a[ny][nx]) {
            dfs(ny, nx);
        }
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    /**
     * 내가 빠트린 부분!
     * connected component
     */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] && visited[i][j] == 0) {
                cout << i << " : " << j << " [DFS가 시작됩니다.]\n";
                ++cnt;
                dfs(i, j);
            }

        }
    }

    cout << cnt<< '\n';

    return 0;
}

/*
5 5
1 0 1 0 1
1 1 0 0 1
0 0 0 1 1
0 0 0 1 1
0 1 0 0 0
 */
