#include <bits/stdc++.h>
using namespace std;

/*
 * 1_문자열_누적합_구현) 아이들의 수 N , 색상의 수 M (1_문자열_누적합_구현 ≤ N ≤ 1e9, 1_문자열_누적합_구현 ≤ M ≤ 300,000, M ≤ N)
 * 다음 M개 줄) 해당 색상 보석의 개수 (1_문자열_누적합_구현 <= <= 1e9)
 * <출력> 질투심의 최솟값.
 */

/**
 * <이분 탐색>
 */

typedef long long ll;

ll ret = 1e18; // 촤대 -> 최소
ll n, m;

bool check(ll mid, vector<ll> &v) { //이분탐색
    ll num = 0;
    for (auto eachV: v) {
        num += eachV / mid;
        if(eachV % mid)
            num++;
    }
    return n >= num; // 아이들 수보다 작거나 같으면 가능!!
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> m;
    vector<ll> v(m);
    ll hi = 0, lo = 1; //hi: 최소 -> 최대
    for(ll i = 0; i < m; i++) {
        cin >> v[i];
        hi = max(hi, v[i]);
    }
    //이분탐색
    sort(v.begin(), v.end());
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        //질투심을 mid로 했을때 가능한가?
        if(check(mid, v)) { //mid에 대하여, 가능하면 더 작게
            ret = min(ret, mid);
            hi = mid - 1;
        }
        else { //안 되면 더 크게
            lo = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}
