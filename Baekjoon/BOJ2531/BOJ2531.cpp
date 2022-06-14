#include <iostream>
#include <vector>
using namespace std;

int check[3001];
vector<int> dish;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, d, k, c;
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		dish.push_back(a);
	}

	int cnt = 0, maxCnt = 0;

	// ó�� k���� �ʹ��� �Ծ��� �� 
	for (int i = 0; i < k; i++) {
		if (!check[dish[i]]) cnt++; // ó���Դ� �ʹ��̸�
		check[dish[i]]++;
	}

	for (int i = 1; i < N; i++) {
		if (maxCnt <= cnt) { // ���� ���� ������ �ʹ��� �Ծ��� ��
			if (!check[c]) maxCnt = cnt + 1; // ���� ���� �ʹ��� ���� �ʾҴٸ� �߰�
			else maxCnt = cnt;
		}
		// ���� �տ��� �Ծ��� �ʹ� ����
		// ������ �ʹ��� k���� �ش���� �ʴ´ٸ� ������ ����
		check[dish[i - 1]]--; 
		if (!check[dish[i - 1]]) cnt--; 
		// ������ �ʹ� ���� �ʹ��� �Դ´�
		// ó�� ���� �ʹ��̸� ������ ���Ѵ�
		if (check[dish[(i + k - 1) % N]] == 0) cnt++; 
		check[dish[(i + k - 1) % N]]++;
	}

	cout << maxCnt;
	return 0;
}