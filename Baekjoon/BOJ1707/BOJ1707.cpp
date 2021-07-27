// �̺� �׷���
// https://www.acmicpc.net/problem/1707

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

vector<int> graph[20001];
int check[20001];
bool flag;

void DFS(int v, int c) {
	check[v] = c; // c �������� ����
	int i;
	for (i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if (check[nv] == 0) { // ���� ���о��ߴٸ� �ݴ� �������� ����
			DFS(nv, c * -1);
		}
		else if (check[nv] && c == check[nv]) { // ���е��ִµ� ����� ���� �����̶�� ����
			flag = false;
			return;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T > 0) {
		int v, e;
		scanf("%d %d", &v, &e);
		for (int i = 0; i < e; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			// ����� ����
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		flag = true;
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) { // �˻����� ���� �����̶��
				DFS(i, 1);
			}
		}

		if (!flag) 
			printf("NO\n");

		else 
			printf("YES\n");

		// �ʱ�ȭ
		for (int i = 1; i <= v; i++)
			graph[i].clear();

		memset(check, 0, sizeof(check));
		T--;
	}
	return 0;
}