#include <bits/stdc++.h>
using namespace std;


/**
 * 카운팅은 배열 또는 맵!!
 * 문자니까 cnt[] 가능 (알파벳은 26개)
 */
int cnt[26] = {0, };
int n = 0;
string str, result;
int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        cnt[str[0]-'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(cnt[i] >= 5) {
            result += i + 'a';
        }
    }
    if(result.size()) {
        cout << result << '\n';
    }
    else {
        cout << "PREDAJA" << '\n';
    }

    return 0;
}