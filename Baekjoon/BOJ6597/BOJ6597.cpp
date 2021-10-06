// Ʈ�� ����
// https://www.acmicpc.net/problem/6597

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pre, in;
int inTree[26];

void post_order(int pre_left, int pre_right,int in_left,int in_right) {
	if (pre_left > pre_right) return; // left �� right���� ū ��� ����

	char root = pre[pre_left]; // preorder���� subtree�� root�� ���� ���� ���
	int rootIdx = inTree[root - 'A']; // inorder������ root�� ��ġ 
	/* 
	inorder root�� ������ left sub tree, inorder root�� �������� right sub tree 
	inorder���� sub tree�� ���̸� ���� preorder�� sub tree�� ��ġ�� ã�´�.
	*/
	post_order(pre_left + 1, pre_left + rootIdx - in_left, in_left, rootIdx - 1); 
	post_order(pre_left + rootIdx - in_left + 1, pre_right, rootIdx + 1, in_right); 
	cout << root; // post order�̹Ƿ� ���� ���߿� root ���
}

int main() {
	while (cin >> pre >> in) {
		for (int i = 0; i < in.length(); i++) {
			int idx = in[i] - 'A';
			inTree[idx] = i;
		}
		post_order(0, pre.length() - 1, 0, in.length() - 1);
		cout << '\n';
	}

	return 0;
}