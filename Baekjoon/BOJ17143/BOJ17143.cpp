// ���ÿ�
// https://www.acmicpc.net/problem/17143

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct shark {
	int speed;
	int dir;
	int size;
}shark;

int R, C, M;
shark arr[101][101];
int dy[] = { 0, -1,1,0,0 };
int dx[] = { 0, 0,0,1,-1 };
queue<pair<pair<int, int>,shark>> q;
long long total = 0;

int changeDir(int d) { // ���� �ڸ��� ���� ���� �ݴ��
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else return 3;
}

pair<pair<int, int>,shark> move(int y, int x) {
	int d = arr[y][x].dir;
	int s = arr[y][x].speed;
	int sz = arr[y][x].size;
	shark tmp;
	arr[y][x].size = 0; // �̵� �� �ڸ��� ���

	if (d == 1 || d == 2) { // �Ʒ��� ���϶�
		s %= (R - 1) * 2; // (R-1) * 2 ��°�� ó�����·� ���ƿ´�
		for (int i = 0; i < s; i++) { // ������ s��ŭ �̵�
			if (y + dy[d] < 1 || y + dy[d] > R) d = changeDir(d);
			y += dy[d];
			x += dx[d];
		}
	}
	else if (d == 3 || d == 4) { // �¿� �϶�
		s %= (C - 1) * 2; // // (C-1) * 2 ��°�� ó�����·� ���ƿ´�
		for (int i = 0; i < s; i++) { // ������ s��ŭ �̵�
			if (x + dx[d] < 1 || x + dx[d] > C) d = changeDir(d);
			y += dy[d];
			x += dx[d];
		}
	}

	tmp.speed = s;
	tmp.size = sz;
	tmp.dir = d;

	return { { y,x }, tmp };
}

void setShark() {
	int qsize = q.size();
	vector<pair<int, int>> v;
	for (int i = 0; i < qsize; i++) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		shark tmp = q.front().second;
		q.pop();
		if (arr[y][x].size > tmp.size) continue; // ���� �ִ� ���� ũ�Ⱑ �۴ٸ� ����
		arr[y][x] = tmp;
		v.push_back({ y,x });
	}

	for (int i = 0; i < v.size(); i++) { // ���� �� ������ ��� ���
		int y = v[i].first;
		int x = v[i].second;
		q.push({ {y,x},arr[y][x] });
	}
}
void solve(int col) {
	if (col > C) return;

	int catchY = -1, catchX = -1;
	// ���� column ���� y�� ������������ ���� ����� �� ��´�
	for (int i = 1; i <= R; i++) {
		if (arr[i][col].size > 0) {
			total += arr[i][col].size; // ���� ����� ũ�⸦ �信 ����
			arr[i][col].size = 0;
			catchY = i;
			catchX = col;
			break;
		}
	}

	int qsize = q.size();
	for (int i = 0; i < qsize; i++) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		q.pop();
		if (y == catchY && x == catchX) continue; // ���� ���� �����ϰ� ��� �̵�
		q.push(move(y, x));
	}
	setShark(); // �̵��� ������ set
	solve(col + 1); // ��ĭ ������ �̵�
}

int main() {
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		arr[r][c].speed = s;
		arr[r][c].dir = d;
		arr[r][c].size = z;
		q.push({ { r,c },arr[r][c]});
	}

	solve(1);

	printf("%d", total);
	return 0;
}