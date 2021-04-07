//���� �ȵǴ� ����
//https://www.acmicpc.net/problem/14621

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace  std;

typedef pair<int, pair<int, int>> pipii;
int parent[1001];
char gender[1001];
bool check[1001];

int find(int x) { // �θ� ��带 ã�´�
	if (x == parent[x])
		return x;
	else 
		return parent[x] = find(parent[x]);
}

void Union(int a, int b) { // �� ��带 ���� �θ�� �����Ѵ�
	a = find(a);
	b = find(b);

	if (a != b)
		parent[b] = a;
}

bool same_parent(int a, int b) { // �� ��尡 ���� �������� Ȯ��
	a = find(a);
	b = find(b);
	if (a == b) return true;

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	priority_queue<pipii, vector<pipii>, greater<pipii>> pq; // �Ÿ��� ª�������� ����

	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 1; i <= N; i++) {
		cin >> gender[i];
	}

	for (int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		if(gender[u] != gender[v]) // ���� �ٸ� ������ ���б��� Edge�� ����
			pq.push({ d,{u,v} });
	}

	int sum = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();

		if (!same_parent(u, v)) {
			sum += dist;
			Union(u, v);
			// ����� ���б��� üũ
			check[u] = true; 
			check[v] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) { // ���б� �� ������� ���� ��찡 ������쿡 -1 ���
			cout << -1;
			return 0;
		}
	}
	cout << sum;

	return 0;
}