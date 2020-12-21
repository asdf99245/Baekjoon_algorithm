//숨바꼭질 3
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
	pq.push({ 0,n }); // 시간 , 현재위치

	while (!pq.empty()) {
		
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (x == k) return cost; //도착했다면 출력

		if (x * 2 <= 100000 && !visited[x * 2]) { // 순간이동해서
			visited[x * 2] = true;
			pq.push({ cost,x * 2 }); // 0초 걸림
		}

		for (j = 0; j < 2; j++) { // 걸어서
			int nn = x + walk[j];
			if (0 <= nn && nn <= 100000 && !visited[nn]) { // 범위안에 있고 방문한적이 없을경우
				visited[nn] = true;
				pq.push({ cost+1,nn }); // 1초 걸림
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