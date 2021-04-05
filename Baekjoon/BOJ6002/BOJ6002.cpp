//Job Hunt
//https://www.acmicpc.net/problem/6002

#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

vector<pair<int, int>> v[221];
int main() {
	int D, P, C, F, S, i;
	scanf("%d %d %d %d %d", &D, &P, &C, &F, &S);
	for (i = 0; i < P; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		v[from].push_back({ to,D });
	}

	for (i = 0; i < F; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back({ to, D - cost }); // ���� ���� ���� ����� ����
	}

	//���� ����
	vector<long long> dist(C + 1, LONG_MIN);
	dist[S] = D; // ���� ��������  D�޷��� ���� ������
	for (i = 1; i <= C; i++) {
		for (int j = 1; j <= C; j++) {
			if (dist[j] == LONG_MIN) continue; // ���� ���� ���� ��ŵ
			for (auto &p : v[j]) {
				long long cost = dist[j] + p.second;
				long long next = p.first;
				if (cost > dist[next]) { // �� ���� ���� ���� �ִٸ� ����
					dist[next] = cost;
					if (i == C) { // V��° ��ȯ�� �Ÿ��� ������ �ִٸ� ����Ŭ�� �ִ�
						printf("-1");
						return 0;
					}
				}
			}
		}
	}

	sort(dist.begin(), dist.end());
	printf("%lld", dist[C]); // �����Ͽ� ���� ū ���� ���

	return 0;
}