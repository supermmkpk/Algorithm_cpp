#include <bits/stdc++.h>
using namespace std;
#define N 3

/**
 * 방문한 정점 다시 X : visited!!
 * 맵 : 방향벡터!! (dy[], dx[])
 */
const int dy[] = {-1, 0, 1,  0};
const int dx[] = {0, 1,  0,  -1};
int a[N][N], visited[N][N];

void go(int y, int x) {
    visited[y][x] = 1;
    cout << y << " : " << x << '\n';
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) //오버/언더플로 방지
            continue;
        if (a[ny][nx] && visited[ny][nx] == 0) {
            go(ny, nx);
        }
        /*if(a[ny][nx] == 0) continue;
        if(visited[ny][nx]) continue;
        go(ny, nx);*/
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0);

    return 0;
}