// ���̱�
// https://www.acmicpc.net/problem/14725

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Trie {
	bool finish = false;
	map<string, Trie> next;
};

void insert(Trie& t, vector<string> v, int ind) {
	if (ind == v.size()) { // �迭 ���϶� ����
		t.finish = true;
		return;
	}

	if (t.next.count(v[ind]) == 0) { // map�� ���� ���ٸ� ���� 
		t.next[v[ind]] = Trie();
	}

	insert(t.next[v[ind]], v, ind + 1); // child�� ���� �ε��� �� ����
}

void print(Trie& t, int dep) {

	for (auto child : t.next) { // ��� child�� ����
		for (int i = 0; i < dep; i++) { // ���� ���̸�ŭ -- ���
			cout << "--";
		}

		cout << child.first << "\n"; 

		print(child.second, dep + 1); // ���� child��
	}
}

int main() {
	int n;
	cin >> n;
	int i;
	Trie root;

	for (i = 0; i < n; i++) {
		int k;
		cin >> k;
		vector<string> v(k);
		for (int j= 0; j < k; j++) {
			cin >> v[j];
		}
		insert(root, v, 0);
	}

	print(root, 0);

	return 0;
}