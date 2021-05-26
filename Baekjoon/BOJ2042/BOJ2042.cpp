//구간 합 구하기
//https://www.acmicpc.net/problem/2042
//자꾸 100%에서 틀리다고 나오는데 이유를 모르겠다

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 1000000
using namespace std;

long long arr[MAX + 1];
vector<long long> tree;

long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;

	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int index, int value) {
	if (index < start || index > end) {
		return;
	}
	if (start == end) {
		tree[node] = (long long)value;
		return; 
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, index, value);
	update(node * 2 + 1, mid + 1, end, index, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;

	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	int n, m, k, i;
	scanf("%d %d %d", &n, &m, &k);
	int h = (int)ceil(log2(n));
	int tsize = (1 << (h + 1));
	tree.resize(tsize);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}

	init(1, 1, n);

	for (i = 0; i < m + k; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else if (a == 2) {
			printf("%lld\n", query(1, 1, n, b, c));
		}
	}
	return 0;
}