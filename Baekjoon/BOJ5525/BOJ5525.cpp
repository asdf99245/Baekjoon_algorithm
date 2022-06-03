// IOIOI
// https://www.acmicpc.net/problem/5525

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> s;

	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (s[i] == 'I') { 
			int cnt = 0;
			while (s[i + 1] == 'O' && s[i + 2] == 'I') { // "01" ��Ʈ�� �������� ���� ������
				cnt++; // ��Ʈ�� ��
				if (cnt == N) { // Pn�� ã���� ��
					cnt--; // ���� ���� "01" ��Ʈ�� ����
					ans++;
				}
				i += 2;
			}
		}
	}

	cout << ans;

	return 0;
}