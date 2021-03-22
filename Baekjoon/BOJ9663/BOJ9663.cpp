//N-queen
//https://www.acmicpc.net/problem/9663

#include <cstdio>
#include <algorithm>
using namespace std;

int cnt = 0;
int queens[15]; //�� ������ n��° ĭ�� ���� ����

bool check(int row ,int ind) {
	for (int i = row - 1; i >= 0; i--) {
		if (queens[i] == ind || queens[i] == ind - (row - i) || queens[i] == ind + (row -i)) // ������ ���鿡 ���ο� �밢���� ���� �ִ��� �˻�
			return false;
	}

	return true;
}

void nQueen(int row, int N) {
	if (row == N) { // N���� ���� �� ��ġ�ߴٸ� count
		cnt++;
		return;
	}

	int i;
	
	for (i = 0; i < N; i++) {
		if (check(row, i)) {
			queens[row] = i; // i��° ĭ�� �� ��ġ
			nQueen(row + 1, N); // ���� ���� ����
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	nQueen(0, N);
	printf("%d", cnt);
	return 0;
}