// �̸� ���ϱ�
// https://www.acmicpc.net/problem/16900
// kmp ������ �ʿ䰡 �ִ�

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long  ll;

vector<ll> getPi(string s) {
	int i;
	// s�� i�ε��������� �κ� ���ڿ��� ��ġ�� ���̻�, ���λ� �迭�� �ִ� ����
	vector<ll> pi(s.size(), 0);
	int j = 0;
	for (i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) 
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}

	return pi;
}

int main() {
	string s;
	ll n;

	cin >> s >> n;
	vector<ll> pi = getPi(s);
	cout << s.size() + (n - 1) * (s.size() - pi[s.size() - 1]);
	return 0;
}