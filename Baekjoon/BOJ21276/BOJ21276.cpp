//�躸 ������ ȣ��
//https://www.acmicpc.net/problem/21276
//�κ��հ� 10/19

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<string> name;
vector<string> root;
map<string, int> inDegree;
map<string, vector<string>> mp;
map<string, vector<string>> tree;
int cnt = 0;

void topology(int N, vector<string> & name) {
	int i;
	queue<string> q;
	for (i = 0; i < N; i++) {
		if (inDegree[name[i]] == 0) { // ������ ���ٸ� ������ ������ ��
			q.push(name[i]);
			cnt++;
			root.push_back(name[i]);
		}
	}

	while (!q.empty()) {
		string x = q.front();
		q.pop();
		for (i = 0; i < mp[x].size(); i++) {
			string child = mp[x][i];
			if (--inDegree[child] == 0) { // �ڽ��� ������ �� Ȯ�� �ƴٸ� ���� ������ child
				q.push(child);
				tree[x].push_back(child);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i;
	cin >> N;
	string n;
	for (i = 0; i < N; i++) {
		cin >> n;
		name.push_back(n);
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		string X, Y;
		cin >> X >> Y;
		inDegree[X] ++; // ������ ��
		mp[Y].push_back(X); 
	}
	sort(name.begin(), name.end()); // �̸� �������� ����
	topology(N, name); // ��������
	cout << cnt << '\n';
	for (i = 0; i < root.size(); i++) {
		cout << root[i] << ' ';
	}
	cout << '\n';
	for (i = 0; i < name.size(); i++) {
		cout << name[i] << ' ' << tree[name[i]].size() << ' ';
		for (int j = 0; j < tree[name[i]].size(); j++) {
			cout << tree[name[i]][j] << ' '; // child �� �ִٸ� ���
		}
		cout << '\n';
	}

	return 0;
}