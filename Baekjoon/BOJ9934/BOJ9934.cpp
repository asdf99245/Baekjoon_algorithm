//���� ���� Ʈ��
//https://www.acmicpc.net/problem/9934

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
vector<int> tree[11];

void getTree(int l, int r,int depth) {
	int root = (l + r) / 2; // ��Ʈ ���
	tree[depth].push_back(v[root]);
	if (l == r) return; // �� �̻� child�� ���ٸ� ����
	getTree(l, root - 1, depth + 1); // ���� sub tree�� ����
	getTree(root + 1, r, depth + 1); // ������ sub tree�� ����
}
int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < pow(2, k) - 1; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	getTree(0, v.size() - 1, 1);
	for (int i = 1; i <= k; i++) { // ������ i�� ���ú��� ���
		for (int j = 0; j < tree[i].size(); j++) {
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}
	return 0;
}