#include <bits/stdc++.h>
using namespace std;

/**
 * 안전영역 => <DFS>
 * 조합 : 3개까지는 중첩 for문으로 가능.
 * 1) 무식하게 풀기 : 시간복잡도 계산, 고려
 */
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[10][10], visited[10][10];
vector<pair<int, int>> wallList; //벽 세울 수 있는 모든 빈칸
vector<pair<int, int>> virusList; //바이러스가 있는 모든 곳
int n = 0, m = 0, ret = 0;
void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) //오버, 언더
            continue;
        if(a[ny][nx] == 0 && visited[ny][nx] == 0) //0이 빈칸, 이동 가능
            dfs(ny, nx);
    }
    return;
}
int solve() {
    memset(visited, 0, sizeof(visited)); //매 경우의 수마다 초기화!! visited 오염
    for(auto v : virusList) {
        dfs(v.first, v.second); // 바이러스가 퍼진다 (dfs)
    }
    int cnt = 0; //안전 영역의 개수
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0 && visited[i][j] == 0) //바이러스가 방문 X, 벽X(빈칸) : 안전영역
                cnt++;
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0)
                wallList.push_back({i, j}); //벽 놓을 수 있는 가용 공간
            if(a[i][j] == 2)
                virusList.push_back({i, j}); //바이러스 있는 공간
        }
    }

    //조합 (3개 뽑는다)
    for(int i = 0; i < wallList.size(); i++) {
        for(int j = i + 1; j < wallList.size(); j++) {
            for(int k = j + 1; k < wallList.size(); k++) {
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve()); //모든 조합 경우의 수 중, 안전 영역 개수의 최대
                //원상 복귀!
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret << '\n';

    return 0;
}