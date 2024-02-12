#include <bits/stdc++.h>
using namespace std;

/**
 * BJ1987 : 알파벳
 * <비트마스킹>
 * 세로 R칸, 가로 C칸의 표 모양 보드가 있다. 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 1행 1열에는 말이 놓여 있다.
 * 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
 * 말이 최대한 몇 칸을 지날 수 있는지 구하라. (단, 좌측 상단의 칸도 포함.)
 *
[입력]
1_문자열_누적합_구현) R <공백> C. (1_문자열_누적합_구현 ≤ R,C ≤ 20)
R개 줄) C개의 대문자 알파벳들이 빈칸 없이 주어진다.

[출력]
말이 지날 수 있는 최대의 칸 수.
 */
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

char board[24][24];
int R, C, ret;

void go(int sy, int sx, int status, int cnt) {
    ret = max(ret, cnt);
    for(int d = 0; d < 4; d++) {
        int ny = sy + dy[d];
        int nx = sx + dx[d];
        //오버 언더 체크
        if(ny < 0 || nx < 0 || ny >= R || nx >= C)
            continue;
        int nextVal = 1 << (int)(board[ny][nx] - 'A');
        if((nextVal & status) == 0) {
            go(ny, nx, status | nextVal, cnt + 1); //++cnt는 cnt를 변경시킴. 매개변수로 보낼 때 주의!!
            //++cnt 하면 for문 더 도는 경우 cnt가 오염된 상태로 진행됨!! 즉, 1이 더해진 오염된 상태로 진행됨...
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    go(0, 0, 1 << (int)(board[0][0] - 'A'), 1);

    cout << ret << '\n';

    return 0;
}