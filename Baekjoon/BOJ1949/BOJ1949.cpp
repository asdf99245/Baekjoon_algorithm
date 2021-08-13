// ��� ����
// https://www.acmicpc.net/problem/1949

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int num[10001];
bool visited[10001];
vector<int> tree[10001];
int dp[10001][2];

void solve(int curr) {
	visited[curr] = true;

	dp[curr][0] = 0; // �Ϲ� �����϶�
	dp[curr][1] = num[curr]; // ��� ������ �����Ҷ�

	for (int i = 0; i < tree[curr].size(); i++) {
		int next = tree[curr][i];
		if (!visited[next]) { // �湮���� �ʾҴٸ�
			solve(next);
			dp[curr][0] += max(dp[next][0], dp[next][1]); // �Ϲ� �����̸� ���������� �Ϲݸ���,��������� �ϳ���
			dp[curr][1] += dp[next][0]; // ��������̸� ���������� ��������ϼ� ����
		}
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	for (i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));

	solve(1);

	printf("%d", max(dp[1][0], dp[1][1])); // 1�� ������ ��������϶��� �Ϲݸ����϶��� ū���� ����

	return 0;
}