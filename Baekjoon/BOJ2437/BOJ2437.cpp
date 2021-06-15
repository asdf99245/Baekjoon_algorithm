// ����
// https://www.acmicpc.net/problem/2437

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n); // �������� ����

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > sum + 1) { // i��° ���� ���԰� �����պ��� 2 �̻� ũ�ٸ� ������ + 1 �� ���Ը� �����Ұ���
			break;
		}
		sum += arr[i]; // ������
	}

	printf("%d", sum + 1);
	return 0;
}