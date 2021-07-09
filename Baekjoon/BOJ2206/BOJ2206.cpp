// �� �μ��� �̵��ϱ�
// https://www.acmicpc.net/problem/2206

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
int map[1001][1001];
bool visited[1001][1001][2]; // 3���� �迭�� ������� ���� �μ��� �Ⱥμ��� ����
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };

int BFS(int y, int x) {
	visited[y][x][0] = true;
	int i;
	queue<pair<pair<int, int>, pair<int,bool>>> q;
	q.push({ {y,x},{1,false} });

	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		int cnt = q.front().second.first; // ������� �Ÿ�
		bool check = q.front().second.second; // ���� �μ��� üũ
		q.pop();

		if (y == N - 1 && x == M - 1) { // �����ߴٸ� ����
			return cnt;
		}
		
		for (i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M) { // �����ȿ� ������
				if (map[ny][nx] == 1 && !check) { // ���̰� ���� �μ����� ���ٸ�
					visited[ny][nx][1] = true;
					q.push({ {ny,nx},{cnt + 1,true} });
				}
				else if (map[ny][nx] == 0 && !visited[ny][nx][check] ) { // ���� �ƴ϶��
					visited[ny][nx][check] = true;
					q.push({ {ny,nx},{cnt + 1,check} });
				}
			}
		}
	}

	return -1;
}

int main() {
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d",BFS(0, 0));

	return 0;
}