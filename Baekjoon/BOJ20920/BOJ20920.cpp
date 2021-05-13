//���ܾ� �ϱ�� �ܷο�
//https://www.acmicpc.net/problem/20920

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string, int> cnt;
vector<string> v;

bool cmp(string& a, string& b) {
	if (cnt[a] != cnt[b]) // �� ���� ��������
		return cnt[a] > cnt[b];
	else if (a.length() != b.length()) // ���� ������ ��������
		return a.length() > b.length();
	else // ��� ���ٸ� ���������� ����
		return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		string word;
		cin >> word;
		if (word.length() >= M) {
			if(cnt[word] == 0) // ���Դ� �ܾ �ƴ϶�� ���Ϳ� ����
				v.push_back(word);
			cnt[word] ++; // �ʿ� ������ �����ش�
		}
	}
	sort(v.begin(), v.end(), cmp); // ����

	for (i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}