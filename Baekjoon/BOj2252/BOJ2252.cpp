//�� �����
//https://www.acmicpc.net/problem/2252

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> student[32001];
int inDegree[32001];

vector<int> topological_sort() {
	vector<int> result;
	queue<int> q;
	int i, j;

	for (i = 1; i <= n; i++) {
		if (inDegree[i] == 0) // ���������� ���� ������ ����
			q.push(i);
	}

	for (i = 1; i <= n; i++) {
		if (q.empty())
			break;

		int x = q.front();
		q.pop();
		result.push_back(x);

		for (j = 0; j < student[x].size(); j++) {
			int ns = student[x][j]; 
			inDegree[ns] --; // �������� ���ҽ�����
			if (inDegree[ns] == 0) // ����Ǿ���ϴ� �л��� �� ���ٸ� ����
				q.push(ns);
		}
	}

	return result;
}
int main() {
	int i;
	vector<int> res;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++) {
		int s1, s2;
		scanf("%d %d", &s1, &s2);
		student[s1].push_back(s2);
		inDegree[s2]++; // ���� �����ϴ� �л��� �ִٸ� ���������� ���������ش�
	}

	res = topological_sort(); // ��������

	for (i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	return 0;
}