#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int x;
    int y;
    int num;
    Node* left;
    Node* right;
};

vector<Node> tree;
vector<int> res1;
vector<int> res2;

bool cmp(Node& a, Node& b) { // depth�� ���� �������� ����
    return a.y > b.y;
}

void makeTree(Node* root, Node* child) {
    if (root->x > child->x) {  // root���� ���ʿ� ������ left child
        if (root->left == NULL) root->left = child;
        else makeTree(root->left, child);
    }
    else { // root���� �����ʿ� ������ right child
        if (root->right == NULL) root->right = child;
        else makeTree(root->right, child);
    }
}

void preorder(Node* root, vector<int>& res) { // root -> left child -> right child
    res.push_back(root->num);
    if (root->left != NULL)
        preorder(root->left, res);
    if (root->right != NULL)
        preorder(root->right, res);
}

void postorder(Node* root, vector<int>& res) { // left child -> right child -> root
    if (root->left != NULL)
        postorder(root->left, res);
    if (root->right != NULL)
        postorder(root->right, res);
    res.push_back(root->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for (int i = 0; i < nodeinfo.size(); i++) {
        Node tmp;
        tmp.x = nodeinfo[i][0];
        tmp.y = nodeinfo[i][1];
        tmp.num = i + 1;
        tmp.left = tmp.right = NULL;
        tree.push_back(tmp);
    }

    sort(tree.begin(), tree.end(), cmp); // depth ������ �������� ����
    Node* root = &tree[0];
    for (int i = 1; i < nodeinfo.size(); i++) {
        makeTree(root, &tree[i]); // Ʈ�� ����
    }

    vector<int> res1, res2;
    preorder(root, res1); // ���� ��ȸ
    postorder(root, res2); // ���� ��ȸ
    answer.push_back(res1);
    answer.push_back(res2);
    return answer;
}