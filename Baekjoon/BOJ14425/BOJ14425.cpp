// ���ڿ� ����
// https://www.acmicpc.net/problem/14425

#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

int cnt = 0;

struct Trie {
	bool finish;
	Trie* next[26];

	Trie():finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') { // ���ڿ��� ���̶�� ǥ��
			finish = true;
			return;
		}
		int curr = *key - 'a';
		if (!next[curr])
			next[curr] = new Trie();
		next[curr]->insert(key + 1);
		
	}

	void find(const char * key) {
		if (*key == '\0') { // ���ڿ��� ���̶��
			if (finish == true) cnt++; // Ʈ���̿� �����ϴ� �ܾ��� ���� ����
			return;
		}
		int curr = *key - 'a';
		if (!next[curr]) // ��������� �κй��ڿ��� ���� ���ڿ��̶��
			return;

		next[curr]->find(key + 1);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int i;

	Trie* root = new Trie;
	string s;
	for (i = 0; i < n; i++) {
		cin >> s;
		root->insert(s.c_str()); // Ʈ���̿� ���ڿ��� ����
	}

	for (i = 0; i < m; i++) {
		cin >> s;
		root->find(s.c_str());
	}

	cout << cnt;
	return 0;
}