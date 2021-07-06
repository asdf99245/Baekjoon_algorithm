// �ٸ� �����
// https://www.acmicpc.net/problem/2146

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int n;
int map[101][101];
bool visited[101][101];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

void mark(int y, int x, int num) { // �� ���� ���� �ٸ��� ��ȣ�� �ű�
	queue<pair<int, int>> q;
	map[y][x] = num;
	q.push({ y,x });

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < n) {
				if (map[ny][nx] != 0 && map[ny][nx] != num) {
					map[ny][nx] = num;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int BFS(int num) {
	queue<pair<pair<int, int>,int>> q; // ��ǥ, ��������� �ٸ� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == num) { // �ش��ϴ� ���̸� ť�� ����
				q.push({ { i,j } ,0 });
				visited[i][j] = true;
			}
			
		}
	}

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < n) { // ���� �ȿ� �ְ�
				if (!visited[ny][nx]) { // �湮���� �ʾ�����
					if (map[ny][nx] == 0) { // �ٴٸ� �ٸ� ����
						visited[ny][nx] = true;
						q.push({ { ny,nx }, cnt + 1 });
					}
					else if (map[ny][nx] && map[ny][nx] != num) { // �ٸ� ���� �����ߴٸ� �ٸ� ���� ��ȯ
						return cnt;
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int num = 2;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				mark(i, j, num);
				num++;
			}		
		}
	}

	int ans = 10001;
	for (i = 2; i < num; i++) {
		memset(visited, false, sizeof(visited));
		ans = min(ans,BFS(i)); // ��� ������ BFS ���� ���� ���� �ٸ����� ����
	}

	printf("%d", ans);
	return 0;
}