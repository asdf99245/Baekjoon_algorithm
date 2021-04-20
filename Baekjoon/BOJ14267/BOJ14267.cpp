//ȸ�� ��ȭ1
//https://www.acmicpc.net/problem/14267

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int cnt[100001];
int compliment[100001];

void DFS(int start, int w) {
	int i;

	cnt[start] += w; // Ī���� ��ġ�� ���Ѵ�

	for (i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		DFS(next, w); // ���� �Ĺ�� 
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int super;
		scanf("%d", &super);
		if (i == 1) continue;
		v[super].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int num, w;
		scanf("%d %d", &num, &w);
		compliment[num] += w; // �Ȱ��� ������ ���� Ī�� ��ġ�� ����
	}

	for (int i = 1; i <= n; i++) {
		if (compliment[i] != 0) // Ī�� ���� ������ ���� DFS
			DFS(i, compliment[i]);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", cnt[i]);
	}

	return 0;
}