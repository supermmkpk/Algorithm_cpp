#include <bits/stdc++.h>
using namespace std;
#define prev aaaa
/*
 * 수빈이는 걷거나 순간이동. 위치가 X일 때,  걷는다 : 1초 후, X-1 또는 X+1로 이동. 순간이동 : 1초 후, 2*X로 이동.
 * 1)수빈이가 있는 위치 N(0 ≤ N ≤ 100,000), 동생이 있는 위치 K(0 ≤ K ≤ 100,000) (N과 K는 정수)
 * <출력>
 * 1) 동생을 찾는 가장 빠른 시간
 * 2) 어떻게 이동해야 하는지 공백으로 구분해 출력
 */

/**
 * <BFS>
 * 테스트케이스 반례 생각! : 테케가 다른 값으로 주어지면 같은 값, 중간값으로 주어지면 상한/하한
 */

int visited[100004];
int prev[100004];
int ret;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;


    visited[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == k) {
            ret = visited[k];
            break;
        }
        for(int next : {now - 1, now + 1, now * 2}) {
            if(next < 0 || next > 100000) { //오버 언더
                continue;
            }
            if(visited[next] == 0) {
                visited[next] = visited[now] + 1;
                q.push(next);
                prev[next] = now;
            }
        }
    }
    vector<int> v;
    for(int i = k; i != n; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());

    cout << ret - 1 << '\n';
    for(auto eachV : v) {
        cout << eachV << " ";
    }
    cout << '\n';

    return 0;
}
