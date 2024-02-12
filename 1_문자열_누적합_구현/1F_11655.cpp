#include <bits/stdc++.h>
using namespace std;

/**
 * A는 65, a는 97, 알파벳은 26개
 * 그러면 당연히 Z: 90, z: 122
 * 대문자, 소문자 로직 나눠서: 13 더한 게 넘어가면 -26해서 순환!
 * getline(cin, string) : 공백 포함 한 줄 입력 받기
 */
string str = "";
int main(void) {
    getline(cin, str);

    for(int i = 0; i < str.length(); i++) {
        //A는 65, a는 97
        if(str[i] >= 65 && str[i] <= 90) {
            if(str[i] + 13 > 90) { //범위 넘어가면 -26 (순환)
                str[i] = str[i] + 13 - 26;
            }
            else {
                str[i] += 13;
            }
        }
        else if(str[i] >= 97 && str[i] <= 122) {
            if(str[i] + 13 > 122) { //범위 넘어가면 -26 (순환)
                str[i] = str[i] + 13 - 26;
            }
            else {
                str[i] += 13;
            }
        }
    }
    cout << str << '\n';

    return 0;
}