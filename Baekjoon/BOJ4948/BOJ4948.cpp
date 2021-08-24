// ����Ʈ�� ����
// https://www.acmicpc.net/problem/4948

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 123456 * 2
using namespace std;

int arr[MAX + 1];

int main() {
	int n;

	// �����佺�׳׽��� ü �̿�
	for (int i = 2; i <= MAX; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= MAX; i++) {
		if (arr[i] == 0)continue;
		for (int j = i + i; j <= MAX; j += i) {
			arr[j] = 0; // i �ڱ� �ڽ��� ������ i�� ����� 0����
		}
	}

	//���� ���� �Ҽ��̴�

	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		
		int cnt = 0;
		for (int i = n + 1; i <= n * 2; i++) {
			if (arr[i] != 0) cnt++; // �Ҽ��� ������ ���Ѵ�
		}

		printf("%d\n", cnt);
	}
	return 0;
}