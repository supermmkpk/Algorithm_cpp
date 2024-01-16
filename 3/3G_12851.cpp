#include <bits/stdc++.h>
using namespace std;
/*
 * 수빈이는 걷거나 순간이동. 위치가 X일 때,  걷는다 : 1초 후, X-1 또는 X+1로 이동. 순간이동 : 1초 후, 2*X로 이동.
 * 1)수빈이가 있는 위치 N(0 ≤ N ≤ 100,000), 동생이 있는 위치 K(0 ≤ K ≤ 100,000) (N과 K는 정수)
 * <출력>
 * 1) 동생을 찾는 가장 빠른 시간
 * 2) 가장 빠른 시간으로 동생을 찾는 방법의 수
 */

/**
 * <BFS>
 */

int visited[100004];
int cnt[100004];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    //BFS
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        if(now == m) {
            break;
        }
        q.pop();
        for(int next : {now - 1, now + 1, now * 2}) {
            if(next < 0 || next > 100000)
                continue;
            if(visited[next] == 0) {
                visited[next] = visited[now] + 1;
                q.push(next);
                cnt[next] += cnt[now];
            }
            else if(visited[next] == visited[now] + 1) {
                cnt[next] += cnt[now];
            }
        }
    }

    cout << visited[m] - 1 << '\n';
    cout << cnt[m] << '\n';


    return 0;
}
