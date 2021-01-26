//소수& 팰린드롬
//acmicpc.net/problem/1747

/*
#include <cstdio>
#include <algorithm>
#include <string>
#define MAX_N 1999991
using namespace std;

int a[MAX_N + 1]; // 100만 보다 큰 소수는 200만 안에 있다, 200만 안에 팰린드롬 수 중 가장 큰 수는 1999991

void getPrimeNumber() { //에라토스테네스의 체
	int i, j;
	for (i = 2; i <= MAX_N; i++) {
		a[i] = i;
	}

	for (i = 2; i <= MAX_N; i++) {
		if (a[i] == 0) continue;
		for (j = 2 * i; j <= MAX_N; j += i) { // 배수 지워줌
			a[j] = 0; 
		}
	}
}
bool isPalindrome(int num) {
	string s = to_string(num);
	int i = 0, j = s.length() - 1;

	while (i <= j) {
		if (s[i] != s[j]) return false; // 대칭으로 비교 일치하지 않을시 팰린드롬수 아님
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