//ķ��
//https://www.acmicpc.net/problem/4796

/*#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int L, P, V;
	int cnt = 0;
	while (1) {
		cnt++;
		scanf("%d %d %d", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0) // �ݺ��� Ż��
			break;

		int res = V % P; //���ӵǴ� ��
		if (res >= L) // ������ ���� ����Ҽ� �ִ³� ���� ũ�ų� ���ٸ� ��� ������ �� ��ŭ ����
			printf("Case %d: %d\n", cnt, (V / P) * L + L);
		else // ������ ���� ����Ҽ� �ִ³� ���� �۴ٸ� ������ �� ��ŭ�� ����
			printf("Case %d: %d\n", cnt, (V / P) * L + res);
	}
	return 0;
}*/