#include<bits/stdc++.h>
using namespace std;

//typedef long long ll; //(1 <= N <= 1000000000)이니까 int(10^9) 가능은 함

/**
 * 1. 무식하게 접근해보기
 * 2. 범위가 너무 넓어서 팩토리얼 직접 구할 수 없다.
 * => idea! : 승수 개념, 0의 개수 = 10의 개수 = 2*5 의 개수 = min(2개수, 5개수).
 * 전체 개수는 각 (/ n ^ k) 의 합과 같다!
 */
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) { ///테케: 초기화 주의!
        int ret2 = 0, ret5 = 0; // 2, 5의 개수. 이 중 min이 10의 개수
        int n;
        cin >> n;
        for(int i = 2; i <= n ; i *= 2) {
            ret2 += n / i;
        }
        for(int i = 5; i <= n ; i *= 5) {
            ret5 += n / i;
        }

        cout << min(ret2, ret5) << '\n';
    }

    return 0;
}

