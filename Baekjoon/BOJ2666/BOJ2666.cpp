// ���幮�� �̵�
// https://www.acmicpc.net/problem/2666

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

int m;
int seq[21];
int dp[21][21][21]; // ù��° => ���� ����, (�ι�°,����°) => ���� ����


int solve(int cnt, int first, int second) {
	if (cnt == m) return 0; // ��� ������ ���
	int& ret = dp[cnt][first][second];
	if (ret != -1) return ret; // �̹� ���� ���� ��ȯ

	// ���� ����� ���� ���� ������ �Ÿ��� ���������ϴ� ������ �� => abs(prev-next)
	int a = solve(cnt + 1, seq[cnt], second) + abs(first - seq[cnt]); // ù��° ���� ��� ���� ������ ���
	int b = solve(cnt + 1, first, seq[cnt]) + abs(second - seq[cnt]); // �ι�° ���� ��� ���� ������ ���
	
	return ret = min(a,b); // ���� �� ���� ���� ���Ѵ�.
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &seq[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d",solve(0, a, b));
	return 0;
}