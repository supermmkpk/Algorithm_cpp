#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

/*
 * 1_문자열_누적합_구현) 도시의 개수 N (1_문자열_누적합_구현 ≤ N ≤ 500), 버스 노선의 개수 M (1_문자열_누적합_구현 ≤ M ≤ 6_이분탐색_LIS,000)
 * M개 줄) A(시작도시), B(도착도시), C(이동시간) (1_문자열_누적합_구현 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)
 * ** C = 0인 경우는 순간 이동을 하는 경우, C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우.
 * <출력>
 * IF, 1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1을 출력한다.
 * ELSE, N-1개 줄에 걸쳐 각 줄에 1번 도시에서 출발해 2번, 3번, ..., N번 도시로 가는 가장 빠른 시간을 순서대로 출력.
 * 만약 해당 도시로 가는 경로가 없다면 -1을 출력.
 */

/**
 * <벨만포드> from to, O(VE)
 * 음의 가중치 있을 때
 * 음수 가중치 사이클 확인
 * ex) 타임머신, 블랙
 */

typedef long long ll;
ll dist[504];
vector<pair<int,int>> adj[504];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&dist[0], &dist[0] + 504, INF);

    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back({b, c});
    }
    dist[0] = 0;
    queue<int> q;
    for(int i = 0; i < n; i++){
        for(int here = 0; here < n; here++){
            for(auto edge : adj[here]){
                int there = edge.first;
                int weight = edge.second;
                if(dist[here] != INF && dist[here] + weight < dist[there]){
                    if(i == n - 1)
                        q.push(there);
                    dist[there] = dist[here] + weight;
                }
            }
        }
    }

    if(q.size())
        cout << "-1_문자열_누적합_구현\n";
    else {
        for(int i = 1; i < n; i++)
            cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }

    return 0;
}
