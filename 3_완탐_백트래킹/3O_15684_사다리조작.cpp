#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

/**
 * 사다리 게임: N개의 세로선과 M개의 가로선이 있다.
 * 인접한 세로선 사이에는 가로선을 놓을 수 있는데, 각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수는 H이고, 모든 세로선이 같은 위치를 갖는다.
 * 가로선은 인접한 두 세로선을 연결해야 한다. 단, 두 가로선이 연속하거나 서로 접하면 안 된다.
 * 사다리에 가로선을 추가해서, i번 세로선의 결과가 i번이 나오기 위해 추가해야 하는 가로선의 최소 개수를 구하시오.
[입력]
1) 세로선 수 N, 가로선 수 M, 가로선을 놓을 수 있는 위치 수 H. (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
M개 줄) 가로선의 정보 a, b. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) (b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미)
가로 점선 번호: 위부터 1~, 세로선: 왼쪽부터 1~
[출력]
i번 세로선의 결과가 i번이 나오도록 추가해야 하는 가로선 개수의 최솟값. (정답이 3보다 큰 값,불가능한 경우: -1)
*/

int ret = INF;
int N, M, H;
bool visited[34][14]; // a 가로선으로 b -- b+1 잇는 선 있는지

bool check()
{
    // 1~N번 세로줄에 대하여
    for (int i = 0; i <= N; i++)
    {
        int start = i;
        for (int j = 0; j < H; j++)
        {
            if (visited[j][start])
                start++;
            else if (visited[j][start - 1])
                start--;
        }
        if (start != i)
            return false;
    }
    // 모두 OK
    return true;
}

void go(int now, int cnt)
{
    if (cnt > 3 || cnt >= ret)
        return;
    if (check()) // 가능하면(i->i) 최소 갱신
        ret = min(ret, cnt);

    // 완탐, 백트래킹
    for (int i = now; i <= H; i++) // 1~H번에 대하여 탐색
    {
        for (int j = 1; j < N; j++) // 1~N-1번 세로선에 대하여 탐색
        {
            // 연속으로 이어지는지 체크
            if (visited[i][j - 1] || visited[i][j] || visited[i][j + 1])
                continue;
            visited[i][j] = true;
            go(i, cnt + 1);
            visited[i][j] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        visited[a][b] = true;
    }

    go(1, 0); // 1번 위치부터 놓으면서 완탐/백트래킹

    cout << ret;

    return 0;
}