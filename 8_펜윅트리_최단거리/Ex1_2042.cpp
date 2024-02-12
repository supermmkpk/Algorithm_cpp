#include <bits/stdc++.h>
using namespace std;

/*
 * 1_문자열_누적합_구현) N, M(수의 변경이 일어나는 횟수), K(구간합 구하는 횟수) (1_문자열_누적합_구현 ≤ N ≤ 1_문자열_누적합_구현,000,000 , 1_문자열_누적합_구현 ≤ M ≤ 10,000 , 1_문자열_누적합_구현 ≤ K ≤ 10,000)
 * N개줄) 숫자 (-2_Graph_DFS_BFS^63 <= <= 2_Graph_DFS_BFS^63 - 1_문자열_누적합_구현)
 * ~N+M+K+1줄) a==1_문자열_누적합_구현 : b(1_문자열_누적합_구현 ≤ b ≤ N)번째 수를 c로 바꾸고, a==2_Graph_DFS_BFS : b(1_문자열_누적합_구현 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합을 구하여 출력
 * <출력> K줄에 걸쳐 구간의 합을 출력 (-2_Graph_DFS_BFS^63 <= <= 2_Graph_DFS_BFS^63 - 1_문자열_누적합_구현)
 */

/**
 * <펜윅 트리>
 * idx & -idx
 * 누적합처럼 생각
*/
typedef long long ll;
vector<ll> v;
vector<ll> tree;

void update(ll idx, ll diff) {
    while(idx < tree.size()) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

ll sum(ll idx) {
    ll ret = 0;
    while(idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    v = vector<ll> (n + 1);
    tree = vector<ll> (n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        update(i, v[i]);
    }

    for(int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if(a == 1) { // update
            ll diff = c - v[b];
            v[b] = c;
            update(b, diff);
        }
        else if (a == 2) { // sum
            cout << (sum(c) - sum(b - 1)) << '\n';
        }
    }

    return 0;
}
