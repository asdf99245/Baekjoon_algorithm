//�Ҽ�& �Ӹ����
//acmicpc.net/problem/1747

/*
#include <cstdio>
#include <algorithm>
#include <string>
#define MAX_N 1999991
using namespace std;

int a[MAX_N + 1]; // 100�� ���� ū �Ҽ��� 200�� �ȿ� �ִ�, 200�� �ȿ� �Ӹ���� �� �� ���� ū ���� 1999991

void getPrimeNumber() { //�����佺�׳׽��� ü
	int i, j;
	for (i = 2; i <= MAX_N; i++) {
		a[i] = i;
	}

	for (i = 2; i <= MAX_N; i++) {
		if (a[i] == 0) continue;
		for (j = 2 * i; j <= MAX_N; j += i) { // ��� ������
			a[j] = 0; 
		}
	}
}
bool isPalindrome(int num) {
	string s = to_string(num);
	int i = 0, j = s.length() - 1;

	while (i <= j) {
		if (s[i] != s[j]) return false; // ��Ī���� �� ��ġ���� ������ �Ӹ���Ҽ� �ƴ�
		i++;
		j--;
	}
	return true;
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	getPrimeNumber();

	for (i = n; i <= MAX_N; i++) {
		if (a[i] != 0) {
			if (isPalindrome(i)) {
				printf("%d", i);
				break;
			}
		}
	}
	return 0;
}*/