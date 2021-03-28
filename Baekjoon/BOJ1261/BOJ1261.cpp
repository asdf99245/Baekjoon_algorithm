//�˰���
//https://www.acmicpc.net/problem/1261

#include <cstdio>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

typedef pair<int, pair<int, int>> pipii;
int n, m;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
int maze[100][100]; // �̷� => �׷���
bool visited[100][100];

void dijkstra() { 
	priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
	pq.push({ 0,{0,0} });
	int i;
	vector<vector<int>> arr(n, vector<int>(m, INF));
	arr[0][0] = 0;
	visited[0][0] = true;

	while (!pq.empty()) {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();

		if (cost > arr[y][x]) continue; // �̹� Ȯ���� ��δ� ��ŵ

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx]) { // �湮���� �ʾҰ� �̷� ���̶��
				int nextCost = cost + maze[ny][nx];
				if (nextCost < arr[ny][nx]) { //��ο� �μ� ���� ���� �� ������� �����Ѵ�
					visited[ny][nx] = true;
					arr[ny][nx] = nextCost;
					pq.push({ nextCost,{ny,nx} });
				}
			}
		}
	}

	printf("%d", arr[n - 1][m - 1]);
}

int main() {
	int i, j;
	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	
	dijkstra();

	return 0;
}