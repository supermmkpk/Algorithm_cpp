#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[104][104], visited[104][104];
vector<pair<int, int>> c; //치즈 경계 좌표들
int n, m;

void dfs(int y, int x) {
    visited[y][x] = 1;
    if(a[y][x] == 1) {//치즈가 있어! (경계)
        c.push_back({y, x});
        return;
    }
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if(visited[ny][nx] == 0)
            dfs(ny, nx);
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

    int ret1 = 0, ret2 = 0; //ret1: 걸리는 시간, ret2: 다 녹기 전 치즈 크기
    while (1) {
        memset(visited, 0, sizeof(visited));
        c.clear();
        dfs(0, 0); //경계선 좌표들 찾아서 c에 넣기
        ret2 = c.size();
        for(auto i : c) {
            a[i.first][i.second] = 0;
        }
        bool cheese = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] != 0)
                    cheese = true;
            }
        }
        ret1++;
        if(cheese == false) //치즈 없으면 1도 없으니까
            break;
    }

    cout << ret1 << '\n';
    cout << ret2 << '\n';

    return 0;
}
