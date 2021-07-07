// A�� B
// https://www.acmicpc.net/problem/12904

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int canChange(string s, string t) {
	int i;

	for (i = t.length() - 1; i >= 0; i--) { // t ���ڿ��� ���������� �Ųٷ� Ȯ��
		if (s == t) return 1; // ���ڿ��� �������ٸ� ����
		char a = t[i];
		t = t.substr(0, i); // ���� ���ڰ� A�� B�� �߶���Ѵ�
		if (a == 'B') { // B��� �ڸ� ���ڿ��� ������
			reverse(t.begin(), t.end());
		}
	}

	return 0;
}

int main() {
	string s, t;
	cin >> s >> t;

	printf("%d", canChange(s, t));
	return 0;
}