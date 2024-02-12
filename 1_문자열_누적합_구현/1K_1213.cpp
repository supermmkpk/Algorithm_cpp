#include <bits/stdc++.h>
using namespace std;


/**
 * <카운팅>
 * char(int) 가능
 * 알파벳 카운트는 카운트 배열!!
 * 숫자 & 1_문자열_누적합_구현: 홀수 , else: 짝수
 * string.insert(index, "") : 해당 index에 추가. 해당 index부터 있었던 문자열은 추가된 바로 뒤에 이어짐.
 * "I'm Sorry Hansoo" : 이런건 실수 없게 복붙하자!
 */
string str, ret;
char mid;
int cnt[26];
int flag = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str;

    for(auto c : str) {
        cnt[c - 'A']++;
    }
    for(int i = 25; i >= 0; i--) {
        if(cnt[i]) { //카운트가 0이면 건너뛴다. 즉, 카운트가 1이상이라면
            if(cnt[i] & 1) { //홀수 개
                mid = char(i + 'A');
                flag++;
                cnt[i]--; //빼면 짝수
            }
            if(flag >= 2) { //홀수 개인 것이 2개 이상 => 팰린드롬 불가
                break;
            }
            for(int j = 0; j < cnt[i]; j += 2) { //양쪽에 추가하니까 2개씩 증가!
                ret = char(i +'A') + ret; //앞에 추가
                ret += char(i + 'A'); //<=> ret = ret + char(i + 'A');  //뒤에 추가
            }
        }
    }
    if(mid) { //mid (홀수) 있다면 가운데에
        ret.insert(ret.begin() + ret.size() / 2, mid);
    }

    if(flag >= 2) {
        cout << "I'm Sorry Hansoo\n";
    }
    else {
        cout << ret << '\n';
    }

    return 0;
}