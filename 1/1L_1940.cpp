#include <bits/stdc++.h>
using namespace std;


/**
 * <조합>
 * 조합 3개까지는 중첩 for문
 * 시간 초과 대비해서 안 되는 거는 if문으로 배제하기!
 */
int n, m;
int a[15004];
int cnt = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //시간초과 대비! : 안 되는 경우는 배제하기!
    //(고유한 번호는 100,000보다 작거나 같은 자연수)
    if(m > 200000) {
        cout << 0 << '\n';
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] + a[j] == m) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}