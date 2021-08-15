// Ʈ���� ����
// https://www.acmicpc.net/problem/1167

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[100001];
vector<pair<int, int>> tree[100001];
int maxLength = -1;
int maxNode;

void dfs(int curr, int dist) {
	visited[curr] = true;

	if (maxLength < dist) { // ���� �� ��带 ã�´�
		maxNode = curr;
		maxLength = dist;
	}

	int i;
	for (auto node: tree[curr]) {
		int nx = node.first;
		int cost = node.second;
		if (!visited[nx]) { // �湮���� ���� ��忡 �湮
			dfs(nx, dist + cost);
			visited[nx] = false;
		}
	}
}

int main() {
	int v, i;
	scanf("%d", &v);

	for (i = 0; i < v; i++) {
		int n, a, cost;
		scanf("%d", &n);
		while (1) {
			scanf("%d", &a);
			if (a == -1) // ����
				break;
			scanf("%d", &cost);
			tree[n].push_back({ a,cost });
		}
	}

	dfs(1, 0); // ������ ������ ���� �� ��带 ã��
	visited[1] = false;
	dfs(maxNode, 0); // �� ������ ���� �� ��带 ã���� Ʈ���� ����

	printf("%d", maxLength);

	return 0;
}