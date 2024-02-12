#include <bits/stdc++.h>
using namespace std;

/**
 * 배열의 이름 = 주소값
 * 정적 배열만 가능
 */
 int a[3] = {1,2,3};
int main() {
    int *c = a;
    cout << c << '\n';
    cout << &a[0] << '\n';
    cout << c + 1 << '\n';
    cout << &a[1] << '\n';

    return 0;
}
