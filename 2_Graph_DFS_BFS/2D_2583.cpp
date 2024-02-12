#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa


/**
 * connected component => <DFS>
 * DFS 재귀를 int 자료형으로 구현해서 누적을 구할 수도 있다.
 * x,y 좌표로 주어질 때, 그대로 진행하되 배열에 저장 시 y,x  Ex)a[y][x]
 * y1과 같이 <bits/stdc++.h>의 예약어일 수 있으니 관련 오류 시, #define y1 aaaa 같이 대처
 */
const int dy[] = {-1,0,1, 0};
const int dx[] = {0,1,0, -1};

int m, n;
int a[104][104], visited[104][104];
vector<int> ret; //각 connected component의 넓이(size) 저장할 벡터

int dfs(int y, int x) {
    int size = 1; //넓이
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= m ||nx < 0 || nx >= n) //오버, 언더 처리
            continue;
        if(a[ny][nx] == 0 && visited[ny][nx] == 0) { //색칠 안 돼 있는 데 찾기!!
            size += dfs(ny, nx); ///찾을 때마다 1씩 더하기 = 넓이 누적
        }
    }
    return size;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k; //직사각형 수
    int x1, y1, x2, y2;

    cin >> m >> n >> k;

    //직사각형 색칠
    /**
     * 좌표계로 주어지면 x,y 그대로 하되
     * 배열로 저장할 때는 a[y][x]
     */
    while(k--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++) {
            for(int y = y1; y < y2; y++) {
                a[y][x] = 1;
            }
        }
    }

    //connected component
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 0 && visited[i][j] == 0) {//색칠 안 돼 있는 데 찾기!!
                ret.push_back(dfs(i,j)); //각 connected component의 넓이 push_back
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for(auto i : ret) {
        cout << i << " ";
    }

    return 0;
}
