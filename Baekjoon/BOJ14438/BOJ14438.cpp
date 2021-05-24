//������ ���� 17
//https://www.acmicpc.net/problem/14438

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#define MAX 100000
using namespace std;

int arr[MAX + 1];
vector<int> tree;

int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;

	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end)); // ���ʰ� ������ ������ �� ���� ������ �����ش�
}

int update(int node, int start, int end, int index, int value) {
	if (index < start || index > end) // ���� �ȿ� �ε����� ���ٸ�
		return tree[node];

	if (start == end) { // index���
		return tree[node] = value;
	}

	int mid = (start + end) / 2;

	return tree[node] = min(update(node * 2, start, mid, index, value), update(node * 2 + 1, mid + 1, end, index, value)); 
}

int query(int node, int start, int end, int left, int right) {
	if (right < start || left > end) // ���� ���̱� ������ ���� ū �� ��ȯ
		return INT_MAX;
	if (left <= start && end <= right) // ���� ���̶�� ��ȯ
		return tree[node];

	int mid = (start + end) / 2;

	return  min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right)); // �� �������� ��ȯ
}

int main() {
	int n, m, i;
	scanf("%d", &n);
	int h = (int)ceil(log2(n));
	int tsize = 1 << (h + 1);
	tree.resize(tsize); // Ʈ�� ������ ����
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	init(1, 1, n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) { // ����
			update(1, 1, n, b, c);
		}
		else { // �������� ���� ������ 
			printf("%d\n", query(1, 1, n, b, c));
		}
	}
	return 0;
}