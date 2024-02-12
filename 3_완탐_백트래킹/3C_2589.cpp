#include <bits/stdc++.h>
using namespace std;

/**
 * connected component, DFS
 */

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[54][54], visited[54][54];
int n, l, r, sum; // (1_문자열_누적합_구현 ≤ N ≤ 50, 1_문자열_누적합_구현 ≤ L ≤ R ≤ 100)
vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int, int>> &v) { // v: 인구 이동이 일어나는 좌표들
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if(l <= abs(a[ny][nx] - a[y][x])  && abs(a[ny][nx] - a[y][x]) <= r && visited[ny][nx] == 0) {
            v.push_back({ny, nx});
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for(;; cnt++) {
        //초기화
        bool flag = 0;
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    v.clear();
                    v.push_back({i, j});
                    sum = a[i][j];
                    dfs(i, j, v);
                    if (v.size() == 1)
                        continue;
                    else {
                        int avg = sum / v.size();
                        for (auto k: v) {
                            a[k.first][k.second] = avg;
                        }
                        flag = 1;
                    }
                }
            }
        }
        if(flag == 0)
            break;
    }
    cout << cnt << '\n';

    return 0;
}
