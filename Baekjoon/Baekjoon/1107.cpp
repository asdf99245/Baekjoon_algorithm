//리모컨
//https://www.acmicpc.net/problem/1107

/*#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool bt_num[10];

bool check(int n) {
	int i;
	if (n == 0 && bt_num[0] == true) return false;
	while (n != 0) {
		if (bt_num[n % 10] == true) return false;
		n /= 10;
	}

	return true;
}
int main() {
	int n, m, i;
	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		int bt;
		scanf("%d", &bt);
		bt_num[bt] = true; // 고장난 버튼
	}

	int minCnt = abs(100 - n);

	for (i = 0; i < 999900; i++) {
		if (check(i)) {
			int l = to_string(i).length();
			minCnt = min(minCnt, l + abs(i - n));
		}
	}

	printf("%d", minCnt);
	return 0;
}*/