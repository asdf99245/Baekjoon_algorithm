// �˹�
// https://www.acmicpc.net/problem/2981

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int num[101];
set<int> st;

int gcd(int a, int b) {
	int rest = a % b;
	return rest ? gcd(b, rest) : b;
}

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	sort(num, num + n); // �������� ����

	int g = num[1] - num[0]; // num[i+1] - num[i] = M * (v[i+1] - v[i]) + r - r �̿�

	for (i = 2; i < n; i++) {
		g = gcd(g, num[i] - num[i - 1]);
	}

	st.insert(g); // �ߺ� �����ϱ� ���� set�̿�
	for (i = 2; i * i <= g; i++) { // �ִ� ������� ����� ���Ѵ�
		if (g % i == 0) {
			st.insert(i);
		}
	}

	for (auto it = st.begin(); it != st.end(); it++)
		printf("%d\n", *it);

	return 0;
}