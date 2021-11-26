// Ʈ���� ��������
// https://www.acmicpc.net/problem/2213

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int weight[10001];
vector<int> tree[10001];
int dp[10001][2];
vector<int> ans;

int DFS(int curr, int selected, int prev) {
	int& ret = dp[curr][selected];
	if (ret != -1)return ret;

	if (selected) { // ���õƴٸ�
		ret = weight[curr];
		for (auto next : tree[curr]) {
			if (next == prev) continue;
			ret += DFS(next, 0, curr); // ���� ���� �����Ҽ� ����
		}
	}
	else { // �������� �ʾҴٸ�
		ret = 0;
		for (auto next : tree[curr]) {
			if (next == prev) continue;
			// ���� ��带 ������ ���� �������� ���� ����� ū ���� ����
			int a = DFS(next, 0, curr);
			int b = DFS(next, 1, curr);
			ret += max(a, b);
		}
	}

	return ret;
}

void getSet(int curr, int selected, int prev) { // �ִ��� ���� ��θ� ���� ������ ���Ѵ�. 
	if (selected) {
		ans.push_back(curr);
		for (auto next : tree[curr]) {
			if (next == prev) continue;
			getSet(next, 0, curr);
		}
	}
	else {
		for (auto next : tree[curr]) {
			if (next == prev) continue;
			if (dp[next][1] >= dp[next][0])
				getSet(next, 1, curr);
			else 
				getSet(next, 0, curr);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
	}
	int u, v;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	memset(dp, -1, sizeof(dp));
	int a = DFS(1, 0, 0); // 1�� ��带 �������� ���
	int b = DFS(1, 1, 0); // 1�� ��带 �������� ���

	if (a > b) { // �ִ밪�� ���� ���������� ã�´�.
		getSet(1, 0, 0);
	}
	else {
		getSet(1, 1, 0);
	}
	sort(ans.begin(), ans.end()); // �������� ����

	printf("%d\n", max(a, b));
	for (auto t : ans) {
		printf("%d ", t);
	}

	return 0;
}