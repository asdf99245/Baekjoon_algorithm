//��Ʈ��ũ ����
//https://www.acmicpc.net/problem/1922

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int par[1001];
vector<pair<pair<int, int>, int>> edge;
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

int find(int x) { // ���Ͽ� ���ε� 
	if (par[x] == x)
		return x;
	else return par[x] = find(par[x]);
}
bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	else if (a > b) par[a] = b;
	else par[b] = a;

	return true;
}
int main() {
	int i;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < n; i++) par[i] = i; // �θ� ��� �ʱ�ȭ
	for (i = 0; i < m; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		edge.push_back({ {a,b},cost });
	}

	sort(edge.begin(), edge.end(), comp); // ���� ���� ������ �������� ����

	int minCost = 0;

	for (i = 0; i < edge.size(); i++) {
		int a = edge[i].first.first;
		int b = edge[i].first.second;
		int cost = edge[i].second;
		if (Union(a, b)) minCost += cost; // ����Ŭ �߻����� ������ ���� �߰�
	}

	printf("%d", minCost);
	return 0;
}