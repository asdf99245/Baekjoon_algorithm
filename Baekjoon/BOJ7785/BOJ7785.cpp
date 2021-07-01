// ȸ�翡 �ִ� ���
// https://www.acmicpc.net/problem/7785

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<string> st; // �ߺ� ���� ���� set �̿�

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);

	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s2 == "enter") { // ���
			st.insert(s1);
		}
		else { // ��� 
			st.erase(s1);
		}
	}

	// ���� �������� ���
	for (auto iter = st.rbegin(); iter != st.rend(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}