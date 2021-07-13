// �߿�
// https://www.acmicpc.net/problem/2002

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> mp;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, i;
	cin >> n;
	string s;
	int ans = 0;

	for (i = 0; i < n; i++) { // ���� ������� ��ȣ�� �ű�
		cin >> s;
		mp[s] = i;
	}

	for (i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	// ���� ���߿� ���� �������� ������ ���� ���� ã�´�
	for (i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mp[v[i]] > mp[v[j]]) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}