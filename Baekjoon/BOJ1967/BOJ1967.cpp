//Ʈ���� ����
//https://www.acmicpc.net/problem/1967

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int maxDist = 0;
int farthest;

void DFS(int curr,int dist) {
	int i;
	visited[curr] = true;

	if (maxDist < dist) { // �� �� �Ÿ���� ����
		maxDist = dist;
		farthest = curr;
	}

	for (i = 0; i < tree[curr].size(); i++) {
		int next = tree[curr][i].first;
		int cost = tree[curr][i].second;
		if (!visited[next]) {
			DFS(next, dist + cost);
		}
	}
}
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		int u, v, weight;
		scanf("%d %d %d", &u, &v, &weight);
		tree[u].push_back({ v,weight });
		tree[v].push_back({ u,weight });
	}

	DFS(1, 0); // ��Ʈ�������� ���� �ָ��ִ� ��带 ã�´�
	maxDist = 0;
	memset(visited, false, sizeof(visited));
	DFS(farthest, 0); // ã�� ���κ��� ���� �� �������� ���̸� ã�´�

	printf("%d", maxDist);
	return 0;
}