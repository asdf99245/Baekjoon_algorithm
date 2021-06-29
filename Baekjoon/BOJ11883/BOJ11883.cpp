// ���ϼ� 1
// https://www.acmicpc.net/problem/11883

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

int cache[1000001];
int num[] = { 3,5,8 };

void BFS() {
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++) { // 3, 5, 8 ���� ���� ���� �ڸ����� ���� ���� �ڸ��� + 1
			int next = here + num[i];
			if (next <= 1000000 && cache[next] == -1) {
				q.push({ next, cnt + 1 });
				cache[next] = cnt + 1;
			}
		}
	}

}

void print(int N , int cnt) {
	if (N == 0) return; 

	int i;
	for (i = 0; i < 3; i++) { 
		int next = N - num[i];
		if (next < 0) continue; // ������ �Ұ���
		if (cache[next] == cnt - 1) { // ���� ���� �ڸ������� 1 ���� ���̿�����
			printf("%d", num[i]);
			print(next, cnt - 1);
			return;
		}
	}
}
int main() {
	int T, N;
	scanf("%d", &T);
	memset(cache, -1, sizeof(cache));
	cache[0] = 0;

	BFS();

	while (T > 0) {
		scanf("%d", &N);
		if (cache[N] == -1) { // ���ϼ��� �������� �ʴ´�
			printf("-1\n");
		}
		else {
			print(N, cache[N]);
			printf("\n");
		}
		T--;
	}
	return 0;
}