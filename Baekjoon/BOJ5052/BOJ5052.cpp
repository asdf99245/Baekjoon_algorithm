// ��ȭ��ȣ ���
// https://www.acmicpc.net/problem/5052

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

bool flag;

bool compare(string a, string b) {
	return a.length() < b.length();
}

vector<string> v;

struct Trie {
	bool finish; // ���� ǥ��
	Trie* next[11];

	Trie() :finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 10; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') { // ���ڿ��� ��
			finish = true;
		}
		else {
			if (finish) flag = false; // ���� �̹� �ִ� ��ȭ��ȣ�� �����ؼ� �Ѿ�ٸ�
			int curr = *key - '0';
			if (next[curr] == NULL) 
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}
};

int main() {
	int T, n;
	string num;
	cin >> T;

	while (T > 0) {
		cin >> n;
		flag = true;
		Trie* root = new Trie; // Ʈ���� ����
		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end(), compare); // ���ڿ� ���� �������� ����

		for (int i = 0; i < n; i++) {
			root->insert(v[i].c_str()); 
		}

		if (!flag) { // �ٸ� ��ȭ��ȣ�� ������ ��ȣ�� �ִٸ� 
			cout << "NO\n";
		}
		else
			cout << "YES\n";

		v.clear();
		T--;
	}

	return 0;
}