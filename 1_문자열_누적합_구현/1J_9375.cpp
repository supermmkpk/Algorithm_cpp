#include <bits/stdc++.h>
using namespace std;

/**
 * 경우의 수: 커질 수 있으니까 long long
 * 곱하기
 */
typedef long long ll;
int t = 0, n = 0;
string name, type;
ll ret = 1;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++) { //while(t--) 도 가능.
        map<string, int> mp; //테스트 케이스마다 새로 만들어야!
        ret = 1; //테스트 케이스마다 초기화!

        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> name >> type;
            mp[type]++;
        }
        for(auto m : mp) {
            ret *= (m.second + 1); //+1은 안 입는 경우
        }
        ret--; //아무것도 안 입는 경우

        cout << ret << '\n';
    }

    return 0;
}