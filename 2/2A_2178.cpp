#include <bits/stdc++.h>
using namespace std;

/**
 * <BFS>
 * 최단경로 => BFS
 * 가중치가 한 칸으로 모두 같다! => BFS
 * 좌표계와 방향벡터! dy[],dx[], (y,x)
 * BFS는 큐 사용!
 * (y,x)는 pair<int,int>로 표현
 * visited = 1; push; while(q.size()) { front; pop; 오버,언더 체크; if(존재&&방문X) push, visited+가중치; }
 * 붙여서 입력 받을 때: scanf("%1d") 또는 string으로 받아서 쪼개기
 * scanf 사용시 ios::sync_with_stdio(false) 사용 금지!
 */
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m;
int a[104][104], visited[104][104], x, y;
queue<pair<int, int>> q;

void bfs(int sy, int sx) {
    visited[sy][sx] = 1;
    q.push({sy, sx}); ///
    while(q.size()) { ///
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (a[ny][nx] && visited[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1; //가중치 한칸
                q.push({ny, nx});
            }
        }
    }
    return;
}

int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    /*string temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        for(int j = 0; j < m; j++) {
            a[i][j] = temp[j] - '0';
        }
    }*/

    bfs(0,0);
    cout << visited[n-1][m-1] << '\n';

    return 0;
}
