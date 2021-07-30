//Ű ����
//https://www.acmicpc.net/problem/2458

/*
#include <cstdio>
#include <vector>
#define INF 987654321
using namespace std;

int graph[501][501];
int rGraph[501][501];

void floydWarshal(int N) {
	int i, j, k;

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];

				if (rGraph[i][k] + rGraph[k][j] < rGraph[i][j])
					rGraph[i][j] = rGraph[i][k] + rGraph[k][j];
			}
		}
	}
}

void init(int N ) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				graph[i][j] = INF;
				rGraph[i][j] = INF;
			}
		}
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int i,j;

	init(N);

	for (i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		rGraph[b][a] = 1; // ������ �׷����� �ڽź��� Ű�� ���� ����鿡 ���� ���ִ��� Ȯ��
	}
	
	floydWarshal(N); // ��� �������� �ٸ� ��� ���������� ��ΰ� �ִ��� Ȯ��
	int cnt = 0;

	for (i = 1; i <= N; i++) {
		bool flag = true; 
		for (j = 1; j <= N; j++) {
			if (i == j) continue; // �ڱ��ڽ��� ����
			if (graph[i][j] == INF && rGraph[i][j] == INF) { // �������� ���� �ִ� ��ΰ� ������ ,������ �Ѵ� ���� ���
				flag = false;
				break;
			}
		}
		if (flag) cnt++; //��� ��ΰ� �ִٸ� ī��Ʈ
	}

	printf("%d", cnt);
	return 0;
}*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

int arr[501][501];
int arr2[501][501];

void floyd(int n) { // ��� ��忡 ���� ��ΰ� �����Ѵٸ� ����
	int i, j, k;

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (i != j) {
					if (arr[i][j] > arr[i][k] + arr[k][j]) {
						arr[i][j] = arr[i][k] + arr[k][j];
					}
					if (arr2[i][j] > arr2[i][k] + arr2[k][j]) {
						arr2[i][j] = arr2[i][k] + arr2[k][j];
					}
				}
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;

    // ������� ������ 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i != j) {
				arr[i][j] = INF;
				arr2[i][j] = INF;
			}
			
		}
	}
	
	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr2[b][a] = 1;
	}

	floyd(n);

	int cnt = 0;
	for (i = 1; i <= n; i++) {
		bool check = true;
		for (j = 1; j <= n; j++) {
			if (arr[i][j] == INF && arr2[i][j] == INF) { // ������� ������ �Ѵ� ��ΰ� �������� �ʴ´ٸ� 
				check = false;
				break;
			}
		}

		if (check) cnt++; // ��� ��忡 ���� ��ΰ� �ִٸ� ������ �� �� �ִ�
	}

	printf("%d", cnt);

	return 0;
}
