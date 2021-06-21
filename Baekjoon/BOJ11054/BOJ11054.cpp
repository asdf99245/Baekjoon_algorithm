// ���� �� ������� �κ� ����
// https://www.acmicpc.net/problem/11054

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[1001];
int dp[1001];
int dp2[1001];

int main() {
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = dp2[i] = 1;
	}
	
	// �տ������� i��° �ε��������� ���� �� �������� �κм����� ���Ѵ� 
	for (i = 2; i <= N; i++) {
		for (j = 1; j < i; j++) {
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	// �ڿ������� i��° �ε��������� ���� �� �������� �κм����� ���Ѵ� 
	for (i = N - 1; i >= 1; i--) {
		for (j = N; j >= i + 1; j--) {
			if (arr[i] > arr[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	int ans = 0;
	for (i = 1; i <= N; i++) {
		ans = max(ans, dp[i] + dp2[i] - 1); // i��° �ε����� �������� ������ �������� ������ ���̿� �ߺ��Ǵ� �� -1 ����
	}

	printf("%d", ans);
	return 0;
}
