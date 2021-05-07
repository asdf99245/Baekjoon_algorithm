//Ʈ���� ��հ� ����
//https://www.acmicpc.net/problem/20924

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 200000
using namespace std;

vector<pair<int,int>> tree[MAX + 1];
int dp[MAX + 1];
bool visited[MAX + 1];
int pole = -1;
int maxLength = 0;
bool flag = false;

void DFS(int curr, int N, int R ) {
	visited[curr] = true;
	int i;
	if (dp[curr] > maxLength) maxLength = dp[curr]; // ��Ʈ�������� ���� �� ���� ����
	if (!flag) { // ��ձ��̰� ���������� üũ
		pole = dp[curr];
		if (curr == R) { // ��Ʈ�� ��� child�� 2�� �̻��� ��� �Ⱑ���
			if (tree[curr].size() > 1) flag = true;
		}
		else { // ��Ʈ�� �ƴ� ��� ������ ��带 ���־����
			if (tree[curr].size() - 1 > 1) flag = true;
		}
	}

	for (i = 0; i < tree[curr].size(); i++) {
		int child = tree[curr][i].first;
		int length = tree[curr][i].second;
		if (!visited[child]) {
			dp[child] = dp[curr] + length; // ���� �������� ���̴� ����������� ���� + �����忡�� ��������� ����
			DFS(child, N, R);
		}
	}
}
int main() {
	int N, R, i;
	scanf("%d %d", &N, &R);
	if (N == 1) { // ��尡 �Ѱ��ϰ�� ��ձ��̿� �������� ���� 0
		printf("0 0");
		return 0;
	}
	for (i = 0; i < N - 1; i++) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		tree[a].push_back({ b,d });
		tree[b].push_back({ a,d });
	}

	DFS(R, N, R);
	printf("%d %d", pole, maxLength - pole); // ��ձ��̿� ���� �� �������� = (��Ʈ�������� ���� �� ������ ���� - ��ձ���)
	return 0;
}