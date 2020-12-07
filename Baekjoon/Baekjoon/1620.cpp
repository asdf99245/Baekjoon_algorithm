//���¾� ���ϸ� ������ �̴ټ�
//https://www.acmicpc.net/problem/1620

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> pokedex1; // �̸��� �´� ��ȣ ����
string pokedex2[100001]; //��ȣ�� �´� �̸� ����

int main() {
	// ����� �ӵ� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, i;
	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		string name;
		cin >> name;
		pokedex1[name] = i;
		pokedex2[i] = name;
	}

	string p;
	for (i = 0; i < m; i++) {
		cin >> p;
		if (isdigit(p[0])) { // ��ȣ�� ��
			cout << pokedex2[stoi(p)] << "\n";
		}
		else { // �̸��϶�
			cout << pokedex1[p] << "\n";
		}

	}
	return 0;
}