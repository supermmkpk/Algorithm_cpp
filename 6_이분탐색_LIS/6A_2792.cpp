#include <bits/stdc++.h>
using namespace std;

/*
 * 모든 보석을 N명의 학생들에게 나누어 주려고 한다. 이때, 보석을 받지 못하는 학생이 있어도 된다.
 * 항상 같은 색상의 보석만 가져간다.
 * 질투심은 가장 많은 보석을 가져간 학생이 가지고 있는 보석의 개수
 * <입력>
 * 1_문자열_누적합_구현) 아이들의 수 N , 색상의 수 M (1_문자열_누적합_구현 ≤ N ≤ 1e9, 1_문자열_누적합_구현 ≤ M ≤ 300,000, M ≤ N)
 * M개 줄) 구간 [1_문자열_누적합_구현, 109]에 포함되는 양의 정수가 하나씩 주어진다. K번째 줄에 주어지는 숫자는 K번 색상 보석의 개수이다.
 * <출력> 질투심의 최솟값.
 */

/**
 * <이분 탐색>
 * 무식하게: N에 대하여 다 쪼개보고 확인 : 1e9(10억)
 * 선형적으로 생각했을 때 시간복잡도 너무 크다 -> 이분 탐색 고려!
 */

typedef long long ll;

int a[300004]; //k번 색의 보석 개수
ll n;
int m;

bool check(int mid) { //질투심이 mid일때
    int num = 0;
    for(int i = 0; i < m; i++) {
        num += a[i] / mid;
        if(a[i] % mid != 0)
            num++;
    }
    return (n >= num); //최소한
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int left = 1, right = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        right = max(right, a[i]);
    }

    int ret = 1e9;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(check(mid)) {
            ret = min(ret, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ret << '\n';


    return 0;
}
