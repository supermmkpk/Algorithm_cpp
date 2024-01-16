#include <bits/stdc++.h>
using namespace std;

/*
 * <입력>
 * 1) 도로의 개수 N(5 ≤ N ≤ 1,000)
 * 2) 사건의 개수 W(1 ≤ W ≤ 1,000)
 * W개 줄) 사건 발생 위치.(주어진 순서대로 처리. 좌표: delimeter=공백. 두 사건이 발생한 위치가 같을 수 있다.)
 * <출력>
 * 1) 두 경찰차가 이동한 총 거리
 * W개 줄) i번째(1 ≤ i ≤ W) 사건이 맡겨진 경찰차 번호(1 or 2)
 */

/**
 * <DP>
 * 기저사례, 메모이제이션, 로직, 초기화
 */

int px[1004], py[1004]; //사건 발생 좌표
int dp[1004][1004];
int n, w;

int dist(int a, int b) {
    return abs(py[a] - py[b]) + abs(px[a] - px[b]);
}

int getSum(int a, int b) {
    //기저사례
    if(a == w + 1 || b == w + 1)
        return 0;

    //메모이제이션
    if(dp[a][b])
        return dp[a][b];

    //로직
    int next = max(a, b) + 1; //둘 중 큰 게 사건
    return dp[a][b] = min(getSum(a, next) + dist(b, next), getSum(next, b) + dist(a, next));
}
void solve() {
    int a = 0, b = 1;
    for(int i = 2; i < w + 2; i++) {
        if(dp[i][b] + dist(a, i) < dp[a][i] + dist(b, i)) {
            cout << 1 << '\n';
            a = i;
        }
        else {
            cout << 2 << '\n';
            b = i;
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> w;

    //초기화 (경찰차1: 0 : 0,0 / 경찰차2: 1 : n,n)
    px[0] = 1; py[0] = 1;
    px[1] = n; py[1] = n;
    for(int i = 2; i < w + 2; i++) {
        cin >> py[i] >> px[i];
    }

    cout << getSum(0,1) << '\n';
    solve();

    return 0;
}
