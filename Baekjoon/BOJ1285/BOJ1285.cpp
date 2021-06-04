//���� ������
//https://www.acmicpc.net/problem/1285

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int coin[21];
int ans = 20 * 20 + 1;

void flip(int ind, int n) {
	if (ind == n) { // n��° �ٱ��� �������ٸ�
		int i, j;
		int sum = 0;
		for (i = 0; i < n; i++) {
			int t = 0;
			for (j = 0; j < n; j++) {
				if ((coin[j] & (1 << i)) != 0) { // ��Ʈ�� 1�̶��(�޸��̶��) 
					t++;
				}
			}
			sum += min(n - t, t); // 1�� 0�� �� ���� ������ �ո����� ���ؾ��Ѵ�
		}
		ans = min(ans, sum);

		return;
	}

	flip(ind + 1, n);
	coin[ind] = ~coin[ind]; // ind��° ���� �����´�
	flip(ind + 1, n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (j = 0; j < n; j++) {
			if (s[j] == 'T') { // �޸��� ��� ��Ʈ�� 1��
				coin[i] |= (1 << j);
			}
		}
	}

	flip(0, n);

	cout << ans;

	return 0;
}