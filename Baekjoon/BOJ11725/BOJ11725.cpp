//Ʈ���� �θ� ã��
//https://www.acmicpc.net/problem/11725

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tree[100001];
int par[100001];

void DFS(int curr,int prev) {
	int i;
	par[curr] = prev; // ���� ��尡 �θ���
	for (i = 0; i < tree[curr].size(); i++) {
		int child = tree[curr][i];
		if(child != prev) // �θ� ��� �����ϰ� ���� ��� �湮
			DFS(child, curr);
	}
}


int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	DFS(1, 1);
	for (i = 2; i <= n; i++) {
		printf("%d\n", par[i]);
	}
	return 0;
}