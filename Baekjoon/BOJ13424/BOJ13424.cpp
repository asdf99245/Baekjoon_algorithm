//��� ����
//https://www.acmicpc.net/problem/13424

#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

int n, m;
//vector<pair<int, int>> graph[101];

vector<int> dijkstra(int start, int n, vector<pair<int,int>> graph[101]) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(n + 1, INF);
	int i;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (d > dist[curr]) continue; // �̹� �� ª�� ��ΰ� ����

		for (i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int cost = d + graph[curr][i].second;
			if (cost < dist[next]) { // �� ª�� ����Ͻ� ����
				dist[next] = cost;
				pq.push({ cost,next });
			}
		}
	}

	return dist; // �ִܰ�� �迭 ��ȯ
}

int getMeetingRoom(int n,vector<vector<int>> &dists) {
	int i, j, minCost = INF, ret = 0;

	// 1 ~ n��° ���� ������ҷ� �ϴ� ��쿡 �̵��Ÿ��� ������ 
	// ���� ���� ���� ã�´�
	for (i = 1; i <= n; i++) {
		int sum = 0;
		for (j = 0; j < dists.size(); j++) {
			sum += dists[j][i];
		}
		if (sum < minCost) {
			minCost = sum;
			ret = i;
		}
	}
	return ret;
}
int main() {
	int T, i, k, a, b, c;
	scanf("%d", &T);

	while (T > 0) {
		scanf("%d %d", &n, &m);
		vector<pair<int, int>> graph[101];

		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			graph[a].push_back({ b,c });
			graph[b].push_back({ a,c });
		}
		scanf("%d", &k);

		vector<int> v;
		vector<vector<int>> dists;

		for (i = 0; i < k; i++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}

		for (i = 0; i < v.size(); i++) {
			dists.push_back(dijkstra(v[i], n,graph)); // �� ģ������ �ִ� ��ġ������ �ִܰ�θ� ������
		}

		printf("%d\n", getMeetingRoom(n, dists)); 
		T--;
	}
	return 0;
}