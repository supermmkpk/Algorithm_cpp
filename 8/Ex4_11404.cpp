#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

/*
 * 1) 도시의 개수 n (2 ≤ n ≤ 100)
 * 2) 버스의 개수 m (1 ≤ m ≤ 1e5)
 * m개 줄) 시작 도시 a, 도착 도시 b, 비용 c (1 <= c <= 1e5).
 * ** 시작 도시와 도착 도시가 같은 경우는 없다, 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
 * <출력> [i][j] : i에서 j로 가는데 필요한 최소 비용. i에서 j로 갈 수 없는 경우, 0
 */

/**
 * <플로이드워셜> : 모든 쌍의 최단거리 알고리즘
 * {a,b,c} to {a,b,c}, O(V^3)
 * U -> V 가는데 경유점 거치는 게 더 빠르면, dist[u][v] 갱신!(완화)
 * 직간접 연결, 그래프 지름 확인 가능
 * N 작을 때! O(V^3)이므로...
 */

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int dist[104][104];
    fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        dist[a][b] = min(dist[a][b], c);
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); //경유하는 게 더 빠른가?
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j || dist[i][j] == INF)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
