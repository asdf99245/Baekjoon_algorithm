// ���� ū ���簢��
// https://www.acmicpc.net/problem/1915

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 1000
using namespace std;

int n, m;
int arr[MAX + 1][MAX + 1];
int dp[MAX + 1][MAX + 1];
int maxSize = 0;

bool check(int i, int j) {
	return arr[i][j] && arr[i - 1][j] && arr[i][j - 1] && arr[i - 1][j - 1];
}

int main() {
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1) { 
				dp[i][j] = 1;
				maxSize = 1; // �迭�� 1�� �ϳ��� ������ ���� ū ���簢���� ũ��� �ּ� 1�̴�
			}
		}
	}

	if (n == 1 || m == 1) { // ���̳� ���� �����̶��
		printf("%d", maxSize * maxSize);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) continue;
			if (check(i, j)) { // ����,����,���� �� �밢�� ���� ���� �����Ѵٸ�
				int minValue = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
				dp[i][j] = minValue + 1; // 3�� �� ���������� + 1�� ���� ���� �������ִ��� ���簢���� �ִ� ����
				maxSize = max(maxSize, dp[i][j]); // ���簢���� ���� ū ���̸� ���Ѵ�
			}
		}
	}

	printf("%d", maxSize * maxSize);

	return 0;
}