#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

/*
 * 작성자 : 박봉균
 * 아이디어 : 알파벳 카운팅은 맵 또는 배열! -> DFS + 알파벳카운팅(방문처리)
 * 결과 : 2020KB, 424ms
 */

/* <BJ1987_G4 : 알파벳>
 * <시간제한: 2초>
 * 세로 R칸, 가로 C칸 표 모양 보드가 있다.
 * 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행1열)에는 말이 놓여 있다.
 * 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
 * 좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하시오. (말이 지나는 칸은 좌측 상단의 칸도 포함된다.)
[입력]
1) R, C. (1 ≤ R,C ≤ 20)
R개 줄) 보드 행렬 (공백 X)
[출력]
말이 지날 수 있는 최대의 칸 수
*/

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int R, C;
char matrix[24][24];
bool visited[30];
int ret = -INF;

void dfs(int y, int x, int cnt)
{
    ret = max(ret, cnt);

    for (int d = 0; d < 4; d++)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;

        if (visited[matrix[ny][nx] - 'A'] == false)
        {
            visited[matrix[ny][nx] - 'A'] = true;
            dfs(ny, nx, cnt + 1);
            visited[matrix[ny][nx] - 'A'] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> matrix[i][j];

    visited[matrix[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ret << '\n';
    return 0;
}