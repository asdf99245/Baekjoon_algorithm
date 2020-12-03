//��ȣ �����
//https://www.acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alpha;
vector<char> code;
char vowels[] = { 'a','e','i','o','u' };

bool checkVow(char alpha) {
	int i;

	for (i = 0; i < 5; i++) {
		if (alpha == vowels[i]) { // ���� �ϳ��� Ȯ��
			return true;
		}
	}
	return false;
}
void DFS(int cnt,int ind, int vowel, int con) {
	if (cnt == l) { // ���ĺ� ������ ����������
		if (vowel < 1 || con < 2) return; // ������ �ּ� 1��, ������ �ּ� 2�� ������ �������� ������ ������� �ʴ´�
		for (int i = 0; i < code.size(); i++) // ��ȣ ��� 
			cout << code[i];
		cout << "\n";
		return;
	}

	for (int i = ind; i < alpha.size(); i++) {
		code.push_back(alpha[i]);
		if (checkVow(alpha[i])) // ���ĺ��� ������ �� ���� + 1
			DFS(cnt + 1, i + 1, vowel + 1, con);
		else //���ĺ��� �����϶� ���� + 1
			DFS(cnt + 1, i + 1, vowel, con + 1);
		code.pop_back();
	}

	return;
}

int main() {
	int i;
	cin >> l >> c;
	for (i = 0; i < c; i++) {
		char a;
		cin >> a;
		alpha.push_back(a);
	}

	sort(alpha.begin(), alpha.end()); // ���� ������ ����

	DFS(0, 0, 0, 0);
	return 0;
}