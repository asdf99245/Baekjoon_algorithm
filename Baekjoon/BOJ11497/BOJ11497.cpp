// �볪�� �ǳʶٱ�
// https://www.acmicpc.net/problem/11497

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int arr[10001];

int main() {
	int t, n, i;
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n); // �������� ����
		
		vector<int> v;
		// 2ĭ�� ������ �볪���� �����ҽ� ���� ���� ��������
		if (n % 2 == 0) { // ¦�� �Ͻ�
			for (i = 0; i < n; i+=2) { 
				v.push_back(arr[i]);
			}
			for (i = n - 1; i > 0; i -= 2) {
				v.push_back(arr[i]);
			}
		}
		else { // Ȧ�� �Ͻ�
			for (i = 0; i < n; i += 2) {
				v.push_back(arr[i]);
			}
			for (i = n - 2; i > 0; i -= 2) {
				v.push_back(arr[i]);
			}
		}

		int ans = abs(v[0] - v[n - 1]); // ó���� ���� ����
		for (i = 0; i < n - 1; i++) { // ���ĵ� �������� ���� ���̸� ���Ѵ�
			ans = max(ans, abs(v[i] - v[i + 1])); // �ִ� ����
		}
		printf("%d\n", ans);
		t--;
	}
	return 0;
}