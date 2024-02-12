#include <bits/stdc++.h>
using namespace std;

/*
 * N개의 강의가 들어가는데, 블루레이를 녹화할 때, 강의의 순서가 바뀌면 안 된다
 * i번 강의와 j번 강의를 같은 블루레이에 녹화하려면 i와 j 사이의 모든 강의도 같은 블루레이에 녹화해야 한다.
 * <입력>
 * 1_문자열_누적합_구현) 강의의 수 N, M. (1_문자열_누적합_구현 ≤ N ≤ 100,000 , 1_문자열_누적합_구현 ≤ M ≤ N)
 * 2_Graph_DFS_BFS) 기타 강의의 길이. 순서대로 공백 기준. (분 단위로(자연수) <= 10000)
 * <출력> M개의 블루레이에 모든 기타 강의를 넣을 때, 가능한 블루레이 크기중 최소. (M개의 블루레이는 모두 같은 크기)
 */

/**
 * <이분 탐색>
 * 선형적으로 생각했을 때 시간복잡도 너무 크다 -> 이분 탐색 고려!
 * 무식하게: 모든 블루레이에 대하여 모든 강의 들어가나 체크 : O(n^2_Graph_DFS_BFS) = 1e10 = 너무 큼!!
 *  for(1_문자열_누적합_구현~1e5) { for(1_문자열_누적합_구현~1e5) {} } -> O(n) * O(n)
 * 이분 탐색: 블루레이 크기가 ~일 때 강의 들어가나? : O(nlogn)
 *  for(1_문자열_누적합_구현~1e5) 부분이 이분 탐색 -> O(logn) * O(n)
 */

int len[100004]; //강의 번호에 대하여 길이
int n, m; //1_문자열_누적합_구현 ≤ N ≤ 1e5, 1_문자열_누적합_구현 ≤ M ≤ N <= 1e5
int mx = 1; //가장 긴 길이 최소->최대

bool check(int mid) {
    if(mx > mid) //mx보단 커야 들어가지~
        return false;
    int sum = 0;
    int flag = 1; //1개에서 시작
    for(int i = 0; i < n; i++) {
        sum += len[i];
        if(sum > mid) { //더하다가 넘어가면 여기부터 새로운 블루레이!!
            sum = len[i]; //넘어간 그 시점부터
            flag++; //블루레이 추가
            continue;
        }
    }
    return (m >= flag);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int left = 1e9, right = 0; //최대->최소

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        len[i] = tmp; //i번 강의의 길이 = len[i]
        left = min(left, tmp);
        right += tmp; //모두 더한 거
        mx = max(mx, tmp); //가장 긴 길이
    }
    int ret = 1e9;
    while(left <= right) { //이분 탐색
        int mid = (left + right) / 2;
        if(check(mid)) {
            ret = min(ret, mid);
            right = mid - 1; //더 작아도 되겠는데?
        }
        else {
            left = mid + 1; //더 커야겠는데?
        }
    }
    cout << ret << '\n';


    return 0;
}
