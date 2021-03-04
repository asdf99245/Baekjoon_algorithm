//�����
//https://www.acmicpc.net/problem/1094

#include <cstdio>
#include <algorithm>
//#include <intrin.h> __popcnt() �̿� ���� ���̺귯��
using namespace std;

int bitCount(unsigned int x) { 
	if (x == 0) return 0;

	return (x % 2) + bitCount(x / 2); //������ ��ȯ�ϸ鼭 1�Ͻ� ī��Ʈ
}

int main() {
	unsigned int X;
	scanf("%d", &X);

	printf("%d", bitCount(X));
	
	/* ���־� ��Ʃ����� __popcnt() �Լ��� �ϵ�������� ���� ������ ó�� �����ϴ�
	gcc ������ __builtin_popcount() �̿� */
	//printf("%d", __popcnt(X));
	return 0;
}