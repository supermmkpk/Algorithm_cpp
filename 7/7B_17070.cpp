#include <bits/stdc++.h>
using namespace std;

/*
 * 집: N × N, 각 칸 = (행, 열). 행과 열의 번호는 1부터 시작한다. 각각의 칸은 빈 칸이거나 벽이다.
 * 파이프는 항상 빈 칸만 차지해야 한다.
 * 밀 수 있는 방향은 총 3가지가 있으며, →, ↘, ↓
 * 가로: 2가지, 세로: 2가지, 대각선: 3가지
 * 처음에 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로일때, 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.
 * <입력>
 * 1) 집의 크기 N. (3 ≤ N ≤ 16)
 * N개 줄) 집 상태. (빈 칸: 0, 벽: 1). (1, 1)과 (1, 2)는 항상 빈 칸이다.
 * <출력> 한쪽 끝을 (N, N)로 이동시키는 방법의 수. 이동시킬 수 없는 경우에는 0. (방법의 수 <= 1e6)
 */

/**
 * <DP>
 * 기저사례, 메모이제이션, 로직, 초기화
 * 경우의 수는 더하기
 * 경우의 수 채워가기
 */

int house[20][20];

bool check(int i, int j, int dir) {
    if(dir == 0 || dir == 2) {
        if(house[i][j] == 0)
            return true;
    }
    else if(dir == 1) {
        if(house[i][j] == 0 && house[i - 1][j] == 0 && house[i][j - 1] == 0)
            return true;
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> house[i][j];
        }
    }

    //메모이제이션
    int dp[20][20][3]; // (y, x, dir) 가로:0, 대각:1, 세로:2
    //초기화
    memset(dp, 0, sizeof(dp));
    //기저사례
    dp[1][2][0] = 1;
    //로직 : 경우의 수 채워가기
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // → , ↘ 일때: → 가능, 벽 긁음? (check)
            if(check(i, j + 1, 0)) {
                dp[i][j + 1][0] += dp[i][j][0];
                dp[i][j + 1][0] += dp[i][j][1];
            }
            // → , ↘ , ↓ 일때: ↘ 가능, 벽 긁음? (check)
            if(check(i + 1, j + 1, 1)) {
                dp[i + 1][j + 1][1] += dp[i][j][0];
                dp[i + 1][j + 1][1] += dp[i][j][1];
                dp[i + 1][j + 1][1] += dp[i][j][2];
            }

            // ↘, ↓ 일때: ↓ 가능, 벽 긁음? (check)
            if(check(i + 1, j, 2)) {
                dp[i + 1][j][2] += dp[i][j][1];
                dp[i + 1][j][2] += dp[i][j][2];
            }
        }
    }
    int ret = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << ret << '\n';

    return 0;
}
