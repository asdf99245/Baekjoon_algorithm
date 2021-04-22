//���� ���� ����
//https://www.acmicpc.net/problem/17073

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

/*
ù��° ���

vector<int> tree[500001];
bool visited[500001];
int cnt = 0;

void DFS(int curr) {
	visited[curr] = true;
	int i;

	bool leaf = true; // ���� ���̻� �湮 �Ҽ� �ִ� ��尡 ���ٸ� ���������
	for (i = 0; i < tree[curr].size(); i++) {
		int next = tree[curr][i];
		if (!visited[next]) { 
			leaf = false;
			DFS(next);
		}
	}

	if (leaf) {
		cnt++;
	}
}

int main() {
	int n, i;
	double total;
	scanf("%d %lf", &n, &total);
	for (i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	DFS(1); // Ʈ���� �� ���� Ž���ϸ鼭 ��������� ������ ã�´�

	printf("%lf", total/(double)cnt); // �ᱹ ���� ������忡�� ���̻� �������� �ʱ⶧���� ���Ǿ� / �� ������� ������ ���̵�
	return 0;
}

*/

//�ι�° ��� 

int edge[500001];
int cnt = 0;

int main() {
	double total;
	int n;
	scanf("%d %lf", &n, &total);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u] ++;
		edge[v] ++;
	}

	for (int i = 1; i <= n; i++) 
		if (edge[i] == 1) cnt++; // ������ 1���� ��尡 �������

	printf("%lf", total / cnt); // ������忡�� ���� ���߱⶧���� ���Ǿ翡 ��������� �Ѱ����� �����ش�
	return 0;
}