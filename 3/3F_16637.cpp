#include <bits/stdc++.h>
using namespace std;

/**
 * 완탐은 idx 기반!!
 */
vector<char> op;
vector<int> num;

int calc(char o, int x, int y) {
    switch(o) {
        case '+' :
            return x + y;
        case '-' :
            return x - y;
        case '*' :
            return x * y;
    }
}

int ret = -987654321; //최소 -> 최대
void go(int here, int n) { //현재 인덱스, 숫자
    if(here == num.size() - 1) {
        ret = max(n, ret);
        return;
    }
    go(here + 1, calc(op[here], n, num[here + 1])); //앞에거

    if(here + 2 <= num.size() - 1) { //뒤에거
        int temp = calc(op[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, calc(op[here], n, temp));
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //수식 길이 N(1 ≤ N ≤ 19)
    cin >> n;
    string str;
    cin >> str;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {//짝수는 숫자
            num.push_back(str[i] - '0');
        }
        else {//홀수면 연산자 (+, -, *)
            op.push_back(str[i]);
        }
    }

    go(0, num[0]);
    cout << ret << '\n';

    return 0;
}
