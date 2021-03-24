//�ù�
//https://www.acmicpc.net/problem/1719

#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m;
vector<pair<int,int>> graph[201];
int route[201][201];

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (route[i][j] == 0)
                printf("- ");
            else
                printf("%d ", route[i][j]);
        }
        printf("\n");
    }
}
void dijsktra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);

    pq.push({0,start});
    dist[start] = 0;
    int i,j;

    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (d > dist[curr]) continue; // �̹� üũ�� ��ζ�� ��ŵ


        for (i = 0; i < graph[curr].size(); i++) {
            int cost = d + graph[curr][i].second;
            int next = graph[curr][i].first;
            if (cost < dist[next]) { // �� ª�� ��ζ�� �����ϰ� �켱����ť�� ��� ����
                if (curr == start) { // ���� ���� ���ľ� �ϴ� �������� ���ϱ� ���� ���� �������� ���� ó��
                    route[start][next] = next;
                }
                else {
                    route[start][next] = route[start][curr]; // ���� ��ο� ���� ���� ��ģ �������� �տ��� �ҷ��´�
                }
                dist[next] = cost;
                pq.push({ cost,next });
            }
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    int i;

    for (i = 0; i < m; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        // ����� �׷��� ����
        graph[from].push_back({ to,cost });
        graph[to].push_back({ from,cost });
    }

    for (i = 1; i <= n; i++) // �� �����忡 ���Ͽ� �ִܰ�ο� ���ǥ ����
        dijsktra(i);

    print(); // ���ǥ ���
    return 0;
 }