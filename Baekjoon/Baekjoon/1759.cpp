//암호 만들기
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
		if (alpha == vowels[i]) { // 모음 하나씩 확인
			return true;
		}
	}
	return false;
}
void DFS(int cnt,int ind, int vowel, int con) {
	if (cnt == l) { // 알파벳 개수와 같아졌을때
		if (vowel < 1 || con < 2) return; // 모음이 최소 1개, 자음이 최소 2개 조건을 만족하지 않으면 출력하지 않는다
		for (int i = 0; i < code.size(); i++) // 암호 출력 
			cout << code[i];
		cout << "\n";
		return;
	}

	for (int i = ind; i < alpha.size(); i++) {
		code.push_back(alpha[i]);
		if (checkVow(alpha[i])) // 알파벳이 모음일 때 모음 + 1
			DFS(cnt + 1, i + 1, vowel + 1, con);
		else //알파벳이 자음일때 자음 + 1
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

	sort(alpha.begin(), alpha.end()); // 사전 순으로 정렬

	DFS(0, 0, 0, 0);
	return 0;
}