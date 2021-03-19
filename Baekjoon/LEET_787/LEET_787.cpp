//Cheapest Flights Within K Steps
//https://leetcode.com/problems/cheapest-flights-within-k-stops/
//�ֱٿ� ������ ���͵𿡼� LEETCODE�� ������ �����Ͽ��� ������ LEETCODE ������ Ǯ���Ͽ���

typedef pair<int, pair<int, int>> pipii;
class Solution {
    const int INF = 987654321;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int i, ans = 0;
        vector<pair<int, int>> graph[101];
        for (i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back({ flights[i][1],flights[i][2] }); // �׷��� ����
        }

        vector<int> dist(n, INF);
        dist[src] = 0;

        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push({ -1,{0,src} }); // {stops , cost , current node} ���� 
        // stops�� �ִ� K�ȿ� �ִܰ�θ� ���ؾ��ϱ⶧���� stops�� ���������� �켱����ť�� �������־���

        while (!pq.empty()) {
            int d = pq.top().second.first;
            int curr = pq.top().second.second;
            int stops = pq.top().first;
            pq.pop();

            if (stops == K) continue; // �߰��� ������ ������ K�� �̻��̸� �ȵǱ⶧���� continue�� ó��


            for (i = 0; i < graph[curr].size(); i++) {
                int next = graph[curr][i].first;
                int cost = d + graph[curr][i].second;
                if (cost < dist[next]) { // �� ª�� �Ÿ��Ͻ� ����
                    dist[next] = cost;
                    pq.push({ stops + 1,{cost,next} });
                }
            }
        }

        cout << dist[dst]; 

        return dist[dst] == INF ? -1 : dist[dst]; // �� �� ���� ��ζ��(INF) -1 ���
    }
};