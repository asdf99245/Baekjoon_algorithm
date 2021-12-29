// ����ȯ
// https://www.acmicpc.net/problem/2482

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MOD 1000000003
using namespace std;

int dp[1001][1001];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		dp[i][1] = i;
		dp[i][0] = 0;
	}

	for (int i = 4; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			// i���� ���� ������ j���� ���� ��� = ����� ������� vs �� ����
			// ����� ���� = ���� ������ �����Ѱ��� i - 2���� j - 1�� 
			// ���������� = ���� ���� ���� ������ i - 1���� j ��
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	printf("%d", dp[n][k] % MOD);
}