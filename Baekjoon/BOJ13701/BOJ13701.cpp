// �ߺ� ����
// https://www.acmicpc.net/problem/13701

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <bitset>
using namespace std;

bitset<1 << 25> bit;

int main() {
	int n;

	while (scanf("%d", &n) != EOF) { // �Է��� ����������
		if (!bit[n]) { // bitset�� ���� �����ϰ��
			bit[n] = true; // bitset�� ���� ����
			printf("%d ", n);
		}
	}
}