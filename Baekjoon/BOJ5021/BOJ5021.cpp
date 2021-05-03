//���� ���
//https://www.acmicpc.net/problem/5021

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, double> mp;
vector<vector<string>> v(3);
vector<string> cand;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i;
	cin >> N >> M;
	string king;
	cin >> king;
	mp[king] = 1; // ���� �����̱⶧���� 1

	for (i = 0; i < N; i++) {
		string child, p1, p2;
		cin >> child >> p1 >> p2;
		v[0].push_back(child); 
		v[1].push_back(p1);
		v[2].push_back(p2);
	}

	// ������ ������� ������ �ʱ� ������ n*n�� ���鼭 ����
	for (i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mp[v[0][j]] = (mp[v[1][j]] + mp[v[2][j]]) / 2;
		}
	}

	for (i = 0; i < M; i++) {
		string s;
		cin >> s;
		cand.push_back(s);
	}

	string ans;
	double max = 0;

	// ������ ������ ����ū �ĺ��� ã��
	for (i = 0; i < cand.size(); i++) {
		if (mp[cand[i]]> max) {
			max = mp[cand[i]];
			ans = cand[i];
		}
	}

	cout << ans;
	return 0;
}