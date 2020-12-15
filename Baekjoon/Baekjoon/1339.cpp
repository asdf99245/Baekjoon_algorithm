//단어 수학
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
		if (length > maxLength) //최대 길이 구함
			maxLength = length;
		reverse(word.begin(), word.end()); // 자릿수가 큰쪽을 인덱스가 더 크게함
		words.push_back(word);
	}
	
	int num = 9;
	for (i = maxLength - 1; i >= 0; i--) { // 단어의 첫번째 알파벳부터 확인 
		for (j = 0; j < words.size(); j++) {
			if (words[j].size() < i + 1) continue; // 단어가 i + 1 보다 짧다면 continue
			if (mp.find(words[j][i]) == mp.end()) { // 알파벳의 숫자가 정해져 있지 않을때
				mp[words[j][i]] = num; // map에 알파벳 숫자 정해줌
				num--;
			}
		}
	}

	long long int sum = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < words[i].size(); j++) {
			sum += mp[words[i][j]] * pow(10, j); // 숫자값 단어에 대입해서 더해준다
		}
	}

	printf("%lld", sum);
	return 0;
}*/