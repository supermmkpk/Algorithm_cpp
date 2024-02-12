#include <bits/stdc++.h>
using namespace std;

/*
 * 1_문자열_누적합_구현) 수열 A의 크기 N (1_문자열_누적합_구현 ≤ N ≤ 1_문자열_누적합_구현,000)
 * 2_Graph_DFS_BFS) Ai가 주어진다. (1_문자열_누적합_구현 ≤ Ai ≤ 1_문자열_누적합_구현,000)
 * <출력>
 * 1_문자열_누적합_구현) 수열 A의 최대 증가 부분 수열의 길이
 * 2_Graph_DFS_BFS) 최대 증가 부분 수열을 출력 (여러가지인 경우, 아무거나)
 */

/**
 * <LIS : 최대 증가 부분 수열>
 * lower_bound 사용
 */

int  a[1004], lis[1004], len = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    memset(lis, 0, sizeof(lis));
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        //lower_bound : 정렬! , 정렬해 가면서 진행
        auto idx = lower_bound(lis, lis + len, ai);
        if(*idx == 0) //정렬해 가면서 진행
            len++;
        *idx = ai;
    }
    cout << len << '\n';
    for(int i = 0; i < len; i++) {
        cout << lis[i] << " ";
    }
    cout << '\n';

    return 0;
}
