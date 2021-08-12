// Ʈ��
// https://www.acmicpc.net/problem/10838

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

struct Node {
	int color;
	int parent;
};

Node tree[100001];
int check[100001];
int ch = 0;

int getLca(int a, int b) { 
	if (a == b) return a; // ���� ����� ��尡 lca

	ch++; // ��� �湮�� üũ�ϱ� ���� ��
	int dist = 0;
	while (dist <= 1000) { // �Ÿ��� 1000�� �ִ��̹Ƿ�
		// root�� �ƴ϶��
		if (a != 0) {
			if (check[a] == ch) // �� ��尡 ���� ó�� �湮�� ����� lca��
				return a;
			check[a] = ch; // �湮 üũ
			a = tree[a].parent; 
		}
		if (b != 0) {
			if (check[b] == ch)
				return b;
			check[b] = ch;
			b = tree[b].parent;
		}
		dist++; 
	}
	
	return 0; // ��Ʈ���
}

void paint(int a, int b, int c) {
	int lca = getLca(a, b);
	int i;
	
	// lca���� ������ ���� c�� ����
	while (a != lca) { 
		tree[a].color = c;
		a = tree[a].parent;
	}

	while (b != lca) {
		tree[b].color = c;
		b = tree[b].parent;
	}
}

void move(int a, int b) {
	tree[a].parent = b; // b�� child�� a��带 �̵�
}

int count(int a, int b) {
	int lca = getLca(a, b);
	unordered_set<int> colors; // ������ �ߺ����� �ʰ� set�̿�

	while (a != lca) {
		colors.insert(tree[a].color);
		a = tree[a].parent;
	}

	while (b != lca) {
		colors.insert(tree[b].color);
		b = tree[b].parent;
	}

	return colors.size(); // ���� �������� ��ȯ
}

int main() {
	int n, k, i;
	scanf("%d %d", &n, &k);
	// tree[0] => root
	tree[0].color = 0;
	tree[0].parent = NULL;
	// root�� �����Ѵ�
	for (i = 1; i < n; i++) {
		tree[i].color = 0;
		tree[i].parent = 0;
	}

	for (i = 0; i < k; i++) {
		int r, a, b, c;
		scanf("%d %d %d", &r, &a, &b);
		switch (r) {
			case 1:
				scanf("%d", &c);
				paint(a, b, c);
				break;
			case 2:
				move(a, b);
				break;
			case 3:
				printf("%d\n", count(a, b));
		}
	}

	return 0;
}