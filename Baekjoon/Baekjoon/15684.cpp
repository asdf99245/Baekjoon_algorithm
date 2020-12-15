//사다리 조작
//https://www.acmicpc.net/problem/15684

/*#include <cstdio>
#include <algorithm>
using namespace std;

bool connect[31][10];
int N, M, H;

void addConnect(int n) {
	int i;

	while (n > 0) {

		n--;
	}
}
bool startGame() {
	int i, j;

	for (i = 1; i <= N; i++) {
		int now = i;
		for (j = 1; j <= H; j++) {
			if (connect[j][i - 1] == true) {
				now -= 1;
			}
			else if (connect[j][i] == true) {
				now += 1;
			}
		}
		if (now != i) return false;
	}

	return true;
}
int main() {
	int i;
	scanf("%d %d %d", &N, &M, &H);

	for (i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		connect[a][b] = true;
	}
	return 0;
}*/