// ���ϴ�ī ��ȭ��
// https://www.acmicpc.net/problem/12784

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

vector<pair<int,int>> tree[1001];
int dp[1001];
bool visited[1001];

int dfs(int curr) {
	visited[curr] = true;

	if (tree[curr].size() == 1 && curr != 1) { // ���� ����� ���
		return 21; // ���̳ʸ���Ʈ �ִ� �������� ū �� ��ȯ
	}

	for (int i = 0; i < tree[curr].size(); i++) {
		int child = tree[curr][i].first;
		int cost = tree[curr][i].second;
		// �湮���� ���� child��
		if (!visited[child])
			// ���� �ٸ��� ���Ľ�Ű�°Ͱ� child�� �ڽ� ���� ����� �ٸ��� ���Ľ�Ű�� �� �� �ּҰ��� ���� 
			dp[curr] += min(dfs(child), cost);
	}

	return dp[curr];
}

int main() {
	int T, N, M;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			int a, b, cost;
			scanf("%d %d %d", &a, &b, &cost);
			// Ʈ�� ����
			tree[a].push_back({ b,cost });
			tree[b].push_back({ a,cost });
		}

		printf("%d\n" ,dfs(1));
		for (int i = 1; i <= N; i++) {
			tree[i].clear();
		}
		// �ʱ�ȭ
		memset(dp, 0, sizeof(dp));
		memset(visited, false, sizeof(visited));
	}


	return 0;
}