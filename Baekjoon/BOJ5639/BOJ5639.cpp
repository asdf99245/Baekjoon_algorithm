//���� �˻� Ʈ��
//https://www.acmicpc.net/problem/5639

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};
vector<int> v;

Node* add(Node *node ,int n) {
	if (node == NULL) { // ��尡 ���ٸ� �����Ͽ� �ش�
		node = new Node();
		node->key = n;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	if (n < node->key) { // �θ� ����� Ű���� �۴ٸ� ��������
		node->left = add(node->left, n); 
	}
	else { // �θ� ����� Ű���� �۴ٸ� ����������
		node->right = add(node->right, n);
	}

	return node;
}

void postOrder(Node* node) { // left -> right -> root
	if(node->left != NULL) // left child�� �ִٸ� ��������
		postOrder(node->left);
	if (node->right != NULL) // right child�� �ִٸ� ����������
		postOrder(node->right);

	printf("%d\n", node->key); // ��Ʈ key ǥ��
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i = 0, n;
	Node* parent = NULL; // ��Ʈ ���
	while (cin >> n) {
		v.push_back(n);
		parent = add(parent, n); // Ʈ�� ����
	}

	postOrder(parent);

	return 0;
}