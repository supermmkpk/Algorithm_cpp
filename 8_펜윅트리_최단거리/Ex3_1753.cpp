#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

/*
 * 1_문자열_누적합_구현) 정점의 개수 V, 간선의 개수 E (1_문자열_누적합_구현 ≤ V ≤ 20,000, 1_문자열_누적합_구현 ≤ E ≤ 300,000). 모든 정점은 1부터 V번.
 * 2_Graph_DFS_BFS) 시작 정점 번호 K(1_문자열_누적합_구현 ≤ K ≤ V)
 * E개 줄) 각 간선을 나타내는 (u, v, w) : u에서 v로 가는 가중치 w인 간선이 존재.
          (u와 v는 서로 다르며 1_문자열_누적합_구현<= w<= 10. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음)
 * <출력> i번째 줄에 i번 정점으로 가는 최단 경로값. (시작점 자신은 0, 경로가 없는 경우, "INF")
 */

/**
 * <다익스트라>
 * priority_queue<pair<int, int>>, vector<pair<int,int>>, greater<pair<int,int>>> : 작은 거 앞에(오름차순)
 * 거리가 가장 낮은 정점 기준 : 거리 배열 갱신, 다시 큐에 push 반복
 * dist[v] > dist[u] + w 이면 갱신(dist[v] = dist[u] + w), pq.push({dist[v], v});
 * 같은 u여도 마지막 갱신 기준!! : if(dist[here] != here_dist) continue;
 */

vector<pair<int, int>> adj[20004]; //각 정점의 간선 저장. adj[u] = {가중치, v}. u --(w)--> v
int dist[20004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //작은 게 앞으로(오름차순)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int V, E;
    cin >> V >> E;
    int K;
    cin >> K;
    fill(dist, dist + 20004, INF); // 최대 -> 최소
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); //u에서 가중치 w의 v로 가는 간선. (adj[u]에 가중치, v 저장!)
    }
    pq.push({0, K}); //시작점 K, 시작점 가중치는 0
    dist[K] = 0; //시작점은 0
    while(!pq.empty()) {
        int here_dist = pq.top().first; //w
        int here = pq.top().second; //v
        pq.pop();
        if(dist[here] != here_dist) //같은 u면 마지막 갱신된 거 기준!!
            continue;
        for(pair<int, int> there : adj[here]) {
            int _dist = there.first; //w
            int _there = there.second; //v
            if(dist[_there] > dist[here] + _dist) { //_there까지 가는 거리가 짧아졌다면
                dist[_there] = dist[here] + _dist; //최소 갱신
                pq.push({dist[_there], _there}); //갱신
            }
        }
    }
    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}
