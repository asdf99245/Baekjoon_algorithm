//�ִ� ���
//https://www.acmicpc.net/problem/1753

#include <cstdio>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[20001];

void dijkstra(int start, int V) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // �� ª����θ� �켱���� ����
	vector<int> dist(V + 1, INF);

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int d = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (d > dist[curr]) continue; // �̹� üũ �ߴٸ� ��ŵ

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int cost = d + graph[curr][i].second;

			if (cost < dist[next]) { // �� ª�� ��ΰ� �ִٸ� ����
				dist[next] = cost;
				pq.push({ cost,next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] ==  INF) //�����Ҽ� ����
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}

int main() {
	int V, E, K, u, v, w;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({ v,w });
	}

	dijkstra(K,V);
	return 0;
}