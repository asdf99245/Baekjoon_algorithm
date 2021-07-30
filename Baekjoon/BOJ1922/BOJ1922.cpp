// ��Ʈ��ũ ����
// https://www.acmicpc.net/problem/1922

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,pair<int, int>>> v;
int parent[1001];

int find(int x) { // x �� �θ� ã�´�
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) // �θ� ���ٸ� ��ġ�� ����
		return false;
		
	parent[a] = b; //  ���� �θ��

	return true;
}

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int i;
	for (i = 1; i <= n; i++)  // �θ� �ڽ����� �ʱ�ȭ
		parent[i] = i;

	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({ c,{a,b} });
	}

	sort(v.begin(), v.end()); // cost ������������ ����

	int ans = 0;
	for (i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		
		if (Union(a, b)) // a, b �� ���� �������� ���ƴٸ� cost ������
			ans += cost;
	}

	printf("%d", ans);

	return 0;
}