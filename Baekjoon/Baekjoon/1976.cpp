//���� ����
//https://www.acmicpc.net/problem/1976

/*
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int city[201][201];
int parent[201];

int find(int u) { //���Ͽ�-���ε� ���ε�
	if (parent[u] == u)
		return u;
	else return parent[u] = find(parent[u]);
}
void merge(int u, int v) {//���Ͽ�-���ε� ���Ͽ�
	u = find(u);
	v = find(v);
	if (u == v) return;

	parent[u] = v;
}
int main() {

	scanf("%d", &n);
	scanf("%d", &m);
	int i, j, connect;

	for (i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &connect);
			if (connect) // ����Ǿ����� �ÿ� ������
				merge(i, j);
		}
	}
	int a;

	scanf("%d", &a);
	int root = find(a); 

	for (i = 1; i < m; i++) {
		scanf("%d", &a);
		if (root != find(a)) { //���࿡ �θ� ���� �ʴٸ� ���� �κ������� �ƴϴ�
			printf("NO");
			return 0;
		}
	}

	printf("YES");
	return 0;
}*/