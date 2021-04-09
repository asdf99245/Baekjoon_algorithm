//���Ϸ� ����
//https://www.acmicpc.net/problem/13168

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define INF 987654321
using namespace std;

int N, R;
map<string, int> city;
vector<string> route;
double dist[100][100];
double ticket_dist[100][100];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			dist[i][j] = ticket_dist[i][j] = INF;
		}
	}
}

void getDists() {
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		string type, S, E;
		double cost;
		
		cin >> type >> S >> E >> cost;
		int from = city[S];
		int to = city[E];
		dist[from][to] = min(dist[from][to], cost);
		dist[to][from] = min(dist[to][from], cost);
		// ���Ϸ� Ƽ���Ͻ� �ش��ϴ� ���� ����
		if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") {
			cost = 0;
		}
		else if (type == "S-Train" || type == "V-Train") {
			cost /= 2;
		}
		ticket_dist[from][to] = min(ticket_dist[from][to], cost);
		ticket_dist[to][from] = min(ticket_dist[to][from], cost);
	}
}

void floyd() {
	int i, j, k;

	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
				if (ticket_dist[i][j] > ticket_dist[i][k] + ticket_dist[k][j])
					ticket_dist[i][j] = ticket_dist[i][k] + ticket_dist[k][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	cin >> N >> R;
	for (i = 0; i < N; i++) {
		string name;
		cin >> name;
		city[name] = i;
	}

	int M;
	cin >> M;
	for (i = 0; i < M; i++) {
		string name;
		cin >> name;
		route.push_back(name);
	}

	init(); // �׷��� �ʱ�ȭ
	getDists(); // ���Ϸ� Ƽ���� �� ���� �����ʾ��� ��쿡 ���ð� �ּҺ���� ����
	floyd(); // �÷��̵� �ͼ� 

	double res1 = 0, res2 = R;
	// ���� ��ο� ���� ������ �����ش�
	for (i = 0; i < route.size() - 1; i++) {
		int from = city[route[i]];
		int to = city[route[i + 1]];
		res1 += dist[from][to];
		res2 += ticket_dist[from][to];
	}

	if (res1 <= res2)
		cout << "No";
	else
		cout << "Yes";
	return 0;  
}