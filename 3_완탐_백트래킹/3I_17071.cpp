#include <bits/stdc++.h>
using namespace std;
#define MAX 500000

int visited[2][MAX + 4], N, K;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    if(N == K) {
        cout << 0 << '\n';
        return 0;
    }

    //BFS - 가중치 1_문자열_누적합_구현
    queue<int> q;
    visited[0][N] = 1;
    q.push(N);

    int sec = 1;
    int sister = K;
    int ok = 0;
    while(q.size()) {
        sister += sec;
        if(sister > MAX) {
            break;
        }
        //이미 방문 했고, 초(턴)과의 홀짝이 맞다면
        if (visited[sec % 2][sister]) {
            ok = 1;
            break;
        }
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int x = q.front();
            q.pop();

            for (int nx : {x + 1, x - 1, x * 2}) {
                if (nx < 0 || nx > MAX || visited[sec % 2][nx])
                    continue;
                visited[sec % 2][nx] = visited[(sec + 1) % 2][x] + 1;
                if (nx == sister) {
                    ok = 1;
                    break;
                }
                q.push(nx);
            }
            if(ok)
                break;
        }
        if(ok)
            break;
        sec++;
    }

    if(ok) {
        cout << sec << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}

