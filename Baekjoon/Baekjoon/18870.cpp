//��ǥ ����
//https://www.acmicpc.net/problem/18870

/*
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> coord;
vector<int> tmp;
map<int, int> mp;

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		coord.push_back(c);
	}
	tmp = coord;
	sort(tmp.begin(), tmp.end()); // ũ������� ����

	mp[tmp[0]] = 0; // ���� �۱� ������ 0
	for (i = 1; i < n; i++) {
		if (tmp[i - 1] < tmp[i]) {
			mp[tmp[i]] = mp[tmp[i - 1]] + 1; //������ ���ڰ� �۴ٸ� 1 �߰�
		}
		else mp[tmp[i]] = mp[tmp[i - 1]]; // �ƴ϶�� ����
	}

	for (i = 0; i < n; i++) {
		printf("%d ", mp[coord[i]]);
	}
	return 0;
}*/