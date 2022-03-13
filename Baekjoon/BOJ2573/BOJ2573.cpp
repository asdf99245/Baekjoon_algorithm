// ����
// https://www.acmicpc.net/problem/2573

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N, M, time = -1;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int arr[301][301];
int height[301][301];
bool visited[301][301];
vector<pair<int, int>> coord;

vector<pair<int,int>> melt() {
	vector<pair<int, int>> tmp;
	for (int i = 0; i < coord.size(); i++) {
		int y = coord[i].first;
		int x = coord[i].second;
		if (height[y][x] > 0) tmp.push_back({ y,x }); // �����ִ� ����
		else arr[y][x] = 0;
	}
	time++;
	return tmp;
}

void BFS(int y ,int x) {
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			
			if (arr[ny][nx] == 0) height[y][x] --; // �ٴ幰�̸� ���� ����
			else { // �ٴ幰�� �ƴҶ�
				if (!visited[ny][nx]) {  // �湮���� �ʾ�����
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				height[i][j] = arr[i][j];
				coord.push_back({ i,j });
			}
		}
	}

	bool flag = false;
	while (!flag) {
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < coord.size(); i++) {
			if (!visited[coord[i].first][coord[i].second]) { // �湮���� ���� ���꿡 ���� 
				cnt++;
				BFS(coord[i].first, coord[i].second); // �̾����ִ� ������ BFS�� ��� �湮
			}
		}

		if (cnt > 1) flag = true; // ������ �� ��� �̻����� ������������
		if (cnt == 0) { // ������ ��� �������
			time = 0;
			break;
		}
		coord = melt(); // ��� ���� ����
	}

	cout << time;

	return 0;
}