//���ĺ�
//https://www.acmicpc.net/problem/1987

/*
#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int maxL = 0;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
char board[20][20];
bool visited[26]; //�ƽ�Ű �ڵ� �̿��ؼ� ���ĺ� ���� ex) A�� ������ 65�̹Ƿ� A�� ���ָ� 0��° index

inline int alphabet(char x) {  //���ĺ��� index�� ����
	return (int)x - 'A';
}
void DFS(int y, int x, int cnt) { 
	visited[alphabet(board[y][x])] = true;
	int i;

	for (i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < R && 0 <= nx && nx < C) {
			if (!visited[alphabet(board[ny][nx])]) { //�湮�� ���ĺ��� �ƴ϶��
				DFS(ny, nx, cnt + 1);
				visited[alphabet(board[ny][nx])] = false; //�湮�ϱ� ������ �����ش�
			}
		}
	}

	if (maxL < cnt) maxL = cnt; //�ִ� ĭ�� ����
}

int main() {
	//����� �ӵ� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	cin >> R >> C;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	DFS(0, 0, 1);

	printf("%d", maxL);
	return 0;
}
*/