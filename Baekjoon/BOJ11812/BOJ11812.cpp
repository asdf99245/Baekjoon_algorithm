// K�� Ʈ��
// https://www.acmicpc.net/problem/11812

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	long long int n, k, q;
	scanf("%lld %lld %lld", &n, &k, &q);
	for (int i = 0; i < q; i++) {
		long long int x, y;
		long long int cnt = 0;
		scanf("%lld %lld", &x, &y);
		if (k == 1) { // k == 1 �Ͻ� �Ϸķ� ������ֱ⶧���� ��� ��ȣ�� depth
			printf("%lld\n", abs(y - x));
		}
		else { 
			while (y != x) { // ���� �θ� �ɶ�����
				// ���� ������ ��带 �θ���� �ٲ۴�
				if (y > x) {
					y = (y - 2) / k + 1;
				}
				else {
					x = (x - 2) / k + 1;
				}
				cnt++; // �Ÿ� + 1
			}

			printf("%lld\n", cnt);
		}
	}


	return 0;
}