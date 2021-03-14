//��
//https://www.acmicpc.net/problem/3184

#include <iostream>
#include <string>
#include <utility>
#include <memory.h>
#include <queue>
using namespace std;

int r, c;
int wolf = 0, sheep = 0;
string field[250];
bool visited[250][250];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void BFS(int x, int y) {
	int i;
	int w = 0, s = 0;
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	visited[x][y] = true;
	if (field[x][y] == 'v')
		w++;
	else if (field[x][y] == 'o')
		s++;

	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
				if (field[nx][ny] != '#' && !visited[nx][ny]) { //���� �ƴϰ� �湮���� �ʾҴٸ�
					//���볪 ���̶�� ���� ī��Ʈ 
					if (field[nx][ny] == 'v')
						w++;
					else if (field[nx][ny] == 'o')
						s++;

					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}

		}
	}
	//�츮�ȿ� ����� ���� �� ���� ���� �����ش�
	if (s > w) sheep += s; 
	else wolf += w;

}

int main() {
	int i, j;
	cin >> r;
	cin >> c;

	for (i = 0; i < r; i++) {
		cin >> field[i];
	}
	memset(visited, false, sizeof(visited));

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if ((field[i][j] == 'v' || field[i][j] == 'o') && !visited[i][j]) //���볪 ���� �ְ� �湮���� �ʾҴٸ�
				BFS(i, j);
		}
	}

	cout << sheep << " " << wolf;
	return 0;
}