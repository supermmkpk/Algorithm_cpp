#include <bits/stdc++.h>
using namespace std;

int toSec(string s) { // 주어진 시간 초로 통일
    int del = s.find( ":");
    int min = stoi(s.substr(0, del));
    int sec = stoi(s.substr(del + 1));

    return min * 60 + sec;
}
string toMin(int x) {
    int m = x / 60;
    int s = x % 60;

    string sec, min;
    if(s < 10)
        sec = "0" + to_string(s);
    else
        sec = to_string(s);
    if(m < 10)
        min = "0" + to_string(m);
    else
        min = to_string(m);

    return min + ":" + sec;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int t, prev = 0;
    int A = 0, B = 0, Asum = 0, Bsum = 0;
    for (int i = 0; i < n; i++) {
        int team; string s;
        cin >> team >> s;
        t = toSec(s);

        if(A > B)
            Asum += (t - prev);
        else if(B > A)
            Bsum += (t - prev);
        (team == 1) ? ++A : ++B;
        prev = t;
    }
    if(A > B)
        Asum += 2880 - t;
    else if(B > A)
        Bsum += 2880 - t;

    cout << toMin(Asum) << '\n';
    cout << toMin(Bsum) << '\n';

    return 0;
}
