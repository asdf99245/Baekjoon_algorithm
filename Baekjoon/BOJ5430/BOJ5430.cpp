// AC
// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

void func(deque<int> v, string f) {
	int i;
	bool rever = false;
	for (i = 0; i < f.length(); i++) {
		if (f[i] == 'D') { // �տ� ���ڸ� ����
			if (v.size() == 0) { // �� �̻� �����Ҽ� ���ٸ� error
				cout << "error\n";
				return;
			}
			if (rever) // ����������� �� ���� ���Ҹ� ����
				v.pop_back();
			else
				v.pop_front();
		}
		else { // �迭�� ������
			rever = !rever;
		}
	}

	if (v.size() == 0) cout << "[]" << '\n';
	else {
		cout << '[';
		if (!rever) { // ������ ���� ��� �տ�������
			for (i = 0; i < v.size() - 1; i++) {
				cout << v[i] << ',';
			}
		}
		else { // �������� ��� �ڿ�������
			for (i = v.size() - 1; i > 0; i--) {
				cout << v[i] << ',';
			}
		}
		cout << v[i] << ']' << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T > 0) {
		string s1;
		int n;
		cin >> s1 >> n;
		char a;
		int num;
		deque<int> dq;
		cin >> a;
		if (n == 0) { 
			cin >> a;
		}
		else { // ������ ���ڸ� ������ ����
			for (int i = 0; i < n; i++) {
				cin >> num >> a;
				dq.push_back(num);
			}
		}
		func(dq, s1);
		T--;
	}
	return 0;
}