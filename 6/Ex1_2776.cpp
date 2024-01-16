#include <bits/stdc++.h>
using namespace std;

/*
 * 1) 테스트케이스의 개수 T
 * 2) 수첩 1에 적어 놓은 정수의 개수 N (1 ≤ N ≤ 1,000,000)
 * 3) 수첩 1에 적혀 있는 정수들
 * 4) 수첩 2에 적어 놓은 정수의 개수 M(1 ≤ M ≤ 1,000,000)
 * 5) 수첩 2에 적어 놓은 정수들
 * ** 모든 정수들의 범위는 int
 * <출력> 수첩2에 적혀있는 M개의 숫자 순서대로, 수첩1에 있으면 1, 없으면 0.
 */

/**
 * <이분 탐색>
 * binary search 는 sorted array!!
 */

bool search(int tmp, vector<int> &v) { //binary search
    int l = 0, r = v.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(tmp < v[mid]) {
            r = mid - 1;
        }
        else if(tmp > v[mid]) {
            l = mid + 1;
        }
        else if(tmp == v[mid]) {
            return true;
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        //초기화!!
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n ; i++)
            cin >> v[i];
        sort(v.begin(), v.end()); // binary search 는 sorted array!!
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;
            if(search(tmp, v))
                cout << "1\n";
            else
                cout << "0\n";
        }
    }

    return 0;
}