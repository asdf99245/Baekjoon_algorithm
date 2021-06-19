// ������ ����
// https://www.acmicpc.net/problem/1780

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[3];
int** arr;

bool checkPaper(int row, int col, int N) { // ������ ��� ���� ������ �˻��Ѵ�
	int i, j;
	bool flag = true;
	int a = arr[row][col];
	for (i = row; i < row + N; i++) {
		for (j = col; j < col + N; j++) {
			if (a != arr[i][j]) {
				flag = false;
				break;
			}
		}
		if (!flag)break;
	}

	return flag;
}
void cuttingPaper(int row, int col, int N) {
	
	if (checkPaper(row, col, N)) { // �ϳ��� ���ڷ� �Ǿ��ִٸ�
		int a = arr[row][col];
		if (a == -1) {
			cnt[0] ++;
		}
		else if (a == 0) {
			cnt[1] ++;
		}
		else {
			cnt[2] ++;

		}
	}
	else { // �ƴ϶�� 9�������� �ڸ���
		N /= 3; // ���� ���� 3���
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cuttingPaper(row + i * N, col + j * N, N);
			}
		}
	}
}

int main() {
	int N, i,j;
	scanf("%d", &N);
	arr = new int*[N];
	for (i = 0; i < N; i++) {
		arr[i] = new int[N];
		for (j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	cuttingPaper(0, 0, N); // ���̸� �ڸ���

	for (int i = 0; i < 3; i++) // -1 ,0 ,1 �� ���� ���
		printf("%d\n", cnt[i]);

	return 0;
}