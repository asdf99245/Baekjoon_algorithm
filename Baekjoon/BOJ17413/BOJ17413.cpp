// �ܾ� ������ 2 
// https://www.acmicpc.net/problem/17413

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

bool tag = false;

int main() {
	string s;
	getline(cin, s); // ���� �����ؼ� ���� �Է�
	
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<' || s[i] == '>') { // �±װ� �����ų� ������
			if (s[i] == '<') { // ���� �±��϶� ���ÿ� ���ڿ��� �ִٸ� ��� ���
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
			}
			tag = !tag; // �±װ� ���������� true ������ false
			cout << s[i];
			continue;
		}

		if (tag) { // �����±� �϶��� �״�� ���
			cout << s[i];
		}
		else { // �±װ� �����ٸ�
			if (s[i] == ' ') { // �����Ͻ� ���� �ܾ� �ݴ�� ���
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			else // ���ÿ� �����ϳ��� ����
				st.push(s[i]);
		}
	}

	if (!st.empty()) { // ���ÿ� ���� �ܾ �ִٸ� ���
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
	}
	return 0;
}