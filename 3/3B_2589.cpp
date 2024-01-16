#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

char a[54][54];
int visited[54][54];
int n, m;
int mx;

/**
 * <BFS>
 * 보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다.
 * => 최단 거리 중 max!
 * => <BFS>
 * visited = 1, q, push, while, front/pop, 오버/언더, visited==0이면 visited = visited + 가중치, push
 */
void bfs(int sy, int sx) {
    memset(visited, 0, sizeof(visited));
    visited[sy][sx] = 1;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    int y, x;
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (a[ny][nx] != 'W' && visited[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
                mx = max(mx, visited[ny][nx]);
            }
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
    int mn = 987654321;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'L')
                bfs(i, j);
        }
    }
    cout << mx - 1 << '\n';

    return 0;
}
