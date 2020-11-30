//안전영역
/*#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

int n;
int field[101][101];
bool visited[101][101];
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

void DFS(int y, int x, int height) {
	visited[y][x] = true; // 방문하였으므로 true
	int i;

	for (i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && visited[ny][nx] == false) {
			if (field[ny][nx] > height) { // 수위보다 높은곳일때 DFS
				DFS(ny, nx, height);
			}
		}
	}

	return;
}
int main() {
	int i, j, k;
	int maxHeight = -1; 
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &field[i][j]);
			if (field[i][j] > maxHeight)
				maxHeight = field[i][j];
		}
	}

	int maxCnt = -1;
	for (i = 0; i <= maxHeight; i++) { // 하나도 안 왔을때부터 최대 높이까지
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (visited[j][k] == false && field[j][k] > i) { // 방문했고 수위보다 높을때
					DFS(j, k, i);
					cnt++; // 영역의 개수올려줌
				}
			}
		}
		if (maxCnt < cnt) maxCnt = cnt; // 최대영역 개수 갱신
	}

	printf("%d", maxCnt);
	return 0;
}*/