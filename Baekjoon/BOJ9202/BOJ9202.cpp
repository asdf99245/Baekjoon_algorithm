// Boggle
// https://www.acmicpc.net/problem/9202
// 20%���� Ʋ�ȴٰ� ����

#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <unordered_set>
using namespace std;

int total = 0, maxL = 0;
unordered_set<string> st;
string board[4];
bool visited[4][4];
int score[] = { 0,0,0,1,1,2,3,5,11 };
int dy[] = { 1,-1,0,0,1,1,-1,-1 };
int dx[] = { 0,0,1,-1,1,-1,1,-1 };

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
			int curr = *key - 'A';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}
};

void search(Trie* t, int y, int x, string s) {
	if (s.length() > 8) { // 8���� �̻��� ������ ����
		return;
	}
	int ind = board[y][x] - 'A'; // ���ĺ��� �ε���
	if ((t->next[ind]) == NULL) { // �ܾ������ �������� ����
		return;
	}

	visited[y][x] = true;
	s += board[y][x];

	if (t->next[ind]->finish) { // �ܾ������ �ִ� �ܾ��� set�� ����
		st.insert(s);
	}

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		// �湮���� ���� ������ �ֻ����� Ž��
		if (0 <= ny && ny < 4 && 0 <= nx && nx < 4 && !visited[ny][nx]) {
			search(t->next[ind], ny, nx, s);
		}
	}

	visited[y][x] = false;
}

int main() {
	int w, b;
	cin >> w;
	int i, j, k;
	Trie* root = new Trie;

	for (i = 0; i < w; i++) {
		string word;
		cin >> word;
		root->insert(word.c_str()); // �ܾ������ �ܾ ����
	}

	cin >> b;
	for (i = 0; i < b; i++) {
		for (j = 0; j < 4; j++) {
			cin >> board[j];
		}

		// �� �ֻ����� ���� �ܾ�ã�� ����
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				search(root, j, k, "");
			}
		}

		string res = "";
		// ���� �� ������ �ܾ ã�´�
		for (string word : st) {
			int l = word.length();
			if (l == maxL) { // ���������� �ռ����� ����
				res = res < word ? res : word;
			}
			else if (l > maxL) { 
				maxL = l;
				res = word;
			}
			total += score[l];
		}

		cout << total << " " << res << " " << st.size() << "\n";
		// �ʱ�ȭ
		total = 0;
		maxL = 0;
		st.clear();
	}


	return 0;
}