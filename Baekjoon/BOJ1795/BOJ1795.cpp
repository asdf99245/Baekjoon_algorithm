// ����ȸ��
// https://www.acmicpc.net/problem/1795

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>
using namespace std;

int N, M;
string v[51];
int visited[51][51];
int visit[51][51];
int arr[51][51];
int dy[] = { 2,-2,2,-2,1,-1,1,-1 };
int dx[] = { 1,-1,-1,1,2,-2,-2,2 };

void sumArr() { // ��� ���˷κ����� �̵�Ƚ���� ����
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			arr[i][j] += visited[i][j];
		}
	}
}

void BFS(int y, int x, int num) {
	int i;
	queue<pair<pair<int, int>,pair<int,int>>> q;
	visited[y][x] = 0; // ó���� �̵����� �ʾƵ� �����ϹǷ� 0
	visit[y][x]++;
	q.push({ { y,x }, {0,1} });
	
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		int maal = q.front().second.first; // ���� Ƚ��
		int n = q.front().second.second; // �̵� Ƚ��
		q.pop();

		for (i = 0; i < 8; i++) { 
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && visited[ny][nx] == -1) { // �湮���� �ʾҰ� ������ �����̶��
				visit[ny][nx] ++;
				if (maal >= num) { // �ѹ��� ������ ���� Ƚ���� �Ѿ��ٸ� �̵�Ƚ�� ����
					maal = 0;
					n++;
				}
				visited[ny][nx] = n; // ny,nx������ �̵�Ƚ��
				q.push({ {ny,nx},{maal + 1,n} }); // 1���� �̵�
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	int i, j;
	for (i = 0; i < N; i++) {
		cin >> v[i];
	}
	int maal = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int num = v[i][j] - '0'; 
			if (num >= 1 && num <= 9) { // �����̶��
				maal++; // ���� �� ���� ����
				memset(visited, -1, sizeof(visited));
				BFS(i, j, num);
				sumArr();
			}
		}
	}

	bool check = false;
	int ans = 987654321;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (visit[i][j] == maal && arr[i][j] >= 0) { // ��� ���˿��� ���ϼ� �ִٸ�
				ans = min(ans, arr[i][j]);
				check = true;
			}
		}
	}

	if (!check) // ���Ϲ���� ����
		cout << -1;
	else
		cout << ans;
	return 0;
}