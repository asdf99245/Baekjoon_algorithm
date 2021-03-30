//��й�ȣ
//https://www.acmicpc.net/problem/13908

#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

vector<int> know;
int used[7];
int cnt = 0;

bool check(int n) {
	int i, j;
	for (i = 0; i < know.size(); i++) {
		bool flag = false;
		for (j = 0; j < n; j++) {
			if (used[j] == know[i]) { 
				flag = true;
				break;
			}
		}
		if (!flag) // ���� ��й�ȣ�� ���Ե����� �ʴٸ� ����
			return false;
	}

	return true;
}

void DFS(int length, int n) {
	if (length == n) { // ������ �ϼ� �ƴٸ�
		if (check(n)) // ������������ �˰� �� ���� ���� ���ִ��� Ȯ��
			cnt++;
		return;
	}
	int i;

	for (i = 0; i <= 9; i++) {
		used[length] = i; // ��й�ȣ�� length��°�� i ���ڷ� 
		DFS(length + 1, n);
		used[length] = -1;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i;
	for (i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		know.push_back(num); // �˰� �ִ� ��
	}
	memset(used, -1, sizeof(used));
	DFS(0, n);
	printf("%d", cnt);
	return 0;
}