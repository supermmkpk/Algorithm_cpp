#include<bits/stdc++.h>
using namespace std;

/**
 * <범위 조건 잘 보기!!>
 * 숫자로 하면 런타임 에러
 * 최대 100글자 이므로 int(10^9), long long(10^18) 등 숫자로 안됨 -> 문자열로 해야...
 * 문자열은 아스키 코드 기반으로 정렬 => 커스텀 정렬 : cmp
 */
vector<string> ret;
string num;

void go() {
    for(; num.size() && num[0] == '0'; num.erase(num.begin())) {} // 0 없애기
    if(num.size() == 0) //0 없애서 비면, 0
        num = "0";
    ret.push_back(num);
    num = "";
}

bool cmp(string a, string b) {
    if(a.size() == b.size())
        return a < b;

    return a.size() < b.size();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;

        num = "";
        for(int i = 0; i < str.length(); i++) { //숫자 찾기
            if(str[i] < 65) //숫자
                num += str[i];
            else if(num.size()) {
                go();
            }
        }
        if(num.size())
            go();
    }
    sort(ret.begin(), ret.end(), cmp);
    for(auto r : ret) {
        cout << r << '\n';
    }

    return 0;
}