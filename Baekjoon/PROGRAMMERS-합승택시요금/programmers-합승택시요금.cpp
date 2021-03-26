//�ս��ýÿ��
//https://programmers.co.kr/learn/courses/30/lessons/72413

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[201];

vector<int> dijkstra(int start, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    int i;

    pq.push({ 0,start });
    dist[start] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (d > dist[curr]) continue;

        for (i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i].first;
            int cost = d + graph[curr][i].second;
            if (cost < dist[next]) {
                dist[next] = cost;
                pq.push({ cost,next });
            }
        }
    }

    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int i;
    for (i = 0; i < fares.size(); i++) {
        int a = fares[i][0];
        int b = fares[i][1];
        int c = fares[i][2];
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    vector<int> fromStart = dijkstra(s, n); // s���� �ٸ����������� �ִܰ��
    vector<int> fromA = dijkstra(a, n); // A���� �ٸ����������� �ִܰ��
    vector<int> fromB = dijkstra(b, n); // ���� �ٸ����������� �ִܰ��

    answer = INF;
    for (i = 1; i <= n; i++) {
        if (fromStart[i] == INF || fromA[i] == INF || fromB[i] == INF) // ��ΰ� ���� ��� 
            continue;
        int cost = fromStart[i] + fromA[i] + fromB[i]; // (s => i) + ((i=>A) + (i=>B)) �� ��ε��� ����
        if (cost < answer) answer = cost;
    }

    return answer;
}