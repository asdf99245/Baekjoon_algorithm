//�峭������
//https://www.acmicpc.net/problem/2637

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool check[101];
int inDegree[101];
vector<pair<int, int>> v[101];
int part[101][101]; 

void topology(int N) {
	queue<int> q;
	int i, j;

	for (i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			part[i][i] = 1;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first;
			int num = v[x][i].second;
			
			for (j = 1; j <= N; j++) { // ���� ��ǰ�� ���� ��ǰ�� �ʿ��� ����ŭ �⺻,�߰� ��ǰ�� ���� ���ؼ� ������
				part[next][j] += num * part[x][j];
			}
			if (--inDegree[next] == 0) { 
				q.push(next);
			}
		}
	}
}

int main() {
	int N, M, i;
	scanf("%d", &N);
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		int X, Y, K;
		scanf("%d %d %d", &X, &Y, &K);
		check[X] = true; // �߰� ��ǰ�̳� ����ǰ
		inDegree[X] ++; // �ʿ��� ��ǰ��
		v[Y].push_back({ X,K });
	}

	topology(N);

	for (i = 1; i <= N; i++) {
		if (!check[i]) { // �⺻ ��ǰ�� ���ؼ��� ���
			printf("%d %d\n", i, part[N][i]);
		}
	}
	return 0;
}