//���ν��� ���
//https://www.acmicpc.net/problem/1219
//******** �ٽ� �ѹ� �����ҹ��� *************

#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

vector<pair<int, int>> v[100];
int profit[100];
bool cycle[100];
long long dist[100];
int visited[100];

bool BFS(int to,int N) {
	queue<int> q;
	// ����Ŭ�� �������¿��� ������������ �����ִ��� Ȯ��
	for (int i = 0; i < N; i++) {
		if (cycle[i]) {
			visited[i] = true;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == to) {
			return true;
		}

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i].first;
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return false;
}
int main() {
	int N, start, to, M;
	scanf("%d %d %d %d", &N, &start, &to, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,-c });
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &profit[i]);
	}

	for (int i = 0; i < N; i++) dist[i] = LONG_MIN; 
	dist[start] = profit[start]; // ù ���������� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[j] == LONG_MIN) continue; // ���� �Ҽ� ���°��̸� ����
			for (auto& p : v[j]) {
				int cost = p.second;
				int next = p.first;
				if (dist[next] < dist[j] + cost + profit[next]) { // �� ���� ������ ������ �ִٸ� ����
					dist[next] = dist[j] + cost + profit[next];
					if (i == N - 1) { // N��° �ݺ��� �����̵ȴٸ� ����Ŭ�߻�
						cycle[j] = true; // ����Ŭ ��带 �����Ѵ�
					}
				}
			}
		}
	}

	bool check = BFS(to, N); // ����Ŭ ��忡�� ������������ �����ִ��� Ȯ��
	if (dist[to] == LONG_MIN) printf("gg"); // �� �� ���� ���
	else if (check) printf("Gee"); // ���� ������ ���� ������ �ִ� ���
	else
		printf("%lld", dist[to]);
	return 0;
}