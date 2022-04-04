// ��Ȯ�� ������
// https://www.acmicpc.net/problem/9370

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2001
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
vector<pair<int, int>> v[MAX];
int dist[MAX];
bool flag[MAX]; // n��° �������� �ִܰ�ο� g~h��ΰ� ���ԵǾ��ִ��� üũ

void dijkstra(int start, int g, int h) {
	priority_queue<pii,vector<pii>> pq; 

	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first; // ��������� �Ÿ�
		int curr = pq.top().second; // ���� ���
		pq.pop();

		if (dist[curr] < d) continue; // �̹� �����Ѱ�

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i].first;
			int cost = d + v[curr][i].second;
			if (cost < dist[next]) { // �ִ� �Ÿ����
				if ((curr == g && next == h) || (curr == h && next == g)) { // g ~ h ��θ� ����Ѵٸ�
					flag[next] = true;
				}
				else {
					flag[next] = flag[curr];
				}
				dist[next] = cost;
				pq.push({ -cost,next }); 
			}
			if (cost == dist[next]) { // �ִ� ��ΰ� 2�� �̻��϶�
				if ((curr == g && next == h) || (curr == h && next == g)) { // g ~ h ��θ� ����Ѵٸ�
					flag[next] = true;
				}
				flag[next] = flag[curr] || flag[next]; // next�� g ~ h �� ������ �ִܰ�θ� ������ �ִٸ� true��
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T > 0) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i < m; i++) { // �׷��� ����
			int a, b, d;
			cin >> a >> b >> d;
			v[a].push_back({ b,d });
			v[b].push_back({ a,d });
		}
		vector<int> dest;
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			dest.push_back(x);
		}
		sort(dest.begin(), dest.end()); // �������� ����
		fill(dist, dist + MAX, INF);
		fill(flag, flag + MAX, false);
		dijkstra(s, g, h); // ���ͽ�Ʈ��� �ִܰ�� ����
		for (int i = 0; i < dest.size(); i++) {	// g ~ h ��θ� �ִܰ�ο� �����ϴ� ������ ���
			if (flag[dest[i]]) {
				cout << dest[i] << " ";
			}
		}
		cout << "\n";

		for (int i = 1; i <= n; i++) v[i].clear();
		T--;
	}
	return 0;
}