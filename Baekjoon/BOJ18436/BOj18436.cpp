//������ ���� 37
//https://www.acmicpc.net/problem/18436

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 100000
using namespace std;

int arr[MAX + 1];
vector<int> tree;

int init(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start] % 2; // Ȧ���� 1 ¦���� 0
		return tree[node];
	}

	int mid = (start + end) / 2;

	// ���� ���� Ʈ���� ������ ���� Ʈ���� �̵�
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int update(int node, int start, int end, int i, int x) {
	if (start > i || end < i) return tree[node]; // index�� �����ȿ� ���ٸ� ����
	if (start == end) // i ��° �ε������ ����
		return tree[node] = x;

	int mid = (start + end) / 2;

	return tree[node] = update(node * 2, start, mid, i, x) + update(node * 2 + 1, mid + 1, end, i, x);
}

int query(int node, int start, int end , int left , int right) {
	if (start > right || end < left) // ������ �ٱ��̸� 0������
		return 0;
	if (left <= start && end <= right) { // ������ ���Եȴٸ� �����ش�
		return tree[node];
	}

	int mid = (start + end) / 2;

	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	int n, m, i;
	scanf("%d", &n);
	int h = (int)ceil(log2(n)); 
	int tsize = (1 << (h + 1));	// tree ������
	tree.resize(tsize);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	init(1, 1, n); // Ʈ�� ����

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) { // ����
			update(1, 1, n, b, c % 2);
		}
		else if (a == 2) { // ¦���� ��
			printf("%d\n", c - b + 1 - query(1, 1, n, b, c)); // ���� ������ Ȧ���� ������ ���� ¦��
		}
		else { // Ȧ���� ��
			printf("%d\n", query(1, 1, n, b, c));
		}
	}

	return 0;
}