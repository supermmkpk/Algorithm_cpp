
#include <bits/stdc++.h>
using namespace std;

/**
 * <DFS>
 * 테스트 케이스 문제는 초기화 중요!!! while(t--)
 * 최단경로 x, connected component => DFS!
 * if(존재 && 방문X) dfs 호출; <-여기서 connected component 개수 카운트!
 * visited = 1_문자열_누적합_구현; 각 방향에 대하여: 오버 언더 체크; if(존재&&방문X) dfs(재귀);
 */
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, cnt = 0;
int a[54][54], visited[54][54];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0 ; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if(a[ny][nx] && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, nPos; // nPos: 배추 위치 개수
    cin >> t;
    while(t--) {
        //초기화!!
        n = 0; m = 0; cnt = 0, nPos = 0;
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));

        cin >> n >> m >> nPos;
        for(int i = 0; i < nPos; i++) {
            int tmpY, tmpX;
            cin >> tmpY >> tmpX;
            a[tmpY][tmpX] = 1;
        }

        ///connected component
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] && visited[i][j] == 0) {
                    ++cnt;
                    dfs(i,j);
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
