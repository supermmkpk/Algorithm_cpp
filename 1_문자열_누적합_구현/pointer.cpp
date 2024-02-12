#include <bits/stdc++.h>
using namespace std;

/**
 * 포인터의 크기는 고정돼 있다
 * 64비트: 8바이트, 32비트: 4바이트
 */
double a = 4.4;
int c = 10;
int main() {
    double *b = &a;
    int *d = &c;
    cout << sizeof(b) << '\n';
    cout << sizeof(d) << '\n';

    return 0;
}
