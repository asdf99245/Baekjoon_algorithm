//�ܾ� ����
//https://www.acmicpc.net/problem/1339

/*#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map<char, int> mp;
vector<string> words;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, j;
	int maxLength = -1;
	cin >> n;
	for (i = 0; i < n; i++) {
		string word;
		cin >> word;
		int length = word.length();
		if (length > maxLength) //�ִ� ���� ����
			maxLength = length;
		reverse(word.begin(), word.end()); // �ڸ����� ū���� �ε����� �� ũ����
		words.push_back(word);
	}
	
	int num = 9;
	for (i = maxLength - 1; i >= 0; i--) { // �ܾ��� ù��° ���ĺ����� Ȯ�� 
		for (j = 0; j < words.size(); j++) {
			if (words[j].size() < i + 1) continue; // �ܾ i + 1 ���� ª�ٸ� continue
			if (mp.find(words[j][i]) == mp.end()) { // ���ĺ��� ���ڰ� ������ ���� ������
				mp[words[j][i]] = num; // map�� ���ĺ� ���� ������
				num--;
			}
		}
	}

	long long int sum = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < words[i].size(); j++) {
			sum += mp[words[i][j]] * pow(10, j); // ���ڰ� �ܾ �����ؼ� �����ش�
		}
	}

	printf("%lld", sum);
	return 0;
}*/