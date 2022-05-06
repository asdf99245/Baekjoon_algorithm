// ���� �̾�� 2
// https://www.acmicpc.net/problem/14284

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int n, m, s, t;
vector<pii> graph[5001];
int cost[5001];

void dijkstra() {
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	cost[s] = 0;
	pq.push({ cost[s],s }); // s �������� ����
	while (!pq.empty()) {
		pii top = pq.top();
		int currCost = top.first;
		int curr = top.second;
		pq.pop();

		if (currCost > cost[curr]) continue; // cost�� ���ŵ� ���¶�� ��ŵ

		if (curr == t) { // t�� ����Ǿ�����
			cout << currCost;
			break;
		}
		
		for (auto nx : graph[curr]) {
			int nextCost = currCost + nx.second;
			int next = nx.first;
			if (nextCost < cost[next]) { // next���� �Ÿ� ����
				cost[next] = nextCost;
				pq.push({ nextCost,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) cost[i] = 100 * n + 1; 
	cin >> s >> t;

	dijkstra();

	return 0;
}