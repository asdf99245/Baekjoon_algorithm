// ������ 
// https://www.acmicpc.net/problem/1309

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
long long int dp[100001][3]; // xx xo ox 

void solve(int idx) {
	if (idx == N) {
		return;
	}

	dp[idx][0] = (dp[idx - 1][0] + dp[idx - 1][1] + dp[idx - 1][2]) % 9901; // ���� row�� �ƹ� ������ ���ٸ� ���� row�� 3���� ��� ��� ����
	dp[idx][1] = (dp[idx - 1][0] + dp[idx - 1][2]) % 9901; // ���� row�� ������ ĭ�� ���ڰ� �ִٸ� ���� row�� �ƹ� ������ ���� ���� ���ڰ� ���ʿ� �ִ� ���
	dp[idx][2] = (dp[idx - 1][0] + dp[idx - 1][1]) % 9901; // ���� �ݴ��

	solve(idx + 1);
}

int main() {
	scanf("%d", &N);
	dp[0][0] = 1; dp[0][1] = 1; dp[0][2] = 1; 
	solve(1);

	long long int ans = dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]; 
	printf("%lld", ans % 9901);
	return 0;
}