//��� ���� ȣ��
//https://www.acmicpc.net/problem/20168

#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
vector<pii> graph[11];

int dijkstra(int from, int to, int money, int n) {
	priority_queue<pair<int,pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	vector<int> v(n + 1, INF);
	int i;
	pq.push({0 ,{ from,money } }); // ��ġ���� �ּҰ� �Ǵ� ��θ� ���ϱ� ���� ��ġ�ɿ� ���Ͽ� �켱���� ����
	v[from] = 0;

	while (!pq.empty()) {
		int shame = pq.top().first;
		int curr = pq.top().second.first;
		int cash = pq.top().second.second;
		pq.pop();

		if (shame > v[curr]) continue; // ��ġ���� �� ���� ��ΰ� ���� ���

		for (i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int cost = shame > graph[curr][i].second ? shame : graph[curr][i].second; // ���ݱ����� ��ο����� �ִ� ��ġ��
			int rest = cash - graph[curr][i].second; // �����ϰ� ���� ��
			if (cost < v[next] && rest >= 0) { // ��ġ���� �� ���� ���� ������ �� ���� ���
				v[next] = cost;
				pq.push({ cost, { next,rest } });
			}
		}
	}

	return v[to] == INF ? -1 : v[to]; // �� �� �ִ� ��ΰ� �����ÿ��� -1���
}

int main() {
	int n, m, from, to, money;
	scanf("%d %d %d %d %d", &n, &m, &from, &to, &money);
	int i;
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	printf("%d",dijkstra(from, to, money, n));
	return 0;
}