#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

/*
 * 주난이는 N×M크기의 학교 교실 어딘가에서 뛰기 시작했다. 주난이의 파동은 상하좌우 4방향으로 친구들을 쓰러뜨릴 때 까지 계속해서 퍼져나간다.
 * 다르게 표현해서, 한 번의 점프는 한 겹의 친구들을 쓰러뜨린다.
 * 범인을 찾기 위한 최소 점프 횟수 구하자.
[입력]
1) 교실의 크기 N, M이 주어진다. (1 ≤ N, M ≤ 300)
2) 주난이의 위치 y1, x1과 범인의 위치 y2, x2가 주어진다. (1 ≤ y1, y2 ≤ N, 1 ≤ x1, x2 ≤ M)
N개 줄) N×M 크기의 교실 정보가 주어진다. (0: 빈 공간, 1: 친구, *: 주난, #: 범인)
[출력]
범인을 잡기 위한 최소 점프 횟수
 */
const int dy[] = {-1, 0,1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, y1, x1, y2, x2, cnt;
char matrix[304][304];
int visited[304][304];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            cin >> matrix[i][j];
    }

    queue<int> q;
    q.push(1000 * y1 + x1);
    visited[y1][x1] = 1;
    while(matrix[y2][x2] != '0') { //범인 제거될 때까지
        //1이면 잠시 멈춤, cnt 증가, 다시 여기서 시작
        cnt++;
        queue<int> tmpQ;
        //0이면 계속 탐색
        while(q.size()) {
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for(int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
                    continue;
                visited[ny][nx] = cnt; //방문 체크(여기까지 점프 수)
                if(matrix[ny][nx] != '0') { //1이라면
                    matrix[ny][nx] = '0'; //0으로 바꿔주고
                    tmpQ.push(1000 * ny + nx); //tmpQ에 푸쉬
                }
                else
                    q.push(1000 * ny + nx); //0이라면 계속 bfs 탐색
            }
        }
        q = tmpQ; //시작 위치 처음에 푸쉬해주는 것과 같은 것(시작은 다시 1이었던 데부터)
    }

    cout << visited[y2][x2] << '\n';

    return 0;
}

