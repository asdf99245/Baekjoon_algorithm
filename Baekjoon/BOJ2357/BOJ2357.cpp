//�ּڰ��� �ִ�
//https://www.acmicpc.net/problem/2357

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

vector<pair<int,int>> tree;
int arr[100001];

pair<int,int> init(int node ,int start ,int end) {
	if (start == end) { // ���� ����Ͻ�
		tree[node].first = tree[node].second = arr[start]; // �ּڰ� �ִ� ����
		return tree[node];
	}

	int mid = (start + end) / 2; 

	// left child�� right child�� �̵�
	pair<int, int> l = init(node * 2, start, mid);
	pair<int, int> r = init(node * 2 + 1, mid + 1, end);
	
	// ���� ������ �ּڰ��� �ִ��� �ڽ� ��忡������ �����ش�
	tree[node].first = min(l.first, r.first);
	tree[node].second = max(l.second, r.second);
	return tree[node];

}

pair<int, int> find(int node, int start, int end, int left, int right) {
	if (right < start || left > end) { // ������ �Ѿ����
		return {INT_MAX ,0 };
	}
	if (left <= start && end <= right) { // �����ȿ� ���Եɶ�
		return tree[node];
	}

	int mid = (start + end) / 2;
	// left child �� right child ������ �������� �ִ񰪰� �ּڰ��� ���Ѵ�
	pair<int, int> l = find(node * 2, start, mid, left, right);
	pair<int, int> r = find(node * 2 + 1, mid + 1, end, left, right);

	return { min(l.first,r.first) , max(l.second, r.second) };
}

int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	// Ʈ�� ������ ����
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	init(1, 1, N);

	for (i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pair<int, int> ans = find(1, 1, N, a, b);
		printf("%d %d\n", ans.first, ans.second);
	}

	return 0;
}