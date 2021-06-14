// ��Ƽ�� �����층
// https://www.acmicpc.net/problem/1700

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool check[101];
vector<int> v;
vector<int> tap;


int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	int ans = 0;
	for (int i = 0; i < K; i++) {
		if (check[v[i]]) { // �̹� �����ִٸ�
			continue;
		}

		if (tap.size() < N) { // ��Ƽ�ǿ� �ڸ��� �ִٸ�
			check[v[i]] = true; // �����ڸ��� ����
			tap.push_back(v[i]); 
		}
		else {
			ans++;
			int ind = 0;
			int maxInd = i;
			for (int j = 0; j < tap.size(); j++) { // ��Ƽ�ǿ� �����ִ� ��ǰ��
				bool find = false;
				for (int k = i + 1; k < K; k++) { // ���� ���߿� ���Ǿ��� ��ǰ�� ã�´�
					if (v[k] == tap[j]) {
						find = true;
						if (maxInd < k) {
							maxInd = k;
							ind = j;
						}
						break;
					}
				}

				if (!find) { // �� �̻� ������� ���� ��ǰ�� ����
					ind = j;
					break;
				}
			}

			// �÷��׸� ���� �� ��ǰ�� �Ŵ´�
			check[tap[ind]] = false; 
			tap[ind] = v[i];
			check[tap[ind]] = true;
		}
	}

	printf("%d", ans);
	return 0;
}