//Find the City With the Smallest Number of Neighbors at a Threshold Distance
//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
private:
    const int INF = 987654321;
    int graph[100][100];

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int res = 0;
        init(n);

        for (int i = 0; i < edges.size(); i++) { // 그래프 생성
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];
            graph[u][v] = graph[v][u] = cost;
        }

        floyd(n); // 플로이드 와샬 - 모든 집에서의 다른 집으로의 최단경로 구함

        int minN = 101;
        for (int i = n - 1; i >= 0; i--) { 
            int neighbor = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (graph[i][j] <= distanceThreshold) { // threshold 이하의 거리를 가진 이웃의 수를 구함
                    neighbor++;
                }
            }
            if (neighbor < minN) { // 더 작은 이웃을 가진 집을 저장
                res = i;
                minN = neighbor;
            }
        }

        return res;
    }
    void init(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                graph[i][j] = INF;
            }
        }
    }
    void floyd(int n) {
        int i, j, k;
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (graph[i][k] + graph[k][j] < graph[i][j])
                        graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
};