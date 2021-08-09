// ��������
// https://www.acmicpc.net/problem/19535

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[300001];
bool visited[300001];
long long sz[300001];
long long d = 0, g = 0;

void cnt(int n) {
	visited[n] = true; // �湮

	if (sz[n] >= 3) { // ��尡 n��(3�� �̻�) ������ִٸ� G tree�� nC3�� ������ִ� 
		g += (sz[n] * (sz[n] - 1) * (sz[n] - 2)) / 6;
	}

	for (auto node : graph[n]) { 
		if (!visited[node]) { // �湮���� ���� �����
			if(sz[n] > 1 && sz[node] > 1) // �� ��尡 ������ �����ϰ� �ٸ� ����(n��,m��)�� ������ִٸ�
				d += (sz[n] - 1) * (sz[node] - 1); // n * m��ŭ D tree�� ����� �ִ� (-1�� ���θ� ����)
			cnt(node);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// �� ��忡�� ����Ǿ� �ִ� ������ ������ ����
	for (int i = 1; i <= n; i++)
		sz[i] = graph[i].size();

	cnt(1);

	if (d > 3 * g) // D - tree
		printf("D");
	else if (d < 3 * g) // G - tree
		printf("G");
	else // DUDUDUNGA tree
		printf("DUDUDUNGA");
	
	return 0;
}