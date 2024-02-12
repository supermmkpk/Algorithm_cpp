#include <bits/stdc++.h>
using namespace std;


/**
 * 시간!! => ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 * atoi(string.c_str()): 문자열이면 0, 숫자면 숫자 그대로 => 0이면 ㄴㄴ
 * string->int : map: O(logn), 배열: O(n)
 * int->string: map: O(logn), 배열: O(1_문자열_누적합_구현)
 * O(logn) 와 O(1_문자열_누적합_구현)은 별 차이 없다!
 * 하나의 자료구조로 하면 양방향으로 해야 하는데 그러면 시간 오래 걸림
 * 따라서, 자료구조 2개 사용!
 */
string arr[100004];
int n, m;
string str, given;
map<string, int> mp;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        mp[str] = i + 1;
        arr[i + 1] = str;
    }
    for(int i = 0; i < m; i++) {
        cin >> given;
        if(atoi(given.c_str()) == 0) { //문자열이면 0
            cout << mp[given] << '\n';
        }
        else {
            cout << arr[atoi(given.c_str())] << '\n';
        }
    }

    return 0;
}