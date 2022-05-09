// 도로의 개수
// https://www.acmicpc.net/problem/1577

#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <map>
using namespace std;

typedef long long ll;
int n, m, k;
ll dp[101][101];
bool visited[101][101];
map<pair<int, int>,pair<int,int>> mp;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

void dfs(int y, int x) {
	if (y == n && x == m) {
		return;
	}
	
	pair<int, int> tmp = mp[{y, x}];

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (tmp.first == ny && tmp.second == nx) continue;

		if (0 <= ny && ny <= n && 0 <= nx && nx <= m && !visited[ny][nx]) {
			dp[ny][nx] += dp[y][x];
			dfs(ny, nx);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		mp[{a, b}] = { c,d };
	}

	memset(dp, 0, sizeof(dp));

	return 0;
}