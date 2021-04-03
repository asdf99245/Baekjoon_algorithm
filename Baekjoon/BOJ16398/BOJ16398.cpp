//�༺ ����
//https://www.acmicpc.net/problem/16398

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> pipii;
int cost[1000][1000];
int parent[1000];
vector<pipii> v;

int find(int x) { // �θ� ��带 ã�´�
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

bool sameParent(int a, int b) { // ���� �θ� ��带 ������ �ִ��� Ȯ��
	a = find(a);
	b = find(b);
	if (a == b) return true;
	return false;
}

void Union(int a, int b) { // �� ��带 ���� �������� �����ش�
	a = find(a);
	b = find(b);
	
	if (a != b)
		parent[b] = a;
}
int main() {
	int N, i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	for (i = 0; i < N; i++) parent[i] = i; // i����� �θ��带 ����Ŵ

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			v.push_back({ cost[i][j], { i,j} }); // �ϳ��� ��θ� ����
		}
	}

	sort(v.begin(), v.end()); // ���� ���� �������� ����

	long long ans = 0;
	for (i = 0; i < v.size(); i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		int c = v[i].first;
		if (!sameParent(a, b)) { // ���� ��κ��� ����
			Union(a, b);
			ans += c;
		}
	}

	printf("%lld", ans); 
	return 0;
}