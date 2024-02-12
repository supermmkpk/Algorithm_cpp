#include <bits/stdc++.h>
using namespace std;

/**
 * 순열로 풀기
 * 각 순열에서 7개 slice해서 합이 100이면 출력
 */

int a[9] = {0,};
int main() {
    for(int i = 0; i < 9; i++) {
        cin >> a[i];
    }

    sort(a, a+9);
    do {
        int sum = 0;
        for(int i = 0; i < 7; i++) { //7개 슬라이스 해서 합 100인 애 고르기
            sum += a[i];
        }
        if(sum == 100) {
            break;
        }
    } while(next_permutation(a, a+9));

    for(int i = 0; i < 7; i++) {
        cout << a[i] << '\n';
    }

    return 0;
}


/**
 * 조합으로 풀기
 * 전체 - A - B == 100  where A, B 는 가짜
 */

int a[9], sum;
vector<int> v;
pair<int, int> ret;

void solve() {
    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 9; j++) {
            if(sum - a[i] - a[j] == 100) { //전체 - 가짜 = 100(진짜)
                ret = {i, j};
                return; //가짜 조합 찾으면 return
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i]; //전체 합 구하기
    }
    solve();
    for(int i = 0; i < 9; i++) {
        if(ret.first == i || ret.second == i) //가짜 빼고
            continue;
        v.push_back(a[i]); //진짜만 넣기
    }
    sort(v.begin(), v.end()); //오름차순으로 출력한다!
    for(int i : v) {
        cout << i << '\n';
    }

    return 0;
}


/**
 * 재귀로 풀기
 */

int a[9];
int n = 9, r = 7, sum = 0;

void solve() {
    sum = 0;
    for(int i = 0; i < r; i++) {
        sum += a[i];
    }
    if(sum == 100) {
        sort(a, a + 7);
        for(int i = 0; i < r; i++) {
            cout << a[i] << '\n';
        }
        exit(0); //sum == 100인 상황 2번 이상일 수 있으므로 아예 프로그램 종료
    }
}

//== 이정도는 외우기 ==//
void makePermutation(int n, int r, int depth) {
    if(r == depth) { //종료조건!!
        solve();
        return;
    }
    for(int i = depth; i < n; i++) {
        swap(a[i], a[depth]);
        makePermutation(n, r, depth+1);
        swap(a[i], a[depth]);
    }
    return;
}

int main() {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    makePermutation(n, r, 0);

    return 0;
}
