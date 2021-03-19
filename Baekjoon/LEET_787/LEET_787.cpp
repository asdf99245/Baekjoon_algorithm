//Cheapest Flights Within K Steps
//https://leetcode.com/problems/cheapest-flights-within-k-stops/
//최근에 시작한 스터디에서 LEETCODE의 문제를 출제하였기 때문에 LEETCODE 문제를 풀이하였다

typedef pair<int, pair<int, int>> pipii;
class Solution {
    const int INF = 987654321;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int i, ans = 0;
        vector<pair<int, int>> graph[101];
        for (i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back({ flights[i][1],flights[i][2] }); // 그래프 생성
        }

        vector<int> dist(n, INF);
        dist[src] = 0;

        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push({ -1,{0,src} }); // {stops , cost , current node} 순서 
        // stops가 최대 K안에 최단경로를 구해야하기때문에 stops가 작은순으로 우선순위큐에 정렬해주었다

        while (!pq.empty()) {
            int d = pq.top().second.first;
            int curr = pq.top().second.second;
            int stops = pq.top().first;
            pq.pop();

            if (stops == K) continue; // 중간에 존재한 노드들이 K개 이상이면 안되기때문에 continue로 처리


            for (i = 0; i < graph[curr].size(); i++) {
                int next = graph[curr][i].first;
                int cost = d + graph[curr][i].second;
                if (cost < dist[next]) { // 더 짧은 거리일시 갱신
                    dist[next] = cost;
                    pq.push({ stops + 1,{cost,next} });
                }
            }
        }

        cout << dist[dst]; 

        return dist[dst] == INF ? -1 : dist[dst]; // 갈 수 없는 경로라면(INF) -1 출력
    }
};