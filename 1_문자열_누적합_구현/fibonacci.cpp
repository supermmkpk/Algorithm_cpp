#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
    if(n==1 || n==0) //기저 조건(종료 조건)!!!
        return 1;
    return n * fact(n - 1);
}

int fact1(int n) {
    int ret = 1;
    for (int i = 0; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int fibo(int n) {
    cout << "fibo: "<< n << '\n';
    if(n==0 || n==1)
        return n;
    return fibo(n-1) + fibo(n-2);
}
int n = 4;
int main() {
    cout << fibo(n) << '\n';
    return 0;
}