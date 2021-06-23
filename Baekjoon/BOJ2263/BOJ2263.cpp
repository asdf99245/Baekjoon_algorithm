//Ʈ���� ��ȸ
//https://www.acmicpc.net/problem/2263

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void preorder(vector<int> &inorder, vector<int> &postorder, vector<int> &index , int inLeft , int inRight, int postLeft, int postRight) {
	if (inLeft > inRight || postLeft > postRight) return; // ���ʳ��� �����ʳ��� �Ѿ�� ����
	int root = postorder[postRight];
	// ���� ��ȸ�� ������ ���� ��Ʈ
	printf("%d ", root); 
	int rootIndex = index[root]; // ������ȸ���� ��Ʈ�� �ε���

	preorder(inorder, postorder, index, inLeft , rootIndex - 1, postLeft, postLeft + rootIndex - inLeft - 1); // ���� ����Ʈ��
	preorder(inorder, postorder, index, rootIndex + 1, inRight, postLeft + rootIndex - inLeft , postRight -1); // ������ ����Ʈ��
}

int main() {
	int n, i, j;
	scanf("%d", &n);


	vector<int> postorder(n);
	vector<int> inorder(n);
	vector<int> index(n+1);

	for (i = 0; i < n; i++) {
		scanf("%d", &inorder[i]);
		index[inorder[i]] = i; // ���� ��ȸ ���鿡 ���� �ε��� ����
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &postorder[i]);
	}
	preorder(inorder, postorder, index, 0, n - 1, 0, n - 1);
	return 0;
}