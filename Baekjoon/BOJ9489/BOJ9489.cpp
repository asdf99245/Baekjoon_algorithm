//����
//https://www.acmicpc.net/problem/9489

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1000000
using namespace std;

int par[MAX + 1];
int d[MAX + 1];
int arr[1001];

int main() {
	int n, k, i;
	while (true) {
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0) break; // ����

		queue<pair<int,int>> q;
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		q.push({ arr[0],0 }); // ��Ʈ�� ���� 0 ���� 
		int parent = arr[0];
		int depth = 0;
		for (i = 1; i < n; i++) {
			if (arr[i - 1] + 1 < arr[i]) { // ���ӵǴ� ���� �ƴ϶�� ���� ����� �ڽ��� �Ǿ���Ѵ�
				parent = q.front().first;
				depth = q.front().second;
				q.pop();
			}
			q.push({ arr[i],depth + 1 }); // �ڽ� ����� ���� = �θ����� ���� + 1
			par[arr[i]] = parent; // �θ� ��� ����
			d[arr[i]] = depth + 1; // ���� ����
		}
		
		int cnt = 0;
		for (i = 0; i < n; i++) {
			if (d[arr[i]] == d[k]) { // ���̰� ����
				int a = par[arr[i]];
				int b = par[k];
				if (a != b) { // �θ� �����ʴٸ�
					if (par[a] == par[b]) // �θ��� �θ� ������ ����
						cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}