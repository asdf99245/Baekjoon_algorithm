// �޴��� ����
// https://www.acmicpc.net/problem/5670

#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

double total = 0;
string dict[100001];

struct Trie {
	bool finish;
	Trie* next[26];

	Trie() :finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i])
				delete next[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int curr = *key - 'a';
			if (!next[curr])
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}

	
	void search(const char* key, double cnt) {
		if (*key == '\0') { // ���ڿ� ���̸� ��ư Ƚ�� ���ϰ� ����
			total += cnt;
			return;
		}
		int ind = *key - 'a';
		if (cnt == 0) { // ó�� �ε����� ������ ��ư�� �������Ѵ�
			next[ind]->search(key + 1, cnt + 1);
			return;
		}

		// ��� ���ڿ��� ���� �ε����� key���� Ȯ��
		bool flag = true;
		for (int i = 0; i < 26; i++) {
			if (i != ind && next[i]) {
				flag = false;
				break;
			}
		}

		if (!flag) { // �ƴ϶�� ��ư ������
			next[ind]->search(key + 1, cnt + 1);
		}
		else { // �´ٸ�
			if (finish) // ��������� ���ڿ��� ������ �ִ� �ܾ��� ��ư�� �������Ѵ�
				next[ind]->search( key + 1, cnt + 1);
			else 
				next[ind]->search(key + 1, cnt);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int i;

	while (1) {
		cin >> n;
		if (cin.eof()) return 0; // ����� ������ ����
		Trie* root = new Trie; // �� Trie ����
		for (i = 0; i < n; i++) {
			cin >> dict[i];
			root->insert(dict[i].c_str()); // �ܾ� Trie�� ����
		}
		
		for (i = 0; i < n; i++) { 
			root->search(dict[i].c_str(),0); // �� �ܾ ��ư Ƚ�� ����
		}

		// �Ҽ��� ��°�ڸ����� �ݿø�
		cout << fixed;
		cout.precision(2);
		cout << total / n << '\n';
		total = 0;
		delete root;
	}

	return 0;
}