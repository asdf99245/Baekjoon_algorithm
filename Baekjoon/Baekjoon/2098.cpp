//���ǿ� ��ȸ
//https://www.acmicpc.net/problem/2098
//*******************�߿�******************* ���� Ʋ�� ����

/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int n;
int w[16][16];
int dp[16][1 << 16]; //��Ʈ������ visited ǥ�� ȿ������
int INF = 987654321;

int TSP(int curr, int visited) {
	if (visited == ((1 << n) - 1)) { // ���� �湮������
		if(w[curr][0] != 0) //���������� ���� �ִٸ� �Ÿ� ����
			return w[curr][0];
		return INF; //������ ū�� ����
	}
	
	int ret = dp[curr][visited]; //�޸������̼�
	if (ret != -1) //���� �����ϸ� ���
		return ret;

	ret = INF;
	for (int i = 1; i < n; i++) {
		if (visited & (1 << i) || w[curr][i] == 0) //��Ʈ�� �̿��Ͽ� visited Ȯ��, ���� �ִ��� Ȯ��
			continue;

		int visit = visited | (1 << i); //OR��Ʈ�� i��Ʈ visit ǥ�� 

		ret = min(ret, w[curr][i] + TSP(i, visit)); //���� ���� ��Ʈ�� ������
	}

	dp[curr][visited] = ret;
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d", TSP(0, 1));
	return 0;
}*/