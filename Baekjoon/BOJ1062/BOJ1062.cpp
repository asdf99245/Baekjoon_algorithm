//����ħ
//https://www.acmicpc.net/problem/1062

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int alphabet = 0;
int m = 0;

void getRead() {
	int i, j;
	int cnt = 0;

	for (i = 0; i < v.size(); i++) {
		string word = v[i];
		bool check = true;
		for (j = 4; j < word.length() - 4; j++) { // anta tica �� ������ �����Ƿ� �����ϰ� �˻�
			if (!(alphabet & (1 << (word[j] - 'a')))) { // k���� ���ڷ� ������ ������ 
				check = false;
				break;
			}
		}
		if (check) // k ���� ���ڷ� ������ �ִٸ� count + 1
			cnt++;
	}

	m = max(m, cnt); // �� ���� ������ ����
}

void DFS(int ind , int cnt, int k) {
	int i;
	if (cnt == k) { // k ���� ���ڸ� ����ٸ�
		getRead();
		return;
	}

	for (i = ind; i < 26; i++) {
		if (!(alphabet & (1 << i))) { // ����ġ�� ���� ���ĺ��̶�� ��
			alphabet |= (1 << i);
			DFS(i + 1, cnt + 1, k);
			alphabet &= ~(1 << i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, i;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	if (k < 5) { // 5�� ���϶�� anta tica ������ �Ұ��� 
		cout << 0;
		return 0;
	}
	else if (k == 26) { // ��� ���ĺ��� ����ģ�ٸ� �ܾ� ���θ� �˼� �ִ�
		cout << n;
		return 0;
	}

	// anta tica�� ���ϴ� ���ĺ�
	alphabet |= (1 << 'a' - 'a');
	alphabet |= (1 << 'n' - 'a');
	alphabet |= (1 << 't' - 'a');
	alphabet |= (1 << 'i' - 'a');
	alphabet |= (1 << 'c' - 'a');

	DFS(0, 5, k);

	cout << m;
	return 0;
}