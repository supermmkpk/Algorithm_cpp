#include <bits/stdc++.h>
using namespace std;

/*
 수열 A에 대하여, 가장 긴 증가하는 부분 수열을 구하시오.
[입력]
1) 수열 A 크기 N. (1 ≤ N ≤ 1e6)
2) 수열 A 원소 Ai. (-1e9 ≤ Ai ≤ 1e9)
[출력]
1) LIS 길이
2) LIS 출력
 */
int N, A[1000004];
pair<int, int> check[1000004];
vector<int> lis, v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    //초기화
    int cnt = 0;
    lis.push_back(A[0]);
    check[0] = {A[0], 0};
    for(int i = 1; i < N; i++) {
        if(lis.back() < A[i]) { //증가하면 그냥 넣기
            lis.push_back(A[i]);
            check[i] = {A[i], ++cnt}; //순서 기록
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin(); //넣을 곳 찾기
            lis[idx] = A[i];
            check[i] = {A[i], idx}; //순서 기록
        }
    }

    cout << cnt + 1 << '\n';

    for(int i = N - 1; i >= 0; i--) { //뒤에서 부터 순차적으로
        if(cnt == check[i].second) { //순서 체크
            v.push_back(check[i].first);
            cnt--;
        }
    }

    for(int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
    cout << '\n';

    return 0;
}
