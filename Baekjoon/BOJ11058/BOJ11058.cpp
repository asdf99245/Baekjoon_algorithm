// 크리보드
// https://www.acmicpc.net/problem/11058

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[101];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i <= 5; i++) { // 1번만 누른게 젤 큼
		dp[i] = i;
}
	for (int i = 6; i <= N; i++) 
	{
		for (int j = 3; j <= i; j++) { // ctrl-a ctrl-c ctrl-v 까지 최소 3회이므로 3부터 시작
			dp[i] = max(dp[i], dp[i - j] * (j - 1));  // ctrl-v를 누른 횟수에 따라 비교
		}

	}

	printf("%lld", dp[N]);
	return 0;
}