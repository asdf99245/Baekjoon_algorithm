// ����
// https://www.acmicpc.net/problem/2234

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int n, m;
int arr[51][51];
bool visited[51][51];
int dy[] = { 0,-1,0,1 };
int dx[] = { -1,0,1,0 };
int maxRes = 0;

void BFS(int y, int x) {
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ y,x });
	int cnt = 1;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		int curr = arr[y][x];

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < m && nx >= 0 && nx < n ){
				if ((curr & (1 << i)) == 0 && !visited[ny][nx]) { // ���� ���� �湮���� �ʾҴٸ�
				q.push({ ny,nx });
				visited[ny][nx] = true;
				cnt++;
				}
			}
		}
	}

	maxRes = max(maxRes, cnt); // ���� ���� ���� ���Ѵ�
}

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int cnt = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				cnt++; // ��� ���� �ִ��� ���
			}
		}
	}

	printf("%d\n", cnt);
	printf("%d\n", maxRes);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if ((arr[i][j] & (1 << k)) != 0) {
					// ���� ���������� �ִ���̸� ����
					memset(visited, false, sizeof(visited));
					arr[i][j] -= 1 << k;
					BFS(i, j);
					arr[i][j] += 1 << k;
				}
			}
		}
	}

	printf("%d", maxRes);
	return 0;
}