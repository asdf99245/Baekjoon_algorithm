// ���ڿ� ����
// https://www.acmicpc.net/problem/21941

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> mp;
string s;
vector<string> keys;
int dp[1001];

int dfs(int ind) {
	if (ind >= s.length()) 
		return 0;

	if (dp[ind] != 0) 
		return dp[ind];

	for (int i = 0; i < keys.size(); i++) {
		string key = keys[i];
		int score = mp[key];
		// ���ڿ� key�� �����ϴ��� Ȯ��
		if (ind + key.length() <= s.length()) {
			int k;
			for (k = 0; k < key.length(); k++) {
				if (key[k] != s[ind + k]) { 
					break;
				}
			}

			if (k == key.length()) // �κй��ڿ��� key�� ����
				dp[ind] = max(dp[ind], dfs(ind + key.length()) + score); // ���ڿ� ���� ������ 
		}
	}
	

	dp[ind] = max(dp[ind], dfs(ind + 1) + 1); // ���� �Ѱ� �����ϰ� 1�� 

	return dp[ind];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string a;
		int score;
		cin >> a >> score;
		keys.push_back(a);
		mp[a] = score;
	}

	cout << dfs(0);
	return 0;
}