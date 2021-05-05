//ACM craft
//https://www.acmicpc.net/problem/1005

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cost[1001];

void topology(int N , vector<int> &inDegree ,vector<int> &dp, vector<int> graph[1001]) {
	int i;
	queue<int> q;

	for (i = 1; i <= N; i++) {
		if (inDegree[i] == 0) { // ���� �ž� �ϴ� �ǹ��� ���ٸ� ť�� ���� ����
			q.push(i);
			dp[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			dp[next] = max(dp[next], cost[next] + dp[curr]); // �ǹ��� ���ÿ� ������ �ֱ⶧���� ���� �� �ǹ��� ���� �����ɸ� �ð��� ���Ѱ��̿�����
			if (--inDegree[next] == 0) { // ��� ���� �ǹ��� �� �����ٸ� ť�� ����
				q.push(next);
			}
		}
	}
}

int main() {
	int T, i;
	scanf("%d", &T);
	while (T > 0) {
		int N, K;
		scanf("%d %d", &N, &K);
		vector<int> inDegree(N + 1, 0); // ��������
		vector<int> dp(N + 1, 0); 
		vector<int> graph[1001];

		for (i = 1; i <= N; i++) {
			scanf("%d", &cost[i]);
		}

		for (i = 0; i < K; i++) {
			int X, Y;
			scanf("%d %d", &X, &Y);
			graph[X].push_back(Y); 
			inDegree[Y] ++; // ���� ����� �ϴ� �ǹ� ��
		}

		topology(N, inDegree, dp, graph); // ���� ����
		int goal;
		scanf("%d", &goal);
		printf("%d\n", dp[goal]);
		T--;
	}
	return 0;
}