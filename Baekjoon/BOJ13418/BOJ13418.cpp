//�б� Ž���ϱ�
//https://www.acmicpc.net/problem/13418

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Edge {
	int type;
	int u;
	int v;
}Edge;

vector<Edge> edge;
int parent[1001];
int cnt;

bool cmp1(const Edge& a, const Edge& b) { // �������� ����
	return a.type > b.type;
}

bool cmp2(const Edge& a, const Edge& b) { // �������� ����
	return a.type < b.type;
}

int find(int x) { // �θ� ��� ã�´�
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
} 

void Union(int a, int b) { // ��带 ���� �������� ��ģ��
	a = find(a);
	b = find(b);
	parent[b] = a;
}

bool same_parent(int a, int b) { // �θ� ������
	a = find(a);
	b = find(b);
	if (a != b)
		return false;

	return true;
}

int kruskal(int N, bool (*cmp)(const Edge &,const Edge &)) {
	int i,res = 0;
	// �ʱ�ȭ
	for (i = 0; i <= N; i++) parent[i] = i;

	// �־��� ��쿣 ���������� �켱 �ּ��� ��쿣 �������� �켱���� ��ġ������
	sort(edge.begin(), edge.end(), cmp);

	for (i = 0; i < edge.size(); i++) {
		int t = edge[i].type;
		int u = edge[i].u;
		int v = edge[i].v;
		if (!same_parent(u, v)) {
			Union(u, v);
			if (t == 0) res++; // ���������Ͻ� ī��Ʈ + 1
		}
	}

	return res * res;
}
int main() {
	int N, M, start = 0, i;
	scanf("%d %d", &N, &M);
	for (i = 0; i <= M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge.push_back({ c,a,b });
	}

	int ans = kruskal(N, cmp2) - kruskal(N, cmp1);
	printf("%d",ans);
	return 0;
}