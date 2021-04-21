//������ ������
//https://www.acmicpc.net/problem/19542

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int depth[100001];

int DFS(int curr){
	int i;
	visited[curr] = true;

	for (i = 0; i < v[curr].size(); i++) {
		int next = v[curr][i];
		if (!visited[next]) {
			depth[curr] = max(depth[curr], DFS(next) + 1); // �������� ������ �Ÿ��� ���� �� �Ÿ��� ����
		}
	}

	return depth[curr];
}

void BFS(int start,int d) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	int i,ans = 0;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];
			if (!visited[next] && depth[next] >= d) { // ��忡 ���� �Ÿ��� D�̻��̰� �湮���� �ʾҴٸ� 
				q.push(next);
				visited[next] = true;
				ans++; 
			}
		}
	}

	printf("%d", ans * 2); // ���ƿ��� ��θ� ����� * 2 
}

int main() {
	int n, s, d;
	scanf("%d %d %d", &n, &s, &d);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		// �׷��� ����
		v[x].push_back(y);
		v[y].push_back(x);
	}

	DFS(s); // �� ��忡������ ������������ �ִ� ���̸� ����
	BFS(s, d); // �̵� �Ÿ� ���� 

	return 0;
}