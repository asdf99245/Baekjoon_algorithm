//������� ����
//https://www.acmicpc.net/problem/9372

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];

int find(int x) { 
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

bool Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	parent[v] = u;

	return true;
}

int main() {
	int t, n, m, i;
	scanf("%d", &t);
	while (t > 0) {
		vector<pair<int, int>> edge;
		int cnt = 0;
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++) parent[i] = i; // ����� �θ��� ����Ŵ
		for (i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			edge.push_back({ a,b });
		}

		for (i = 0; i < edge.size(); i++) {
			// ���Ͽ� ���ε�
			if (Union(edge[i].first, edge[i].second)) { // �� ���� �����ٿ� ���� ���� �������� �����ϰ� �ƴ϶�� �����ְ� ī��Ʈ + 1
				cnt++;
			}
		}

		printf("%d\n", cnt);
		t--;
	}

	return 0;
}