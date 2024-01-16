#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[104][104], visited[104][104], n, m;
queue<pair<int,int>> q;

void bfs(int sy, int sx) {
    visited[sy][sx] = 1;
    q.push({sy, sx});
    while(!q.empty()) {
        //tie(y,x) = q.front();
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            //= if(ny < 0 || ny >= n || nx < 0 || nx >= m) =//
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            //= a[ny][nx] =//
            if(a[ny][nx] && visited[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int startY, startX, destY, destX;

    cin >> n >> m >> startY >> startX >> destY >> destX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    bfs(startY, startX);
    cout << visited[destY][destX] << '\n';

    // 최단거리 디버깅
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*
5 5
0 0
4 4
1 0 1 0 1
1 1 1 0 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
 */