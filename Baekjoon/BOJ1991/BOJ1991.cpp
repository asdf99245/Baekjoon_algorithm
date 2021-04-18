//Ʈ�� ��ȸ
//https://www.acmicpc.net/problem/1991

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<char, pair<char, char>> tree;

void preorder(char root) { // ���� ��� ����ϰ� left child���� �湮 �Ŀ� right child�� �湮
	cout << root; 

	if (tree[root].first != '.') 
		preorder(tree[root].first);

	if (tree[root].second != '.') 
		preorder(tree[root].second);

	return;
}

void inorder(char root) { // left child���� �湮 �Ŀ� ���� ��� ����ϰ� right child�� �湮
	if (tree[root].first != '.')
		inorder(tree[root].first);

	cout << root;

	if (tree[root].second != '.')
		inorder(tree[root].second);
	return;
}

void postorder(char root) { // left child���� �湮 �Ŀ� right child�� �湮�ϰ� ���� ��� ���
	if (tree[root].first != '.')
		postorder(tree[root].first);

	if (tree[root].second != '.')
		postorder(tree[root].second);

	cout << root;
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, n;
	cin >> n;
	for (i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a] = { b,c }; // ������ Ʈ�� ����
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	return 0;
}