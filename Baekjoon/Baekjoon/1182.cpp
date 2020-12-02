//부분 수열의 합
//https://www.acmicpc.net/problem/1182

/*#include <cstdio>
#include <algorithm>
using namespace std;

int N, S;
int seq[21];
int cnt = 0;

void solve(int d, int sum) {
	if (d == N) {  // 수열 길이와 같아졌을때
		if (sum  == S) {  // sum이 S와 같다면 카운트 올려줌
			cnt++;
		}
		return;
	}

	int i;

	solve(d + 1, sum); // d번째 수를 안 더해줄때
	solve(d + 1, sum + seq[d]); // d번째 수를 더할때
	return;
}
int main() {
	int i;
	scanf("%d %d", &N, &S);

	for (i = 0; i < N; i++) {
		scanf("%d", &seq[i]);
	}

	solve(0, 0);
	if (S == 0) cnt -= 1; //  S가 0 이면 아무것도 더하지않은 경우의 수 빼줌
	printf("%d", cnt);
	return 0;
}*/