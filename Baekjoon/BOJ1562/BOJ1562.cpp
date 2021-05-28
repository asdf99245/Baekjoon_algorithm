//��� ��
//https://www.acmicpc.net/problem/1562

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int mod = 1000000000;
long long dp[101][10][1 << 10]; //[i][j][k] i => �ڸ��� j => 0~9 ���� k => 0~9���� ���� ��Ʈ�� üũ


int main() {
	int n, i, j, k;
	scanf("%d", &n);

	for (i = 1; i <= 9; i++) { // 0���� ���� �Ҽ� �����Ƿ� ����
		dp[1][i][1 << i] = 1; 

	}

	for (i = 2; i <= n; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k <= 1023; k++) {
				if (j == 0) { // 0�� ��� ������ �ڸ����� +1�� ���� ����
					dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % mod;
				}
				else if (j == 9) { // 9�� ��� ������ �ڸ����� -1�μ��� ����
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % mod;
				}
				else { // ������ �ڸ����� ������� +1 ,-1�� ��
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k] % mod;
				}
			}

		}
	}

	long long ans = 0;

	for (i = 0; i <= 9; i++) {
		ans += dp[n][i][1023];
	}

	printf("%lld", ans % mod);

	return 0;

}