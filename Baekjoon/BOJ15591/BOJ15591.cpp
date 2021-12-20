// Mootube(silver)
// https://www.acmicpc.net/problem/15591

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

typedef long long ll;
int N, Q;
vector<pair<int, ll>> graph[5001];
bool visited[5001];

int BFS(int curr, ll k) {
	queue<pair<int, ll>> q;
	visited[curr] = true;
	q.push({ curr,0 });

	int cnt = 0;
	while (!q.empty()) {
		curr = q.front().first;
		ll usa = q.front().second;
		q.pop();

		if (usa >= k) cnt++; // USADO�� K�̻��̸� count

		for (auto n : graph[curr]) {
			int next = n.first;
			ll nextUsa = n.second;
			if (!visited[next]) { // �湮���� ���� ��忡 ����
				visited[next] = true;
				if (usa == 0) 
					q.push({ next,nextUsa });
				else // ������ ����� �������� USADO�� ����
					q.push({ next,min(usa,nextUsa) });
			}
		}
	}

	return cnt;
}

int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N - 1; i++) {
		int p, q;
		ll r;
		scanf("%d %d %lld", &p, &q, &r);
		graph[q].push_back({ p,r });
		graph[p].push_back({ q,r });
	}
	for (int i = 0; i < Q; i++) {
		ll k;
		int v;
		scanf("%lld %d", &k, &v);
		memset(visited, false, sizeof(visited));
		printf("%d\n", BFS(v, k));
	}
	return 0;
}