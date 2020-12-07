// Z
//https://www.acmicpc.net/problem/1074

#include <cstdio>
#include <cmath>
using namespace std;

int cnt = -1;
// Z모양 방향 
int dy[] = { 0,0,1,0 };
int dx[] = { 0,1,-1,1 };
void DFS(int y, int x, int r, int c, int n) {
	int l = pow(2, n); //배열 길이
	if (r > y + l || c > x + l) { // 찾는 인덱스가 범위안에 없다면 범위 크기만큼 카운트에 더해줌
		cnt += l * l;
		return;
	}
	if (y > r && x > c) return; // 찾는 인덱스가 범위 시작점보다 이전이면 찾을 필요 없음
	if (n == 1) { // 배열 길이가 2 일시 Z 모양으로 탐색하면서 카운트수 올려줌
		for (int i = 0; i < 4; i++) {
			++cnt;
			y += dy[i];
			x += dx[i];
			if (y == r && x == c) { // 발견시 출력
				printf("%d", cnt);
				return;
			}
		}
		return;
	}

	// 네 구간으로 분할정복
	DFS(y, x, r, c, n - 1);  
	DFS(y, x + l / 2, r, c, n - 1);
	DFS(y + l / 2, x, r, c, n - 1);
	DFS(y + l / 2, x + l / 2, r, c, n - 1);
}
int main() {
	int n, c, r;
	scanf("%d %d %d", &n, &r, &c);
	
	DFS(0, 0, r, c, n);
	return 0;
}