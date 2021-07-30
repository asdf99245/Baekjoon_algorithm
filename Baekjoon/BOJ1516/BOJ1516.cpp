// ���� ����
// https://www.acmicpc.net/problem/1516

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[501];
int inDegree[501];
int cost[501];
int dp[501];

void topology(int n) {
	int i;
	queue<int> q;
	for (i = 1; i <= n; i++) {
		if (inDegree[i] == 0) { // ����Ǿ���ϴ� ��尡 ���ٸ�
			q.push(i);
			dp[i] = cost[i]; 
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (i = 0; i < graph[curr].size(); i++) { 
			int next = graph[curr][i];
			dp[next] = max(dp[next], dp[curr] + cost[next]); // ���� ū �ҿ�ð��� �ɸ��� ���� �ǹ��� �ð��� ������ 
			if (--inDegree[next] == 0) { // ��� ���� �ǹ��� �� �����ٸ�
				q.push(next);
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		int a;
		scanf("%d", &cost[i]);
		while (1) {
			scanf("%d", &a);
			if (a == -1) // -1 �Է½� ����
				break;
			inDegree[i] ++; // �������� ǥ��
			graph[a].push_back(i);
		}
	}

	topology(n); // ���� ����

	for (i = 1; i <= n; i++)
		printf("%d ", dp[i]);
	return 0;
}