//Tree
//https://www.acmicpc.net/problem/13244

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int curr ,vector<vector<int>> &tree, vector<bool> &visited) {
	int i;
	// �湮 ���� ���� ������ ���ʴ�� Ž��
	visited[curr] = true;
	for (i = 0; i < tree[curr].size(); i++) { 
		int next = tree[curr][i];
		if (!visited[next])
			dfs(next, tree, visited);
	}
}

int main() {
	int T, n, m, i;
	scanf("%d", &T);
	while (T > 0) {
		scanf("%d", &n);
		vector<vector<int>> tree(n + 1);
		vector<bool> visited(n + 1);
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		int cnt = 0;
		for (i = 1; i <= n; i++) {
			if (!visited[i]) { // �湮���� ���� ����϶� Ž��
				dfs(i, tree, visited);
				cnt++; // Ž�� �ѹ��� �����ٸ� ��� ��尡 �̾�������
			}
		}
		if (m == n - 1 && cnt == 1) { // ����Ŭ�� ������ �������� n���� ��庸�� 1�� ���� ������ ��������
			printf("tree\n");
		}
		else {
			printf("graph\n");
		}
		T--;
	}
	return 0;
}