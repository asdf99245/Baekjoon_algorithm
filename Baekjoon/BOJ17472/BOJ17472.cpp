// 다리 만들기 2
// https://www.acmicpc.net/problem/17472

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int map[11][11];
bool visited[11][11];
int bridge[101][101];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };

void DFS(int y, int x, int num) {
	map[y][x] = num;

	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (0 <= ny && ny < N && 0 <= nx && nx < M) {
			if (map[ny][nx] == 1) {
				map[ny][nx] = num;
				DFS(ny, nx, num);
			}
		}
	}
}

int connect(int y ,int x , int dirY, int dirX) {
	visited[y][x] = true;
	
	while (true) {

	}
}
void BFS(int y, int x) {
	int i;
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				if (map[ny][nx] == 0) {
					connect(ny, nx, dy[i], dy[x]);
					bridge[]
				}
				else {
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	int i, j;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int num = 2;
	int cnt = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				DFS(i, j, num);
				num++;
				cnt++;
			}
		}
	}

	
	return 0;
}