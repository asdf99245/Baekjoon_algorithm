//Ư���� �ִܰ��
//https://www.acmicpc.net/problem/1504

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 800
#define INF 987654321
using namespace std;

int N, E, v1, v2;
vector<pair<int, int>> graph[MAX + 1];

int dijkstra(int from, int to) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(N + 1, INF);
	int i;
	pq.push({ 0,from }); 
	dist[from] = 0;

	while (!pq.empty()) {
		int d = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (d > dist[curr]) continue; // �̹� Ȯ���� ����̸� ��ŵ

		for (i = 0; i < graph[curr].size(); i++) {
			int cost = d + graph[curr][i].second;
			int next = graph[curr][i].first;
			if (cost < dist[next]) { // �� ª�� ��θ� ã�Ҵٸ� �����ϰ� ť�� ����
				pq.push({ cost,next });
				dist[next] = cost;
			}
		}
	}

	return dist[to];
}

int main() {
	int i, j;
	scanf("%d %d", &N, &E);
	for (i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	scanf("%d %d", &v1, &v2);

	// �� ���� ��ΰ� ���� : ( 1 => v1 => v2 => N ), ( 1 => v2 => v1 => N )
	// ������ �κа�ο� ���� �ִܰ�θ� ���Ͽ�(���ͽ�Ʈ�� �̿�) �����ذ��� ����� ����
	int v1_v2 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
	int v2_v1 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
	int ans = min(v1_v2, v2_v1); 

	// INF�� �̻��Ͻÿ� ��ΰ� �������� �ʴ´� 
	if (ans >= INF || ans < 0) // �ִ� INF * 3�� ���� �Ǳ� ������ overflow�߻��� ������ ��
		printf("-1");
	else 
		printf("%d", ans);

	return 0;
}