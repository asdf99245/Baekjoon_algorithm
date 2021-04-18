//�۾�
//https://www.acmicpc.net/problem/2056

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int inDegree[10001];
int cost[10001];
vector<int> v[10001];
int dp[10001];

void topology(int N) {
	int i, j;
	queue<int> q;
	for (i = 1; i <= N; i++) {
		if (inDegree[i] == 0) { // ���� ���谡 ���� �۾��� q�� ���� ����
			q.push(i);
			dp[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];
			dp[next] = max(dp[next],cost[next] + dp[curr]); // �����۾��� �ϱ���� �ɸ��ð��� �� �� �ð����� ����(�� ���� �ɸ� �ð����� �ڵ������� �Ϸ�)
			if(--inDegree[next] == 0) // ��� ���� �۾��� �Ϸ�ƴٸ� q�� Ǫ��
				q.push(next);
		}
	}
}

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int num, pre;
		scanf("%d %d", &cost[i], &num);
		inDegree[i] = num; // ��������
		for (int j = 0; j < num; j++) {
			scanf("%d", &pre);
			v[pre].push_back(i); 
		}
	}

	topology(N); 

	int ans = 0;
	// �� �ɸ� �ð��� ���ϱ� ���� ���� ū �ð��� ã�´�
	for (i = 1; i <= N; i++) { 
		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d", ans);
	return 0;
}