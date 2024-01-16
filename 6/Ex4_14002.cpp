#include <bits/stdc++.h>
using namespace std;

/*
 * 1) 수열 A의 크기 N (1 ≤ N ≤ 1,000)
 * 2) Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
 * <출력>
 * 1) 수열 A의 최대 증가 부분 수열의 길이
 * 2) 최대 증가 부분 수열을 출력 (여러가지인 경우, 아무거나)
 */

/**
 * <LIS : 최대 증가 부분 수열>
 * cnt[i] = a[i]보다 작은 애들 중, cnt 최댓값 +1
 * cnt 최대가 최대 증가 부분 수열의 길이.
 */

int a[1004], cnt[1004], prevList[1004];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력, 초기화
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(prevList, -1, sizeof(prevList));

    //LIS : cnt[i] = a[i]보다 작은 애들 중 cnt 최대 +1
    int ret = -987654321; //최소 -> 최대
    int retIdx = 0;
    for(int i = 0; i < n; i++) {
        int maxVal = 0, lastJ = 0;
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && maxVal < cnt[j]) {
                maxVal = cnt[j];
                lastJ = j;
            }
        }
        cnt[i] = maxVal + 1;
        prevList[i] = lastJ;
        if(ret < cnt[i]) { //ret = max(ret, cnt[i]);
            ret = cnt[i];
            retIdx = i; //Trace Back 위해...
        }
    }
    cout << ret << '\n'; //LIS 길이

    //Trace Back : 스택!
    stack<int> stk;
    int idx = retIdx;
    for(int i = 0; i < ret; i++) {
        stk.push(a[idx]);
        idx = prevList[idx];
    }
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << '\n';

    return 0;
}
