//�ֽ�
//https://www.acmicpc.net/problem/11501
/* ����Ͽ� �����ؼ� ������ �������� ã�ƺ��� return ���� Ŀ�� 
int �� long long ���� �����ϴ� ������ �־��� ���� */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long maxProfit(vector<int> &v) {
	long long profit = 0;
	int i;

	long long mx = 0;
	//���� ������ ���� ���� �ְ��� �����ؿ�
	for (i = v.size() - 1; i >= 0; i--) {
		if (v[i] > mx) 
			mx = v[i];
		else //���� ���� �ְ����� ���� �ְ� �Ͻ� ��
			profit += mx - v[i];
	}
	return profit;
}

int main() {
	int T, n, i, j;
	scanf("%d", &T);
	
	int price;

	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		vector<int> v;
		for (j = 0; j < n; j++) {
			scanf("%d", &price);
			v.push_back(price);
		}
		printf("%lld\n",maxProfit(v));
	}

	return 0;
}