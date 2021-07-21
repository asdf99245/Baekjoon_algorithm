// ���ڿ� ����
// https://www.acmicpc.net/problem/9935

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char st[1000000 + 1];

bool check(int top, string es, int l) {
	int i;
	// ���� ���ڿ��� �ִ��� Ȯ��
	for (i = l - 1; i >= 0; i--) {
		if (st[top--] != es[i]) return false;
	}

	return true;
}

void explode(string s, string es) {
	int i;
	int el = es.length();
	int top = 0;
	char last = es[el - 1];

	for (i = 0; i < s.length(); i++) {
		st[top++] = s[i]; // ���ÿ� push
		if (s[i] == last) { // ���� ���ڿ��� ������ ���ڶ��
			if (check(top - 1, es, el)) { // ���� ���ڿ��� �����Ѵٸ� ���̸�ŭ pop
				top -= el;
			}
		}
	}

	if (top == 0) { // ���ڿ��� �������ٸ�
		cout << "FRULA";
	}
	else {
		for (i = 0; i < top; i++) {
			cout << st[i];
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s, es;
	cin >> s >> es;

	explode(s, es);
	return 0;
}