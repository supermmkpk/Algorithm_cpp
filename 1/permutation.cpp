#include <bits/stdc++.h>
using namespace std;

/**
 * 순서를 재배치하여...
 * ~한 순서의 경우 max값을
 * 순열!!
 */
int main() {
    int a[] = {2, 1, 3};
    sort(a, a + 3);

    do {
        for(int i : a)
            cout << i << " ";
        cout << '\n';
    } while(next_permutation(a, a + 3); //&a[0], &a[0] + 3) //a.begin(), a.end()
}