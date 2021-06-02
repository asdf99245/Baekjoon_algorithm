// ���� ����
// https://www.acmicpc.net/problem/14391

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std; 

int paper[4][4];
int ans = 0;

void getSum(int n , int m) {
	int bit = 1 << (n * m); // �� n * m ���� ĭ�� ������ n*m�ڸ��� ��Ʈ������ ��� ������ ǥ��
	int i, j, k;
	int total;
	for (i = 0; i < bit; i++) {
		total = 0;
		// ������ Ȯ��
		for (j = 0; j < n; j++) {
			int sum = 0;
			for (k = 0; k < m; k++) {
				int a = j * m + k; 
				if ((i & (1 << a)) != 0) { // ��Ʈ�� 1�̸� ����
					sum = sum * 10 + paper[j][k]; // ���η� �̾����ٸ� �ڸ�����ŭ 10 ������
				}
				else { // ���ο��� ���η� �ٲ�����
					total += sum;
					sum = 0;
				}
			}
			total += sum;
		}

		// ������ Ȯ��
		for (j = 0; j < m; j++) {
			int sum = 0;
			for (k = 0; k < n; k++) {
				int a = k * m + j;
				if ((i & (1 << a)) == 0) { // ��Ʈ�� 0�̸� ����
					sum = sum * 10 + paper[k][j];
				}
				else { // ���ο��� ���η� �ٲ�����
					total += sum;
					sum = 0;
				}
			}
			total += sum;
		}

		ans = max(ans, total); // �ִ� ����
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &paper[i][j]);
		}
	}

	getSum(n, m);
	printf("%d", ans);

	return 0;
}