#include <bits/stdc++.h>
using namespace std;

/**
 * 카운팅은
 * 배열 (숫자일 때) 또는
 * map (string일 때)
 */
int cnt[26] = {0, };
string str;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    for(char x : str) { //아스키 코드를 인덱스로 해서 카운트++
        cnt[x - 'a']++;
    }
    for(int i = 0; i < sizeof(cnt)/sizeof(int); i++ ) {
        cout << cnt[i] << " ";
    }

    return 0;
}
