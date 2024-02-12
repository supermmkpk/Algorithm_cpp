#include <bits/stdc++.h>
using namespace std;

/*
 * 1부터 9까지의 숫자와, 구멍이 있는 직사각형 보드
 * 먼저, 보드 가장 왼쪽 위에 동전을 하나 올려놓는다
 *  1_문자열_누적합_구현. 동전이 있는 곳의 숫자 X에 대하여
 *  2_Graph_DFS_BFS. 위, 아래, 왼, 오른 방향 중 1개 선
 *  3_완탐_백트래킹. 선택한 방향으로 X만큼 움직인다. (중간에 있는 구멍은 무시)
 * 동전이 구멍에 빠지거나, 보드의 바깥으로 나간다면 게임 종료.
 * 최대 몇 번 동전을 움직일 수 있는지 구하라!
 * <입력>
 * 1_문자열_누적합_구현) 보드의 세로 크기 N, 가로 크기 M (1_문자열_누적합_구현<= N,M <= 50)
 * N개 줄) 보드의 상태 (공백 없음) (1_문자열_누적합_구현~9 또는 H(구멍))
 * <출력> 최대 몇 번 동전을 움직일 수 있는지. (동전을 무한번 움직일 수 있다면 -1_문자열_누적합_구현)
 */

/**
 * <DP>
 * 기저 사례, 메모이제이션, 로직, 초기화
 * 방향 벡터
 * 기저사례 순서 고려!!
 */

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n; int m;
int stat[54][54], visited[54][54], dp[54][54];

int go(int y, int x) {
    // 기저사례 : 구멍/바깥(게임 종료) -> 이미 방문(사이클, 무한),
    if(stat[y][x] == -1 || y < 1 || y > n || x < 1 || x > m) {
        return 0;
    }
    if(visited[y][x] == 1) {
        cout << -1 <<'\n';
        exit(0); //main 함수까지 모두 종료
    }

    //int ret = -1e9; //시간초과
    //메모이제이션!!!
    int &ret = dp[y][x];
    if(ret)
        return ret;

    //로직
    int value = stat[y][x];
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i] * value;
        int nx = x + dx[i] * value;
        ret = max(ret, go(ny, nx) + 1);
    }
    visited[y][x] = 0; //원복

    return ret;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    memset(stat, -1, sizeof(stat)); //stat -1로 초기화 : H이면 -1_문자열_누적합_구현
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for(int j = 1; j <= m; j++) {
            if(str[j - 1] == 'H')
                continue;
            else
                stat[i][j] = (int)str[j - 1] - '0';
        }
    }
    //초기화
    memset(dp, 0, sizeof(dp));
    cout << go(1,1) << '\n';

    return 0;
}
