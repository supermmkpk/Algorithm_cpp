#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

/**
 * 최단 거리 => <BFS>
 */
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m;
char a[1004][1004];
int visitedF[1004][1004], visitedJ[1004][1004];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sy, sx, y, x;
    int ret = 0;
    queue<pair<int, int>> q;

    cin >> n >> m;
    /**
     * 불이 아예 없을 수도 있다는 반례!!
     * 0이 아닌 INF로 초기화!
     */
    fill(&visitedF[0][0], &visitedF[0][0] + 1004 * 1004, INF);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'F') {
                visitedF[i][j] = 1;
                q.push({i, j});
            }
            else if(a[i][j] == 'J') {
                sy = i;
                sx = j;
            }
        }
    }

    //불의 최단거리
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if(a[ny][nx] != '#' && visitedF[ny][nx] == INF) {
                visitedF[ny][nx] = visitedF[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    //지훈의 최단거리 (불보다 짧아야).
    visitedJ[sy][sx] = 1;
    q.push({sy, sx});
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        if(y == 0 || y == n - 1 || x == 0 || x == m - 1) { //가장자리 도달 시, 탈출 성공.
            ret = visitedJ[y][x];
            break;
        }
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if(a[ny][nx] != '#' && visitedJ[ny][nx] == 0 && visitedJ[y][x] + 1 < visitedF[ny][nx]) {
                visitedJ[ny][nx] = visitedJ[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    if(ret != 0)
        cout << ret << '\n';
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}

