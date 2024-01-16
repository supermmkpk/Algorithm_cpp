#include <bits/stdc++.h>
using namespace std;

/*
 * 1) 수열 A의 크기 N (1 ≤ N ≤ 1,000)
 * 2) Ai (1 ≤ Ai ≤ 1,000), M ≤ N)
 * <출력> 최대 증가 부분 수열의 길이.
 */

/**
 * <LIS : 최대 증가 부분 수열>
 * cnt[i] = a[i]보다 작은 애들 중, cnt 최댓값 +1
 * cnt 최대가 최대 증가 부분 수열의 길이.
 */

int a[1004], cnt[1004];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ret = -987654321; // 최소 -> 최대
    for(int i = 0; i < n; i++) {
        int maxVal = 0;
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && maxVal < cnt[j])
                maxVal = cnt[j];
        }
        cnt[i] = maxVal + 1;
        ret = max(ret, cnt[i]);
    }
    cout << ret << '\n';

    return 0;
}

