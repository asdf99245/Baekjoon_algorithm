// 로봇 조종하기 
// https://www.acmicpc.net/problem/2169

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define INF 987654321
using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001][3];
bool visited[1001][1001];
int dy[] = { 1,0,0 };
int dx[] = { 0,-1,1 };

int dfs(int y, int x, int dir) {
	if (y == n - 1 && x == m - 1) {
		return arr[y][x];
	}
	if (dp[y][x][dir] != -1) return dp[y][x][dir];

	int m = -INF;
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < n && 0 <= nx && nx < m) {
			if(visited[ny][nx] == false)
			visited[ny][nx] = true;
			m = max(m, dfs(ny, nx, i));
			visited[ny][nx] = false;
		}
	}

	dp[y][x][dir] = arr[y][x] + m;
	return dp[y][x][dir];
}

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	memset(visited, false, sizeof(visited));
	visited[0][0] = true;

	printf("%d", dfs(0, 0, 0));
	return 0;
}