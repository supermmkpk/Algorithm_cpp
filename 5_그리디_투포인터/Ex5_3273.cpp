#include <bits/stdc++.h>
using namespace std;

/*
 * 1_문자열_누적합_구현) 수열의 크기 n (1_문자열_누적합_구현 ≤ n ≤ 100000)
 * 2_Graph_DFS_BFS) 수열에 포함되는 수 (1_문자열_누적합_구현 <=  <= 1000000 인 자연수)
 * 3_완탐_백트래킹) x (1_문자열_누적합_구현 ≤ x ≤ 2000000)
 * <출력> ai + aj = x (1_문자열_누적합_구현 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 개수
 */

/**
 * <투포인터> : 양 끝에서 출발,sort 후에,
 * l++ : 숫자 커짐
 * r-- : 숫자 작아짐
 */

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n); //수열 (~1e6)
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int x;
    cin >> x;

    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    int ret = 0;
    while(l < r) {
        if(v[l] + v[r] == x) { //찾았다
            ret++;
            r--;
        }
        else if(v[l] + v[r] < x) { // 더 작다 : l++ : 숫자 커져
            l++;
        }
        else if(v[l] + v[r] > x) { // 더 크다 : r-- : 숫자 작아져
            r--;
        }
    }
    cout << ret << '\n';

    return 0;
}
