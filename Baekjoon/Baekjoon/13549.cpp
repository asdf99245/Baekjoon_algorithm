//���ٲ��� 3
//https://www.acmicpc.net/problem/13549

/*#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int walk[] = { -1,1 };
bool visited[100001];

int BFS(int n ,int k) {
	visited[n] = true;
	int i,j;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push({ 0,n }); // �ð� , ������ġ

	while (!pq.empty()) {
		
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (x == k) return cost; //�����ߴٸ� ���

		if (x * 2 <= 100000 && !visited[x * 2]) { // �����̵��ؼ�
			visited[x * 2] = true;
			pq.push({ cost,x * 2 }); // 0�� �ɸ�
		}

		for (j = 0; j < 2; j++) { // �ɾ
			int nn = x + walk[j];
			if (0 <= nn && nn <= 100000 && !visited[nn]) { // �����ȿ� �ְ� �湮������ �������
				visited[nn] = true;
				pq.push({ cost+1,nn }); // 1�� �ɸ�
			}
		}
	}
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", BFS(n, k));
	return 0;
}*/