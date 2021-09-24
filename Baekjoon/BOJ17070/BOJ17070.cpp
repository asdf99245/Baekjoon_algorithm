// ������ �ű��1 
// https://www.acmicpc.net/problem/17070

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[17][17];
int dp[17][17];
int ans = 0;

bool check(int s,int y ,int x) {
	if (s == 0) { // ���������� �̵�
		if (arr[y][x + 1] != 1 && x + 1 < N) return true;
	}
	else if (s == 1) { // �Ʒ��� �̵�
		if (arr[y + 1][x] != 1 && y + 1 < N) return true;
	}
	else { // ������ �밢�� �Ʒ��� �̵�
		if (arr[y][x + 1] != 1 && arr[y + 1][x] != 1 && arr[y + 1][x + 1] != 1 && y + 1 < N && x + 1 < N) {
			return true;
		}
	}

	return false;
}

void solve(int shape, int y, int x) {
	if (y == N - 1 && x == N - 1) { // ����
		ans++;
		return;
	}

	if (shape == 0) { // ���� 
		if (check(0, y, x)) { 
			solve(0, y, x + 1); 
		}
		if (check(2, y, x)) {
			solve(2, y + 1, x + 1);
		}
	}
	else if (shape == 1) { // ���� 
		if (check(1, y, x)) solve(1, y + 1, x);
		if (check(2, y, x)) {
			solve(2, y + 1, x + 1);
		}
	}
	else { // �밢��
		if (check(0, y, x)) solve(0, y, x + 1);
		if (check(1, y, x)) solve(1, y + 1, x);
		if (check(2, y, x)) {
			solve(2, y + 1, x + 1);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][1] = 1;
	solve(0, 0, 1);

	printf("%d", ans);

	return 0;
}