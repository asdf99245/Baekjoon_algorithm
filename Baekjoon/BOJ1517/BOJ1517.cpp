// ���� ��Ʈ
// https://www.acmicpc.net/problem/1517

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int seq[500001];
int arr[500001];
int N;
long long ans = 0;

void merge(int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int index = 0;
	// ������ ������ ���ϸ� ����
	while (i <= m || j <= r) {
		if (i <= m && (j > r || seq[i] <= seq[j])) { // ������ �´ٸ�
			arr[index++] = seq[i++];
		}
		else { // ������ ���� �ʴٸ� ���� ������
			arr[index++] = seq[j++];
			ans += (long long)m - i + 1;
		}
	}

	for (int i = l; i <= r; i++) {
		seq[i] = arr[i - 1];
	}
}

void mergeSort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		// ������ ����� ��������
		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}

int main() {
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++) {
		int a; 
		scanf("%d", &seq[i]);
	}

	mergeSort(0, N - 1);
	printf("%lld", ans);
	return 0;
}