//�κ� ������ ��
//https://www.acmicpc.net/problem/1182

/*#include <cstdio>
#include <algorithm>
using namespace std;

int N, S;
int seq[21];
int cnt = 0;

void solve(int d, int sum) {
	if (d == N) {  // ���� ���̿� ����������
		if (sum  == S) {  // sum�� S�� ���ٸ� ī��Ʈ �÷���
			cnt++;
		}
		return;
	}

	int i;

	solve(d + 1, sum); // d��° ���� �� �����ٶ�
	solve(d + 1, sum + seq[d]); // d��° ���� ���Ҷ�
	return;
}
int main() {
	int i;
	scanf("%d %d", &N, &S);

	for (i = 0; i < N; i++) {
		scanf("%d", &seq[i]);
	}

	solve(0, 0);
	if (S == 0) cnt -= 1; //  S�� 0 �̸� �ƹ��͵� ���������� ����� �� ����
	printf("%d", cnt);
	return 0;
}*/