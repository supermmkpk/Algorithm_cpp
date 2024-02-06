#include <bits/stdc++.h>
using namespace std;

/*
 * 현우는 N일 동안 사용할 금액을 계산하였고, M번만 통장에서 돈을 빼서 쓰기로 하였다.
 * K원을 인출하며(고정), 이것으로 하루를 보낼 수 있으면 그대로 사용하고, 모자라면 남은 금액은 통장에 넣고 다시 K원 인출.
 * 현우는 정확히 M번을 맞추기 위해서 남은 금액이 그날 사용할 금액보다 많더라도 남은 금액을 통장에 집어넣고 다시 K원을 인출할 수 있다.
 * 필요한 최소 금액 K를 계산하라.
[입력]
1) N, M. (1 ≤ N ≤ 1e5, 1 ≤ M ≤ N)
N개 줄) i번째 날에 이용할 금액. (1 ≤ 금액 ≤ 10000)

[출력]
통장에서 인출해야 할 최소 금액 K.
 */

/**
 * 이분 탐색
 */

typedef long long ll;

ll mx, lo, hi, mid, money[10004], N, M, ret;

bool check(ll mid) {
    ll cnt = 1; //인출 카운트
    ll K = mid; //인출 금액 K

    for(int i = 0; i < N; i++) {
        if(mid - money[i] < 0) { //가능하지 않으면
            mid = K; //인출
            cnt++; //인출 카운트 증가
        }
        //다시 돈 쓰기
        mid -= money[i];
    }
    return (cnt <= M);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    mx = 987654321;
    for(int i = 0; i < N; i++) {
        cin >> money[i];
        mx = max(mx, money[i]);
    }

    lo = mx;
    hi = 1000000004;
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if(check(mid)) { //가능! : 더 작은 금액은?
            hi = mid - 1;
            ret = mid;
        }
        else { //불가! : 더 큰 금액에서 재탐색
            lo = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}
