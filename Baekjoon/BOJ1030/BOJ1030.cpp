// ����Ż ���
// https://www.acmicpc.net/problem/1030

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long int s, N, K;

int solve(int y, int x, long long int len) {
	if (len == 1) return 0; // ���� ���̰� 1�� �Ǹ� �Ͼ��
	long long int sub = len / N; // N * N���� �κ� ���簢���� �� ���̴� => ���� �� ���� / N 
	if (y >= sub * (N - K) / 2 && y < sub * (N + K) / 2 && x >= sub * (N - K) / 2 && x < sub * (N + K) / 2) // ���簢���� ��� K*K������ �ִٸ� ������ 
		return 1;
	return solve(y % sub, x % sub, sub); // ���� ��ǥ�� �ش��ϴ� �κ� ���簢������
}

int main() {
	int r1, r2, c1, c2;
	scanf("%lld %lld %lld %d %d %d %d", &s, &N, &K, &r1, &r2, &c1, &c2);
	long long int len = pow(N, s); // �ð��� s�϶� ���� ���� = N�� s����
	for (int i = r1; i <= r2; i++) { 
		for (int j = c1; j <= c2; j++) {
			printf("%d", solve(i, j, len));
		}
		printf("\n");
	}

	return 0;
}