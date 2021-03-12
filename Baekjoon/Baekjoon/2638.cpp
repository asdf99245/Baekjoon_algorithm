//ġ��
//https://www.acmicpc.net/problem/2638

#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX 100
using namespace std;

int n, m;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int paper[MAX][MAX];
bool air[MAX][MAX];
queue<pair<int, int>> cheese;
int time = 0;

void BFS(int y, int x) {
	queue<pair<int, int>> q;
	int i;
	q.push({ y, x });
	air[y][x] = true;

	while(!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m) {
				if (!air[ny][nx] && paper[ny][nx] == 0) {
					q.push({ ny,nx });
					air[ny][nx] = true; //�ܺΰ��� ǥ��
				}
			}
		}
	}
}

bool melt(int y, int x) {
	int i;
	int cnt = 0;
	//�ֺ��� ���Ⱑ �ִ� ĭ�� 2ĭ �̻��ϰ�� ����
	for (i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (air[ny][nx])
			cnt++;
		if (cnt == 2) return true;
	}

	return false;
}

void contact_air(int s) {
	time++;
	int y, x, i;
	queue<pair<int, int>> check; 
	for (i = 0; i < s; i++) {
		y = cheese.front().first;
		x = cheese.front().second;
		cheese.pop();

		if (melt(y, x)) { //ġ� ��Ҵٸ� ���� ġ�� ����
			check.push({ y,x });
		}
		else //ġ� ���� �ʾҴٸ� �ٽ� ť�� Ǫ��
			cheese.push({ y,x });
	}

	//�ϳ��� ������ ����ġ� ������ ���� ������ ���Ƿ� ť�� �����س��� �ѹ��� ����
	while (!check.empty()) {
		y = check.front().first;
		x = check.front().second;
		check.pop();
		paper[y][x] = 0; 
		//ġ� ��� �ܺΰ��Ⱑ ���ԵǴ� �ֺ������� Ȯ��
		BFS(y, x);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &paper[i][j]);
			if (paper[i][j] == 1) { //ġ���� ��ġ�� �̸� ����
				cheese.push({ i, j });
			}
		}
	}

	BFS(0, 0); //�ܺ� ���� ã�Ƽ� üũ
	while (!cheese.empty()) { //ġ� �ٳ���������
		contact_air(cheese.size());
	}

	printf("%d", time);
	return 0;
}