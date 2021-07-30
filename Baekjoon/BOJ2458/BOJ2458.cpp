//키 순서
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
		rGraph[b][a] = 1; // 역방향 그래프로 자신보다 키가 작은 사람들에 연결 돼있는지 확인
	}
	
	floydWarshal(N); // 모든 정점에서 다른 모든 정점으로의 경로가 있는지 확인
	int cnt = 0;

	for (i = 1; i <= N; i++) {
		bool flag = true; 
		for (j = 1; j <= N; j++) {
			if (i == j) continue; // 자기자신은 제외
			if (graph[i][j] == INF && rGraph[i][j] == INF) { // 정점으로 갈수 있는 경로가 역방향 ,정방향 둘다 없을 경우
				flag = false;
				break;
			}
		}
		if (flag) cnt++; //모든 경로가 있다면 카운트
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

void floyd(int n) { // 모든 노드에 대해 경로가 존재한다면 갱신
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

    // 정방향과 역방향 
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
			if (arr[i][j] == INF && arr2[i][j] == INF) { // 정방향과 역방향 둘다 경로가 존재하지 않는다면 
				check = false;
				break;
			}
		}

		if (check) cnt++; // 모든 노드에 대해 경로가 있다면 순서를 알 수 있다
	}

	printf("%d", cnt);

	return 0;
}
