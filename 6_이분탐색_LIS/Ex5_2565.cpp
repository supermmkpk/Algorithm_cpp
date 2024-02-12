#include <bits/stdc++.h>
using namespace std;

/*
 * 1_문자열_누적합_구현) 두 전봇대 사이의 전깃줄의 개수 n (0 < n <= 100)
 * 2_Graph_DFS_BFS~) 각 줄에 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호 (번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다)
 * <출력> 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수
 */

/**
 * <LIS : 최대 증가 부분 수열>
 * pair(A, B) 정렬하면 B에 대하여, { 8_펜윅트리_최단거리, 2_Graph_DFS_BFS, 9, 1_문자열_누적합_구현, 4_비트마스킹, 6_이분탐색_LIS, 7_DP, 10}
 * B에 대하여 LIS 구하면 { 1_문자열_누적합_구현, 4_비트마스킹, 6_이분탐색_LIS, 7_DP, 10}
 * 따라서 {4_비트마스킹,1_문자열_누적합_구현}, {6_이분탐색_LIS,4_비트마스킹}, {7_DP,6_이분탐색_LIS}, {9,7_DP}, {10,10}  (OK)!
 * <출력> = n - (LIS 길이)  Q.E.D
 */

vector<pair<int, int>> v;
int cnt[104];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b}); // a <-> b 전깃줄
    }
    sort(v.begin(), v.end());
    int len = -987654321; //최소 -> 최대
    for(int i = 0; i < n; i++) {
        int maxVal = 0;
        for(int j = 0; j < i; j++) {
            if(v[j].second < v[i].second && maxVal < cnt[j])
                maxVal = cnt[j];
        }
        cnt[i] = maxVal + 1;
        len = max(len, cnt[i]);
    }
    cout << (n - len) << '\n';

    return 0;
}