//소형기관차
//https://www.acmicpc.net/problem/2616
//다시풀어봐야할 문제
/*

#include <cstdio>
#include <algorithm>
using namespace std;

int n, capacity;
int passenger[50001];
int cache[4][50001];
int ans = 0;

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &passenger[i]);
		passenger[i] += passenger[i - 1];
	}
	scanf("%d", &capacity);
	
	for (i = 1; i <= 3; i++) {
		for (j = i * capacity; j <= n; j++) {
			cache[i][j] = max(cache[i][j - 1], cache[i - 1][j - capacity] + (passenger[j] - passenger[j-capacity]));
			ans = max(ans, cache[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}*/